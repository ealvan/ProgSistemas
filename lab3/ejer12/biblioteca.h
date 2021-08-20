//Programa en C++ para implementar
//La herencia Multinivel
#include <iostream>
using namespace std;
//Clase base
class Vehiculo
{
	public:
		Vehiculo()
		{
			cout << "Esto es un vehiculo" << endl;
		}
};
//Primera subclase derivada de la clase vehiculo
class CuatroRuedas : public Vehiculo
{
	public:
		CuatroRuedas()
		{
			cout << "Objeto con cuatro ruedas son vehiculos" << endl;
		}
};
//Sub clase derivada de la clase base CuatroRuedas
class Carro : public CuatroRuedas {
	public:
		Carro()
		{
			cout << "Carro tiene 4 ruedas" << endl;
		}
};
