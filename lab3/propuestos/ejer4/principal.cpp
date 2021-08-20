#include "biblioteca.h"
#include <iostream>
using namespace std;
int main() {
    //tenemos un tren
    //que partira de: Arequipa
    //su destino es : Lima
    //vagones de primera clase: 4
    //vagones de segunda clase: 7
    //el consto de un asiento de primera clase es: 20soles
    //el consto de un asiento de segunda clase es: 10soles
    Train t("Arequipa", "Lima",5, 8,  30, 15);
    t.llenar();
    cout << endl << endl << t.totalVentas() << endl;
}