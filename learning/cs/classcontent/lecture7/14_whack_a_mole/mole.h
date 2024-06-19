#ifndef MOLE_H_INCLUDED
#define MOLE_H_INCLUDED

// Different AI for the mole
enum AI {ESCAPIST, RANDOM, WANDERER};

// Mole
class Mole {
public:

    // Constructor
    Mole(int id, int r, int c, bool bg);
    Mole(int id, int r, int c, bool bg, AI ai);

    // Get the status of the mole
    bool isBig() const;
    int getRow() const;
    int getCol() const;
    void setRow(int r);
    void setCol(int c);
    int getID() const;

    AI  getAI() const;

private:
    //
    int id;
    // True denotes a big mole, false a smaller one
    bool big;
    // Coordinate of the mole
    int row, col;

    // AI
    AI ai;
};


#endif // MOLE_H_INCLUDED
