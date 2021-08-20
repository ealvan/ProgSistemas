#include <iostream>
#include "lugar.cpp"
#include <string>
#include <stdlib.h>     
#include <ctime>
#include <iomanip>
using namespace std;

int main(){
    srand(time(NULL));
    Lugar lugar;
    // cout << "Total de habitantes : "<< lugar.total_habitantes() << endl;  
    lugar.totalHabitantes();
    lugar.prom_habitantes_piso();
    lugar.prom_habitantes_torre();
    return 0;
}

