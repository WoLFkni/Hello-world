#include <iostream>
#include <cassert>
#include <iomanip>
#include <random.h>
#include "field.h"
#include "mole.h"
using namespace std;


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
