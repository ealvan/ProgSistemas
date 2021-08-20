#include <iostream>

using namespace std;
struct Point{
    int x,y;
};
int main(){

    struct Point curva[7];
    for(int i =0; i< 7; i++){
        cout << "Ingrese las coordenadas x,y de la curva en el punto "<<i-3<<": "<<endl;
        cin >> curva[i].x,curva[i].y;        
    }
    cout << "Las coordenadas son : "<<endl;;
    for(int i =0; i< 7; i++){
        cout << "( "<<curva[i].x<<", "<<curva[i].y <<endl;     
    }
    return 0;
}  