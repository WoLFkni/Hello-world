#ifndef FIELD_H_INCLUDED
#define FIELD_H_INCLUDED

#include <grid.h>
#include "mole.h"

struct Field {
    // Size (n x n) of the filed
    int size;
    // Moles in the field
    Grid<Mole*> moles;
};

// Get the information of a mole (if any)
const Mole* getMole(const Field &f, int row, int col);

// Add a mole
void addMole(Field &f, int row, int col, bool big);

// Remove mole
void removeMole(Field &f, int row, int col);

// Has mole left?
bool hasMole(const Field &f);

Field randomField(int size);

// Randomize the field
void randomize(Field &f);

// Release resources
void cleanField(Field &f);

#endif // FIELD_H_INCLUDED
