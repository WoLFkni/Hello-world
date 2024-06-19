#include "field.h"
#include <iomanip>
#include <Random.h>
using namespace std;

// Constructor
Field::Field(int sz)
    : size(sz)
{}

// Destructor
Field::~Field()
{
    for (Mole *m : moles)
        delete m;
}

// Get the information of a mole (if any)
Mole* Field::getMole(int row, int col) const
{
    if (!inBound(row, col))
        return nullptr;

    for (Mole *m: moles)
        if (m->getRow() == row && m->getCol() == col)
            return m;

    return nullptr;
}

// Add a mole
bool Field::addMole(int id, int row, int col, bool big)
{
    if (!inBound(row, col))
        return false;

    Mole *m = getMole(row, col);
    if (m != nullptr)
        return false;

    moles.add(new Mole(id, row, col, big));
    return true;
}

// Remove mole
bool Field::removeMole(int row, int col)
{
    for (int i = 0; i < moles.size(); i++) {
        Mole *m = moles[i];
        if (m != nullptr && m->getRow() == row && m->getCol() == col) {
            delete m;
            moles.remove(i);
            return true;
        }
    }

    return false;
}

// Has mole left?
bool Field::hasMole() const
{
    return !moles.isEmpty();
}


// Randomize the field
void Field::randomize()
{
    Field newField(size);

    for (int i = 0; i < moles.size(); i++) {
        Mole *m = moles[i];
        while (true) {
            int nrow = randomInteger(0, size-1);
            int ncol = randomInteger(0, size-1);
            if (newField.addMole(m->getID(), nrow, ncol, m->isBig()))
                break;
        }
    }

    swap(moles, newField.moles);
}


// Randomization with AI
/*void Field::randomize()
{
    for (Mole *m: moles)
        moleMoves(m);
}
*/

// Print the horizontal line
void printHLine(ostream& os, int n)
{
    os << "  ";
    for (int i = 0; i < n; i++)
        os << "+--";
    os << "+" << endl;
}

// Display the field
void Field::display(std::ostream& os)
{
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
            Mole *m = getMole(i, j);
            if (m != nullptr) {
                if (m->isBig())
                    os << "M" << m->getID();
                else
                    os << "m" << m->getID();
            } else
                os << "  ";
        }
        os << '|' << endl;
        printHLine(os, size);
    }
    os << endl;
}

// In bound check
bool Field::inBound(int r, int c) const
{
    return r >= 0 && r < size && c >= 0 && c < size;
}


///////////////////////////// AI ///////////////////////
void Field::moleRandomMoves(Mole *m)
{
    int nrow, ncol;
    do {
        nrow = randomInteger(0, size-1);
        ncol = randomInteger(0, size-1);
        if (getMole(nrow, ncol) == nullptr)
            break;
    } while (true);
    m->setRow(nrow);
    m->setCol(ncol);
}

void Field::moleWanders(Mole *m)
{
    int rx = randomInteger(-1, 1);
    int ry = randomInteger(-1, 1);
    int nrow = m->getRow() + rx;
    int ncol = m->getCol() + ry;

    if (inBound(nrow, ncol) && getMole(nrow, ncol) == nullptr) {
        m->setRow(nrow);
        m->setCol(ncol);
    }
}

void Field::moleEscapes(Mole *m)
{
    Vector<pair<int, int>> coords = {
        make_pair(0, 0),
        make_pair(0, size-1),
        make_pair(size-1, 0),
        make_pair(size-1, size-1)
    };

    for (pair<int, int> p: coords) {
        int nrow = p.first;
        int ncol = p.second;
        if (inBound(nrow, ncol) && getMole(nrow, ncol) == nullptr) {
            m->setRow(nrow);
            m->setCol(ncol);
            return;
        }
    }

    moleWanders(m);
}

void Field::moleMoves(Mole *m)
{
    switch (m->getAI()) {
    case RANDOM:
            moleRandomMoves(m);
            break;

    case WANDERER:
            moleWanders(m);
            break;

    case ESCAPIST:
            moleEscapes(m);
            break;
    }
}

