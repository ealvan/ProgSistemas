
#include <iostream>

using namespace std;

struct point{
    int x = -1;
    int y = 0;
};

int main(){
    point p;

    cout << "X: "<<p.x<<" Y: "<<p.y<<endl;
    p.y = 12;
    p.x = 11;
    cout << "X: "<<p.x<<" Y: "<<p.y<<endl;

    return 0;
}