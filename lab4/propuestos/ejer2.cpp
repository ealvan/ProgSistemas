#include <iostream>
#include <string>

using namespace std;
//declaracion de funciones
int AreaCuadrilateros(double lado_a, double lado_b);
int AreaTriangulos(double lado_a, double lado_b);
void displayMenu();
void calcular(int fig,double *a, double *b);
//displayMenu
//pedir opcion
//de acuerdo opcion
//display area

int main(){

    double a,b;
    int figura;
    displayMenu();
    cin>> figura;
    if(cin.fail()){
        cout << "Esto no es numero"<< endl;
        return 1;
    }
        
    calcular(figura, &a, &b);
    return 0;
}

int AreaTriangulos(double lado_a, double lado_b){
    int  area = (lado_a*lado_b)/2;
    return area;
}
int AreaCuadrilateros(double lado_a, double lado_b){
    int area = lado_a*lado_b;
    return area;
}

void displayMenu(){
    int size = 3;
    string menu[size] = {
        "Cuadrado(1)",
        "Rectangulo(2)",
        "Triangulo(3):",
    };
    for(int i =0; i < size; i++){
        cout << menu[i]<<endl;
    }
    cout << "Que figura quiere analizar : ";
}
void calcular(int fig,double *a, double *b){
    if(*a < 0 || *b  < 0){
        cout << "Ojo el area es negativa"<<endl;
        return;
    }
    int area=-1;
    switch(fig){
        case 1:
            cout << "Introduzca el valor del lado";
            cin >> *a;
            area = AreaCuadrilateros(*a,*a);
            break;
        case 2:
            cout << "Introduzca el valor del lado a: ";
            cin >> *a;
            cout << "Introduzca el valor del lado b: ";
            cin >> *b;
            area = AreaCuadrilateros(*a,*b);
            break;
        case 3:
            cout << "Introduzca la base : ";
            cin >> *a;
            cout << "Introduzca la altura : ";
            cin >> *b;
            area = AreaTriangulos(*a,*b);
            break;
        default:
            cout << "Figura equivocada "<<endl;
            break;
    }
    cout << "El area de la figura es : " << area << "unidades cuadradas" <<endl;
}