//Existen dos formas definir la función de la clase niembro
//Dentro de la definición de la clase
//Fuera de la definición de la clase
//Programa de C++ para demostrar la declaración
//de la función fuera de la clase
#include <bits/stdc++.h>
using namespace std;
class Alumnos
{
	public:
	string NombreAlumno;
	int id;
	//Imprimirnombre no esta definida dentro de la definicion de la clase
	void Imprimirnombre();
	//Imprimirid esta definida dentro de la definicion de la clase
	void Imprimirid()
	{
		cout << "Alumno id es: " << id;
	}
};
