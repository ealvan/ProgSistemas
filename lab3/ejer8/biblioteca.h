//progrma en c++ para explicar constructores
#include <bits/stdc++.h>
using namespace std;

class Alumnos{
    public:
        int id;
        //Definicion de destructor
        ~Alumnos(){
            cout << "Destructor llamado id:" << id << endl;
        };
};