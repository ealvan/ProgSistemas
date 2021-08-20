#include "biblioteca.h"
int main(){
    //el obj1 llamara al constructor por defecto
    Alumnos obj1;
    cout << "Alumno id es: " << obj1.id << endl;
    //obj1 llamara a un constructor parametrizado
    Alumnos obj2(21);
    cout << "Alumno id es: " << obj2.id << endl;
    return 0;
}
