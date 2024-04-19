#include <iostream>
#include <Vector.h>
#include <istream>
#include <Queue.h>

using namespace std;
typedef pair<int,int> point;

Vector<point> getEntrance(const int& k){
    Vector<point> en;
    for (int i =0; i < k; i++){
        string s;
        getline(cin,s);
        istringstream iss(s);
        point p0;
        iss >> p0.first >> p0.second;
        en.add(p0);
    }
    return en;
}

Vector<string> init(const int n){
    Vector<string> maze(n,".");
    for (int i = 0; i < n; i ++){
        getline(cin, maze[i]);
    }
    return maze;
}

char getPoint(point p0, Vector<string>& maze){
    return maze[p0.first][p0.second];
}

void addPoint(point p0, int x, int y, Queue<point>& way, Vector<string>& maze){
    point p1(p0.first+x, p0.second+y);
    if ('W' != getPoint(p1, maze)) {
        way.enqueue(p1);
    }
}

int main() {
    string s;
    getline(cin , s);
    istringstream iss(s);
    int n,m,k;
    iss >> n >> m >> k;
    Vector<point> en = getEntrance(k);
    Vector<string> maze = init(n);
    Vector<string> reachability;
    for (int i = 0; i < en.size(); i++){
        point p0 = en[i];
        int p0i = getPoint(p0, maze)-'a';
        if (p0i == 'W' - 'a'){
            cout << "unreachable" << endl;
            reachability.add("unreachable");
            continue;
        }
        if (p0i >= 0){
            cout << reachability[p0i] << endl;
            continue;
        }
        Queue<point> way;
        way.enqueue(p0);
        while(!way.isEmpty()){
            point p1 = way.dequeue();
            int p1i = getPoint(p1,maze) - 'a';
            if (p1i == i){
                if (way.isEmpty()){
                    cout << "unreachable" << endl;
                    reachability.add("unreachable");
                }
                continue;
            }
            if (p1i >= 0){
                cout << reachability[p1i] << endl;
                reachability.add(reachability[p1i]);
                break;
            }
            maze[p1.first][p1.second] = 'a'+i;
            if (p1 == pair<int,int> (n-1,m-1)){
                cout << "reachable" << endl;
                reachability.add("reachable");
                break;
            }
            if (p1.first > 0){
                addPoint(p1,-1,0,way,maze);
            }
            if (p1.first < n-1){
                addPoint(p1,1,0,way,maze);
            }
            if (p1.second > 0){
                addPoint(p1,0,-1,way,maze);
            }
            if (p1.second < m-1){
                addPoint(p1,0,1,way,maze);
            }
            if (way.isEmpty()){
                cout << "unreachable" << endl;
                reachability.add("unreachable");
            }
        }
    }
    return 0;
}
