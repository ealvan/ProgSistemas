#include <iostream>

using namespace std;

struct point{
    int x, y;
};

int main(){
    struct point p1 = {0,1};
    p1.x = -1;
    cout << "X: "<<p1.x << ", Y: "<<p1.y<< endl;
    return 0;
}