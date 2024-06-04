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

//����Ƿ�����ƶ���ûԽ�磬û��λ����ƽ�أ�
bool checkmove(Field& field, Unit* u,int rch,int cch){
    if (field.inBounds(u->getRow()+rch,u->getCol()+cch) && !(field.getUnit(u->getRow()+rch,u->getCol()+cch)) && (field.getTerrain(u->getRow()+rch,u->getCol()+cch) == PLAIN)){
        return true;
    }
    else {
        return false;
    }
}

// �ҳ�Ŀ�굥λ��vector�е�λ��
int searching (Vector<Unit*>& units, int row, int col){
    for (int i = 0; i < units.size(); i++){
        Unit *u0 = units[i];
        if (u0->getRow() == row && u0->getCol() == col){
            return i;
        }
    }
}

// ������
int fire (Field& field, Unit* u, string direction, Vector<Unit*>& units){

    if (direction == "W"){
        int col = u->getCol();
        for (int row = u->getRow()-1; row >= 0; row--){
            if (field.getTerrain(row,col) == M){
                return units.size();
            }
            else if (field.getUnit(row,col)){
                int i =  searching(units,row,col);
                units.remove(i);
                field.removeUnit(row,col);
                return i;
            }
        }
        return units.size();
    }
    else if (direction == "S"){
        int col = u->getCol();
        for (int row = u->getRow()+1; row < field.getHeight() ; row++){
            if (field.getTerrain(row,col) == M){
                return units.size();
            }
            else if (field.getUnit(row,col)){
                int i =  searching(units,row,col);
                units.remove(i);
                field.removeUnit(row,col);
                return i;
            }
        }
        return units.size();
    }
    else if (direction == "A"){
        int row = u->getRow();
        for (int col = u->getCol()-1; col >= 0; col--){
            if (field.getTerrain(row,col) == M){
                return units.size();
            }
            else if (field.getUnit(row,col)){
                int i =  searching(units,row,col);
                units.remove(i);
                field.removeUnit(row,col);
                return i;
            }
        }
        return units.size();
    }
    else if (direction == "D"){
        int row = u->getRow();
        for (int col = u->getCol()+1; col < field.getWidth() ; col++){
            if (field.getTerrain(row,col) == M){
                return units.size();
            }
            else if (field.getUnit(row,col)){
                int i =  searching(units,row,col);
                units.remove(i);
                field.removeUnit(row,col);
                return i;
            }
        }
        return units.size();
    }
    else{
        assert (false);
    }
}

// �����û�б��������˵��ĵ�λ
bool checkattack(Field& field, Unit* u,int rch,int cch, Vector<Unit*>& units){
    if (!(field.inBounds(u->getRow()+rch,u->getCol()+cch)) || (field.getTerrain(u->getRow()+rch,u->getCol()+cch) != PLAIN) || !field.getUnit(u->getRow()+rch,u->getCol()+cch)){
        return false;
    }
    return true;
}

// ������ʩ��
int  tornado(Field& field, Unit* u, Vector<Unit*>& units){
    for (int i = -1; i < 2 ; i++){
        for (int j = -1; j < 2; j++){
            if (i == 0 && j == 0){
                continue;
            }
            if (!checkattack(field,u,i,j,units)){
                continue;
            }
            else{
                int col,row;
                row = u->getRow()+i;
                col = u->getCol()+j;
                while (checkattack(field,field.getUnit(row,col),i,j,units)){
                    row += i;
                    col += j;
                }
                if (!field.inBounds(row+i,col+j)){
                    continue;
                }
                else if (field.getTerrain(row+i,col+j) == M){
                    continue;
                }
                else if (field.getTerrain(row+i,col+j) == W){
                    field.removeUnit(row,col);
                    units.remove(searching(units, row,col));
                    row -= i;
                    col -= j;
                    while (col != u->getCol() || row != u->getRow()){
                        field.moveUnit(row,col,row+i,col+j);
                        row -= i;
                        col -= j;
                    }
                }
                else {
                    while (col != u->getCol() || row != u->getRow()){
                        field.moveUnit(row,col,row+i,col+j);
                        row -= i;
                        col -= j;
                    }
                }
            }
        }
    }
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
        if (units.size() > 0){
            if (units[units.size()-1]->getSide()){
                os << "You Win!" << endl;
                return;
            }
            else if (! (units[0]->getSide())){
                os << "You Lose!" << endl;
                return;
            }
        }

        // unit moves
        int i = 0;
        while (i < units.size()){
            Unit *u = units[i];
            if (u->getSide()){
                os << "Please move the unit at (" << u->getRow() << "," << u->getCol() << ")" << endl;
                string commands;
                getline(is,commands);
                istringstream iss(commands);
                int vibrant = 3;
                while (iss){
                    string direction;
                    iss >> direction;
                    if (vibrant >0 && direction == "W" && checkmove(field,u,-1,0)){
                        if (field.moveUnit(u->getRow(),u->getCol(),u->getRow()-1,u->getCol())){
                            vibrant--;
                        }
                    }
                    else if (vibrant >0 && direction == "S" && checkmove(field,u,1,0)){
                        if (field.moveUnit(u->getRow(),u->getCol(),u->getRow()+1,u->getCol())){
                            vibrant--;
                        }
                    }
                    else if (vibrant >0 && direction == "A" && checkmove(field,u,0,-1)){
                        if (field.moveUnit(u->getRow(),u->getCol(),u->getRow(),u->getCol()-1)){
                            vibrant--;
                        }
                    }
                    else if (vibrant >0 && direction == "D" && checkmove(field,u,0,1)){
                        if (field.moveUnit(u->getRow(),u->getCol(),u->getRow(),u->getCol()+1)){
                            vibrant--;
                        }
                    }
                    else if (direction == "X"){
                        string dirTrue;
                        iss >> dirTrue;
                        if (iss){
                            int removing = fire(field,u,dirTrue,units);
                            if (removing < i){
                                i--;
                            }
                            break;
                        }
                    }
                    else if (direction == "Y"){
                        tornado(field,u,units);
                        i = searching(units,u->getRow(),u->getCol());
                        break;
                    }
                }
                i++;
                os << field << endl;
            }
            else{
                break;
            }
        }


        // Preventing loop in empty program

        numTurns++;
    }
}

