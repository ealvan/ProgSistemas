#include <iostream>

using namespace std;


struct Point{
    int x,y;
};

int main(){
    struct Point arr[10];
    
    arr[0].x = 10;
    arr[0].y = 12;

    cout << arr[0].x << " "<< arr[0].y << endl;
    

    //si podemos accder, pero no debemos
    //cout << arr[1].x << endl;
    return 0;

}