#include <iostream>
#include <cassert>
#include <iomanip>
#include <random.h>
#include <grid.h>
using namespace std;

// Mole
struct Mole {
    bool big;
    // Coordinate of the mole
    int row, col;
};

// Score of the mole
int getScore(const Mole *m)
{
    if (m->big)
        return 300;
    else
        return 100;
}

struct Field {
    // Size (n x n) of the filed
    int size;
    // Moles in the field
    Grid<Mole*> moles;
};

// Get the information of a mole (if any)
const Mole* getMole(const Field &f, int row, int col)
{
    return f.moles[row][col];
}

// Add a mole
void addMole(Field &f, int row, int col, bool big)
{
    if (getMole(f, row, col) != nullptr)
        return;

    Mole* m = new Mole;
    m->big = big;
    m->row = row;
    m->col = col;
    f.moles[row][col] = m;
}

// Remove mole
void removeMole(Field &f, int row, int col)
{
    Mole* m = f.moles[row][col];
    if (m != nullptr) {
        delete m;
        f.moles[row][col] = nullptr;
    }
}

// Has mole left?
bool hasMole(const Field &f)
{
    for (Mole *m : f.moles)
        if (m != nullptr)
            return true;
    return false;
}

Field randomField(int size)
{
    Field f;
    f.size = size;
    f.moles.resize(size, size);

    // Every row has one mole
    for (int row = 0; row < size; row++) {
        int col = randomInteger(0, size-1);
        int big = randomBool();
        addMole(f, row, col, big);
    }

    return f;
}

// Randomize the field
void randomize(Field &f)
{
    Grid<Mole*> grd(f.size, f.size);

    for (Mole *m: f.moles) {
        while (true) {
            int nrow = randomInteger(0, f.size-1);
            int ncol = randomInteger(0, f.size-1);
            if (grd[nrow][ncol] == nullptr) {
                grd[nrow][ncol] = m;
                break;
            }
        }
    }

    f.moles = grd;
}

// Release resources
void cleanField(Field &f)
{
    for (Mole *m: f.moles) {
        if (m != nullptr) {
            // cout << "Remove a " << (m->big ? "big" : "small") << " Mole\n";
            delete m;
        }
    }
}

// Print the horizontal line
void printHLine(ostream& os, int n)
{
    os << "  ";
    for (int i = 0; i < n; i++)
        os << "+--";
    os << "+" << endl;
}

// Display the field
void display(const Field &f, std::ostream& os)
{
    int size = f.size;
    // Print the x coordinates
    os << "  ";
    for (int i = 0; i < size; i++)
        os << ' ' << setw(2) << i;
    os << endl;

    printHLine(os, size);
    for (int i = 0; i < size; i++) {
        os << setw(2) << i;
        for (int j = 0; j < size; j++) {
            os << '|';
            // Print the mole
            const Mole* m = getMole(f, i,j);
            if (m != nullptr) {
                if (m->big)
                    os << "M ";
                else
                    os << "m ";
            } else
                os << "  ";
        }
        os << '|' << endl;
        printHLine(os, size);
    }
    os << endl;
}

// Read row and column from the string
bool readRowCol(const string& str, int& row, int& col)
{
    stringstream ss(str);
    ss >> row >> col;
    if (ss)
        return true;
    else
        return false;
}

// Query row and column from input stream
bool queryRowCol(int& row, int& col)
{
    string line;
    if (!getline(cin, line)) {
        cout << "Read line failed!" << endl;
        assert(false);
    }

    if (!readRowCol(line, row, col)) {
        cout << "Incorrect input! "<< endl;
        return false;
    }

    return true;
}

// Play the game
void play(ostream& os, int size)
{
    int score = 0;
    int round = 1;
    Field f = randomField(size);

    os << "Game begins!" << endl;
    while (hasMole(f)) {
        display(f, os);
        os << "Round " << round << "! Your score is " << score << endl;
        os << endl;
        int r, c;
        os << "Enter the coordinate: ";
        if (!queryRowCol(r, c)) break;

        if (!f.moles.inBounds(r, c)) {
            cout << "Coordinate out of bounds!" << endl;
            continue;
        }

        // Check if you have whacked a mole and score
        const Mole* m = getMole(f, r, c);
        if (m != nullptr) {
            bool big = m->big;
            os << "Whacked a " << (big ? "BIG" : "small") << " one!" << endl;
            score += getScore(m);
            // Remove the mole
            removeMole(f, r, c);
        } else {
            os << "Oops! Missed!" << endl;
            score -= 100;
        }

        // Randomize
        randomize(f);
        round++;
    }

    os << "Game ended!\nYou score is " << score << endl;

    cleanField(f);
}

int main()
{
    play(cout, 10);
    return 0;
}
