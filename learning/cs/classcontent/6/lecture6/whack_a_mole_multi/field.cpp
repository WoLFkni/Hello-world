#include "field.h"

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
