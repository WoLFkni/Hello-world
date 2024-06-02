#include "units.h"
#include "field.h"
#include <cassert>
using namespace std;

/* Unit */

// Constructor
Unit::Unit(bool sd, int row, int col):side(sd),row(row),col(col),vibrant(3),ud(0),lr(0)
{

}

Unit::Unit(bool sd, int row, int col, string D, int L):side(sd),row(row),col(col),vibrant(L),ud(0),lr(0)
{
    setDir(D);
}

// Get the side
bool Unit::getSide() const
{
    return side;
}

// Get and set the row[col] of a unit
int Unit::getRow() const
{
    return row;
}

int Unit::getCol() const
{
    return col;
}

void Unit::setRow(int r)
{
    row = r;
}

void Unit::setCol(int c)
{
    col = c;
}

void Unit::setDir(string direction){
    if (direction == "W"){
        ud = -1;
    }
    else if (direction == "S"){
        ud = 1;
    }
    else if (direction == "A"){
        lr = -1;
    }
    else if (direction == "D"){
        lr = 1;
    }
}

int Unit::getVi(){
    return vibrant;
}

int Unit::getud(){
    return ud;
}

int Unit::getlr(){
    return lr;
}

void Unit::oppo(){
    ud = -ud;
    lr = -lr;
}

// Get the symbol of the unit
string getUnitSymbol(const Unit& u)
{
    bool side = u.getSide();
    if (side){
        return "@@";
    }
    else{
        return "PG";
    }
    assert (false);
}
