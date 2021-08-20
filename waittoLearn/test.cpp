#include <iostream>
#include "bible.cpp"
using namespace std;

int main(){
    Atlet t1 = Atlet("Usaimbol",12,"Madagascar", 10.21);
    Atlet t2 = Atlet("Juan",15,"USA", 10.54);

    Atlet comps[] = {t1, t2};
    Race race1 = Race(comps, 120.00);
    return 0;
}