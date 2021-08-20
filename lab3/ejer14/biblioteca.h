#include <iostream>
using namespace std;
//clase base
class Vehiculo
{
	public:
		Vehiculo()
		{
			cout << "Este es un vehiculo" << endl;
		}
};
//clase base
class Faro
{
	public:
		Faro()
		{
			cout << "Faro del vehiculo\n";
		}
};
//primera sub clase
class Carro : public Vehiculo
{

};
//segunda sub clase
class Bus : public Vehiculo, public Faro
{

};
