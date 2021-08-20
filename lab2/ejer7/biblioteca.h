//Programa en C++ para demostrar los constructores
#include <bits/stdc++.h>
using namespace std;
class Alumnos
{
	public:
	int id;
	//Constructor por defecto
	Alumnos()
	{
		cout << "Constructor por defecto llamdo" << endl;
		id = -1;
	}
	//Constructor parametrizado
	Alumnos(int x)
	{
		cout << "Constructor parametrizado llamado" << endl;
		id = x;
	}
};
