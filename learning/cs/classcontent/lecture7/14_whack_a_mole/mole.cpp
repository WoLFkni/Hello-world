#include "mole.h"

// Constructor
Mole::Mole(int id, int r, int c, bool bg)
    : id(id), big(bg), row(r), col(c), ai(RANDOM)
{}

Mole::Mole(int id, int r, int c, bool bg, AI i)
    : id(id), big(bg), row(r), col(c), ai(i)
{}

// Get the status of the mole
bool Mole::isBig() const
{
    return big;
}

int Mole::getRow() const
{
    return row;
}

int Mole::getCol() const
{
    return col;
}

void Mole::setRow(int r)
{
    row = r;
}

void Mole::setCol(int c)
{
    col = c;
}

AI Mole::getAI() const
{
    return ai;
}

int Mole::getID() const
{
    return id;
}
