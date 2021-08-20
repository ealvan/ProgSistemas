
#include <iostream>

using namespace std;

struct persona{
    string nombre;
    string apellido;
    int edad;
    char sexo;
    string tel;
};

int main(){
    struct persona amigos[4];
    for(int i =0; i < 4; i++){
        cin >> amigos[i].nombre;
        cin >> amigos[i].apellido;
        cin >> amigos[i].edad;
        cin >> amigos[i].sexo;
        cin >> amigos[i].tel;
    }
    for(int i =0; i< 4; i++){
        cout << amigos[i].nombre<<endl;
        cout << amigos[i].apellido<<endl;
        cout << amigos[i].edad<<endl;
        cout << amigos[i].sexo<<endl;
        cout << amigos[i].tel<<endl;        
    }
    struct persona friends[]{
        {"ed","da",21,'M',"12332131"},
        {"ed","da",21,'M',"12332131"},
        {"ed","da",21,'M',"12332131"},
    };
}