#include "biblioteca.h"
//Definición de Imprimirnombre usando el alcance de operador de resolución
//ouede haber metodos fuera de su clase
void Alumnos::Imprimirnombre()
{
	cout << "Nombre es: " << NombreAlumno;
}
int main() {
	Alumnos obj1;
	obj1.NombreAlumno = "xyz";
	obj1.id = 15;
	//llamando a Imprimirnombre()
	obj1.Imprimirnombre();
	cout << endl;
	//llamando a impirimirid()
	obj1.Imprimirid();
	return 0;
}
