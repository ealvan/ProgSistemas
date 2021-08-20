#include <iostream>

using namespace std;

struct mani{
    int peso;
    int sal;
    string name;
    char activo;
} a, b;

struct chatt{
    int n;
};
struct punto
{
    int x;
    int y;
};
struct circle
{
    struct punto centro;
    double radio;
};

void displayMani(mani man){
    cout << man.activo<<endl;
    cout << man.sal<<endl;
    cout << man.name<<endl;
    
}
void displayPointer(mani *ptr){
    cout << (*ptr).activo<<endl;
    cout << (*ptr).sal<<endl;
    cout << (*ptr).name<<endl;
}
 
int main(){
    struct mani man;
    man.peso = 12;
    man.sal = 2;
    man.name = "Chatt _Dal";
    man.activo = '?';
    displayMani(man);

    struct mani arr[12];
}