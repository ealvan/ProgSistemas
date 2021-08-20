#include <iostream>
#include <fstream>
#include <regex>
#include <map>
using namespace std;

//declaracion de funciones
string* storeMatches(string str, regex reg, int n);
//nos da el numero de ocurrencias dado una expresion regular
int getSize(string str, regex reg);
//nos otorga todo el contenido de un file.txt
string getAllContenido(string filename);
//nos da la lista de todas las palabras
//en el texto
string* getWords(string filename, int& nroWords);
//nos cuenta el numero de ocurrencias de una palabra
string getPalabrasUnicas(string* words, int len);
//usa las anteriores para obtener los resultados en otro archivo
void filterWords(string fileIN,string fileOUT ,int& nroWords);

/*
Problema 10:
Escriba un programa que haga una lista de todas las palabras encontradas en
un archivo de entrada y escriba esa lista en un archivo de salida, junto con el
número de veces que ha aparecido cada palabra.

*/
