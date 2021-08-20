#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main(){
    // cout << setw(10)<< 123 << endl;
    // cout << 3.141521 << endl;
    // cout << setprecision(3) << 3.145521 << endl;
    cout << setfill('.');
    cout << setw(10) << "Carzola" << setw(10) << "Linares" << setw(10) << "Baeza"<< setw(11)<<"Carchelejo"<< "\n";
    cout << setw(10) << 1 << setw(10) << 2 << setw(10) << 3 << setw(10) << 3 << endl;
    cout << setw(10) << 2 << setw(10) << 3 << setw(10) << 5 << setw(10) << 3 << endl;
    cout << setw(10) << 6 << setw(10) << 4 << setw(10) << 1 << setw(10) << 3 << endl;
    // int i = 100;
    // cout << hex << i<< endl;
    // cout << dec << i<< endl;
    // cout << oct << i<< endl;
    // double h,b;
    // cout << "Ingrese la altura y la base del triangulo: ";
    // cin >> h >> b;
    // double area = (b*h/2);
    // cout<< "El area de nuestro triangulos es : "<< setprecision(4)<<area <<" unidades" << endl;

    char name[40];
    cout <<"Introduzca su fullname: ";
    cin.getline(name, 40);
    cout << "Hola "<<name<<endl;

    return 0;
}