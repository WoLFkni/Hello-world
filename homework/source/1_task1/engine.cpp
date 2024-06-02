#include <sstream>
#include <iomanip>
#include <cassert>
#include <Queue.h>
#include "engine.h"
#include "units.h"
#include "vector.h"
#include "Stack.h"
#include "algorithms.h"
using namespace std;


// Load map and units
Field* loadMap(istream& is, Vector<Unit*>& units)
{
    /*
    string s;
    getline(is,s);
    istringstream iss(s);
    int m0,n0,NT,NM,NG;
    iss >> m0 >> n0 >> NT >> NM >> NG;
    Field *f = new Field(m0,n0);
    for (int i = 0; i < NT; i++){
        getline(is,s);
        istringstream iss(s);
        int R,C;
        string T;
        iss >> R >> C >> T;
        Terrain terrain;
        if (T == "W"){
            terrain = W;
        }else{
            terrain = M;
        }
        f->setTerrain(R,C,terrain);
    }
    for (int i = 0; i < NM; i++){
        getline(is,s);
        istringstream iss(s);
        int R,C;
        iss >> R >> C;
        Unit *unit = new Unit(true, R, C);
        units.add(unit);
        f->setUnit(R,C,unit);
    }
    for (int i = 0; i < NG; i++){
        if (is){
            getline(is,s);
            istringstream iss(s);
            int R,C;
            string PG;
            iss >> R >> C >> PG;
            if (PG != "PG"){
                return NULL;
            }
            Unit *unit = new Unit(false, R, C);
            units.add(unit);
            f->setUnit(R,C,unit);
        }
        else{
            return NULL;
        }
    }
    return f;
}
*/
    string s;
    getline(is,s);
    istringstream iss(s);
    int m0,n0,NT,NM,NG;
    iss >> m0 >> n0 >> NT >> NM >> NG;
    if (!iss){
        return NULL;
    }
    Field *f = new Field(m0,n0);
    for (int i = 0; i < NT; i++){
        getline(is,s);
        istringstream iss(s);
        int R,C;
        string T;
        iss >> R >> C >> T;
        Terrain terrain;
        if (T == "W"){
            terrain = W;
        }else if (T == "M"){
            terrain = M;
        }else{
            return NULL;
        }
        f->setTerrain(R,C,terrain);
    }
    for (int i = 0; i < NM; i++){
        getline(is,s);
        istringstream iss(s);
        int R,C;
        iss >> R >> C;
        Unit *unit = new Unit(true, R, C);
        units.add(unit);
        f->setUnit(R,C,unit);
    }
    for (int i = 0; i < NG; i++){
        if (is){
            getline(is,s);
            istringstream iss(s);
            int R,C;
            string G;
            iss >> R >> C >> G;
            if (G == "PG"){
                if (!iss){
                    return NULL;
                }
                Unit *unit = new Unit(false, R, C);
                units.add(unit);
                f->setUnit(R,C,unit);
            }
            else {
                return NULL;
            }
        }
        else{
            return NULL;
        }
    }
    return f;
}

// Main loop for playing the game
void play(Field& field, istream& is, ostream& os, Vector<Unit*>& units)
{

    int numTurns = 1;
    while (is)
    {
        os << "Turn " << numTurns << " begins:" << endl;
        // Print the new map
        os << field << endl;

        // Check winning
        // Fill in your code here

        // unit moves
        // Fill in your code here

        // Preventing loop in empty program
        string line;
        getline(is,line);

        numTurns++;
    }
}


