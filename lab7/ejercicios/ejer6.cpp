#include <iostream>

using namespace std;
struct Point{
    int x,y;
};
int main(){

    struct Point p1 = {0,1};
    struct Point *p2 = &p1;

    cout << p2->x <<" "<< p2->y<<endl;
    return 0;
}