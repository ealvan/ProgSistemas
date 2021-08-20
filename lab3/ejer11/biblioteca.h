#include <iostream>

using namespace std;

class Vehiculo{
    public:
        Vehiculo(){
            cout << "Este es  un vehiculo" << endl;
        };
};

class CuatroRuedas{
    public:
        CuatroRuedas(){
            cout << "Este es un vehiculo de 4 ruedas" << endl;
        };
};

class Carro : public Vehiculo , public CuatroRuedas{
    //nothing
};