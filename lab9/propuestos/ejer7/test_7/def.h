#include <iostream>
#include <fstream>
#include <string>
#include <regex>
using namespace std;

//declaracion de funciones de implementacion 1 y 2
string* storeMatches(string str, regex reg,int n);
int getSize(string str, regex reg);

//implementacion 1 y 2
int countHaches(string word);

//implementacion 2
bool esIntercalable(string word);


void implementacion_1();
void implementacion_2();

/*
Realizar un programa que cuente las haches intercaladas de un texto de varias
líneas que se encuentra en un fichero. Repetir el problema de forma que cuente
sólo las palabras con hache intercalada. En este segundo caso una palabra con
varias haches intercaladas debe ser contada una sola vez.

NOTA: No son hache intercalada las que son comienzo de palabra ni las que
aparecen formando 'ch'.

Primero:
 --> "No son hache intercalada las que son comienzo de palabra"
 --> Una hache intercalada es una que no este en el inicio de una palabra

Segundo:
 --> "No son hache intercalada las que aparecen formando 'ch'  "
 --> Cualquier hache que en la palabra que forme la combinacion "ch", no 
     se cuenta como hache intercalada

Significa:
    chancho : no tiene ninguna hache intercalada, osea 0
             porque tiene la combinacion "ch"
    
    muchachillo: 0 haches intercaladas

    hahahaha: tiene 3 haches intercaladas, y no 4, porque
            la primera hache esta al inicio  de la palabra

    ahachiha : tiene 2 haches intercaladas
             por que la hay una hache con una combinacion "ch" 
    
    Quiere decir:
        "chancho": 
            NO es una palabra con haches intercaladas
            pues no contiene ninguna hache intercalada
        "hahahaha":
            Si es una palabra con haches intercaladas
            pues contiene 3 haches intercaladas
        "ahachiha":
            Si es una palabra con haches intercaladas
            pues contiene 2 haches intercaladas

*/