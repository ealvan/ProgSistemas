#include <iostream>

using namespace std;
//clase base
class Vehiculo{
    public:
        Vehiculo(){
            cout << "Este es un Vehiculo" << endl;
        };
};
//Primera Subclase
class Carro: public Vehiculo{
    
};
//Segunda Subclase
class Bus: public Vehiculo{

};
