#ifndef FIELD_H_INCLUDED
#define FIELD_H_INCLUDED

#include "mole.h"
#include <Vector.h>
#include <ostream>

// The field where moles happily live
class Field {
public:
    // Constructor
    Field(int sz);
    ~Field();

    // Get the information of a mole (if any)
    Mole *getMole(int row, int col) const;

    // Add a mole
    bool addMole(int id, int row, int col, bool big);

    // Remove mole
    bool removeMole(int row, int col);

    // Display the field
    void display(std::ostream& os);

    // has Mole left?
    bool hasMole() const;

    // Randomly place the moles
    void randomize();

    // Check if a coordinate is in bound;
    bool inBound(int r, int c) const;

private:
    // Size (n x n) of the filed
    int size;
    // Moles in the field
    Vector<Mole*> moles;

    // AI
    void moleMoves(Mole *m);
    void moleRandomMoves(Mole *m);
    void moleWanders(Mole *m);
    void moleEscapes(Mole *m);
};

#endif // FIELD_H_INCLUDED
