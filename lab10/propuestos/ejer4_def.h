#include <iostream>
#include <exception>
#include <string>
#include <cmath>
using namespace std;
//clase que hereda de exception
class Error:public exception{
    private:
        int razon;
    public:
        Error(int mot) : exception(), razon(mot) {}
        const char* what() const throw();
};