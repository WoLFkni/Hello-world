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
            int R,C,L,S;
            string G,D;
            iss >> R >> C >> G;
            if (G == "PG"){
                iss >> D >> L;
                if (!iss){
                    return NULL;
                }
                Unit *unit = new Unit(false, R, C, D, L);
                units.add(unit);
                f->setUnit(R,C,unit);
            }
            else if (G == "TG"){
                iss >> S;
                if (!iss){
                    return NULL;
                }
                Unit *unit = new Unit(false, R, C, S);
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

//检查是否可以移动（没越界，没单位，是平地）
bool checkmove(Field& field, Unit* u,int rch,int cch){
    if (field.inBounds(u->getRow()+rch,u->getCol()+cch) && !(field.getUnit(u->getRow()+rch,u->getCol()+cch)) && (field.getTerrain(u->getRow()+rch,u->getCol()+cch) == PLAIN)){
        return true;
    }
    else {
        return false;
    }
}

// 找出目标单位在vector中的位置
int searching (Vector<Unit*>& units, int row, int col){
    for (int i = 0; i < units.size(); i++){
        Unit *u0 = units[i];
        if (u0->getRow() == row && u0->getCol() == col){
            return i;
        }
    }
}

// 火球术
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
    else {
        assert (false);
    }
}

// 检查有没有被龙卷风伤到的单位
bool checkattack(Field& field, Unit* u,int rch,int cch){
    if (!(field.inBounds(u->getRow()+rch,u->getCol()+cch)) || (field.getTerrain(u->getRow()+rch,u->getCol()+cch) != PLAIN) || !field.getUnit(u->getRow()+rch,u->getCol()+cch)){
        return false;
    }
    return true;
}

// 龙卷风施法
int  tornado(Field& field, Unit* u, Vector<Unit*>& units){
    for (int i = -1; i < 2 ; i++){
        for (int j = -1; j < 2; j++){
            if (i == 0 && j == 0){
                continue;
            }
            if (!checkattack(field,u,i,j)){
                continue;
            }
            else{
                int col,row;
                row = u->getRow()+i;
                col = u->getCol()+j;
                while (checkattack(field,field.getUnit(row,col),i,j)){
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

//哥布林攻击
bool attack(Field& field, Unit* u, Vector<Unit*>& units){
    bool flag = false;
    for (int i = -1; i < 2; i++){
        for (int j = -1; j <2; j++){
            if (i+j != 1 && i+j != -1){
                continue;
            }
            if (field.inBounds(u->getRow()+i,u->getCol()+j) && field.getUnit(u->getRow()+i,u->getCol()+j)){
                if (field.getUnit(u->getRow()+i,u->getCol()+j)->getSide()){
                    field.removeUnit(u->getRow()+i,u->getCol()+j);
                    units.remove(searching(units,u->getRow()+i,u->getCol()+j));
                    flag = true;
                }
            }
        }
    }
    return flag;
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
                int vibrant = u->getVi();
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
            else if (u->getType() == "PG"){
                int vibrant = u->getVi();
                if (attack(field,u,units)){
                    u->oppo();
                    i = searching(units,u->getRow(),u->getCol())+1;
                    continue;
                }
                while(vibrant > 0){
                    int row = u->getRow() + u->getud();
                    int col = u->getCol() + u->getlr();
                    if (!field.inBounds(row,col) || field.getTerrain(row,col) != PLAIN || field.getUnit(row,col)){
                        break;
                    }
                    else {
                        field.moveUnit(u->getRow(),u->getCol(),row,col);
                        vibrant--;
                        if (attack(field,u,units)){
                            i = searching(units,row,col);
                            break;
                        }
                    }
                }
                u->oppo();
                i++;
            }
            else {
                int Sight = u->getSight();
                Queue<pair<int, Vector<point>>> choices;
                for (int x = -Sight; x <= Sight; x++){
                    for (int y = -(Sight-abs(x)); y <= Sight-abs(x); y++){
                        if (x==0 && y == 0){
                            continue;
                        }
                        if (field.inBounds(u->getRow()+x,u->getCol()+y) && field.getUnit(u->getRow()+x,u->getCol()+y) && field.getUnit(u->getRow()+x,u->getCol()+y)->getSide()){
                            if (choices.isEmpty()){
                                pair<int, Vector<point>> choice = searchShortestPath(field,u->getRow(),u->getCol(),u->getRow()+x,u->getCol()+y);
                                if (choice.first >= 0){
                                    choices.enqueue(searchShortestPath(field,u->getRow(),u->getCol(),u->getRow()+x,u->getCol()+y));
                                }
                            }else{
                                int len0 = choices.peek().first;
                                pair<int, Vector<point>> choice = searchShortestPath(field,u->getRow(),u->getCol(),u->getRow()+x,u->getCol()+y);
                                int len = choice.first;
                                if (len >= 0 && len < len0){
                                    choices.dequeue();
                                    choices.enqueue(choice);
                                }
                            }
                        }
                    }
                }
                if (!choices.isEmpty()){
                    Vector<point> finalchoice = choices.peek().second;
                    if (finalchoice.size() > 1){
                        point finalpoint = finalchoice[finalchoice.size()-2];
                        field.moveUnit(u->getRow(),u->getCol(),finalpoint.first,finalpoint.second);
                    }
                    attack(field,u,units);
                    i = searching(units,u->getRow(),u->getCol())+1;
                }
                else {
                    i++;
                }
            }
        }


        // Preventing loop in empty program

        numTurns++;
    }
}


