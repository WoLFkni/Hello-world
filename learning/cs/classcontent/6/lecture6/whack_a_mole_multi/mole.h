#ifndef MOLE_H_INCLUDED
#define MOLE_H_INCLUDED

// Mole
struct Mole {
    bool big;
    // Coordinate of the mole
    int row, col;
};

// Score of the mole
int getScore(const Mole *m);

#endif // MOLE_H_INCLUDED
