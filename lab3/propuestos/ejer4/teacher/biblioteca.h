#include <iostream>

using std::cout;
using std::endl;

class Carriage{
    bool asientos[];
    bool primera;
    public:
        Carriage(){

        };

        Carriage(bool prim);
        bool getAsiento(int ind){return asientos[ind];}
        bool getPrimera(){return primera}
        bool setPrimera(bool p){ primera = p;}
        void ocupar();
}

Carriage::Carriage(bool prim){

}
void Carriage::ocupar( ){

}

class Train{
};