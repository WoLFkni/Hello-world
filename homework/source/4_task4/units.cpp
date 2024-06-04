#include "units.h"
#include "field.h"
#include <cassert>
using namespace std;

/* Unit */

// Constructor
Unit::Unit(bool sd, int row, int col):side(sd),row(row),col(col),vibrant(3),ud(0),lr(0),G_type("@@"),sight(0)
{

}

Unit::Unit(bool sd, int row, int col, string D, int L):side(sd),row(row),col(col),vibrant(L),ud(0),lr(0),G_type("PG"),sight(0)
{
    setDir(D);
}

Unit::Unit(bool sd, int row, int col, int S):side(sd),row(row),col(col),vibrant(0),ud(0),lr(0),G_type("TG"),sight(S)
{

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

int Unit::getVi()const{
    return vibrant;
}

int Unit::getud()const{
    return ud;
}

int Unit::getlr()const{
    return lr;
}

void Unit::oppo(){
    ud = -ud;
    lr = -lr;
}

string Unit::getType()const{
    return G_type;
}

int Unit::getSight() const {
    return sight;
}

// Get the symbol of the unit
string getUnitSymbol(const Unit& u)
{
    bool side = u.getSide();
    if (side){
        return "@@";
    }
    else{
        string G = u.getType();
        if (G == "PG"){
            return "PG";
        }
        else if(G == "TG"){
            return "TG";
        }
    }
    assert (false);
}