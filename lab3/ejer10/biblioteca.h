#include <iostream>

using namespace std;
// clase base
class Vehiculo{
    public:
        Vehiculo(){
            cout << "Este es un vehiculo" << endl;
        };
};
// clase derivada
class Carro: public Vehiculo{

};
