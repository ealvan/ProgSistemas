#include <cstddef>
#include <iostream>
#include <string>

using namespace std;

struct Persona{
    string nombre;
    string direccion;
    string tel;
    int edad;
    void display(){
        cout <<
        "Nombre: "<<nombre<<endl<<
        "Direccion: "<< direccion<<endl<<
        "Telefono: "<<tel<<endl<<
        "Edad: "<<edad<<endl;
    }
};
int main() {

    Persona ptr[50];
    bool isInput = true;
    int n = 50;
    int per = 0;
    int size = 4;
    string str[size]={
        "Ingrese el nombre: ",
        "Ingrese Direccion: ",
        "Ingrese Telefono: ",
        "Ingrese Edad: ",
    };
    while(isInput && per < n){
        string data;
        cout << str[0];
        getline(cin, data);
        if(data.empty()){
            isInput = false;
            break;
        }else{
            ptr[per].nombre = data;
            
        }
        cout << str[1];
        getline(cin, ptr[per].direccion);
        cout << str[2];
        getline(cin, ptr[per].tel);
        cout << str[3];
        cin >> ptr[per].edad;
        cin.ignore();          
        per++;
    }
}
/*

string a;

    char mensaje[40];
    cout << "Ingrese nombre: ";
    getline(cin,a);
    for(int i =0; i< a.length(); i++){
        mensaje[i] = a[i];
    }
    if(a == ""){
        cout << "SIOIIIIIII"<<endl;
    }
    cout << "*"<<a<<"*";
    if(strcmp(mensaje,"")==0){
        cout << "Es cadena vacia"<<endl;
    }
    return 0;
string convertToString(char* a, int size){
    int i;
    string s = "";
    for (i = 0; i < size; i++) {
        s = s + a[i];
    }
    return s;
}
*/
//   string something;
//   bool more = true;
//   cout << "Enter something: ";

//   while (more) {
//     getline(cin, something);

//     if (something.empty()) {
//       cout << "Please enter something: ";
//     }
//     else {
//       more = false;
//     }
//   }

//   cout << "You entered '" << something << "'." << endl;
//   return EXIT_SUCCESS;

//   string data;
//   bool notIs = true;
//   string hello;
//   int c = 0;
//   while(notIs){
//       cout << "Persona #"<<(c+1)<<": "<<endl;
//       cout << "Enter your name: ";
//       getline(cin, data);
//       if(data.empty()){
//         cout << "Finish data input!";
//         break;
//       }
//       cout << "Enter my homework: ";
//       getline(cin, hello);
//       cout << "La data es: "<< data <<endl;
//       cout << "The homework is es: "<< hello <<endl;
//       c++;
//   }