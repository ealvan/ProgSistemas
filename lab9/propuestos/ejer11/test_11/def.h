#include <iostream>
#include <fstream>
using namespace std;
#include <iostream>
using namespace std;
//declaracion de funciones
//algoritmo de merge, divide y venceras
void merge(int arr[], int l, int m, int r);
//es el wrapper o envoltorios de merge
//que se llama asi mismo recursivamente
void mergeSort(int arr[],int l,int r);
//nos da el nuemro de lineas de un archivo
//por linea hya un numero
int getLines(string filename);
//nos da un array de los numeros en ese archivo
int* getNumeros(string filename, int& index);
//unimos los arrays de numeros de los dos archivos
//luego retornamos su puntero del array fusionado
int* merge(int* arr1, int* arr2, int len1, int len2);
//escribimos los resultados en un file
void writeNumeros(string filename,  int* data, int len);


/*
Problema 11:

. Se dispone de dos ficheros de texto que contienen una lista de números enteros
cada uno, ordenados de menor a mayor, a razón de un número por línea. Se
pide un programa en C que a partir de estos dos ficheros, genere un tercer 
fichero que contenga todos y cada uno de los datos de los dos ficheros iniciales
y esté también ordenado de menor a mayor. 

NOTAS: Cada fichero de datos inicial puede tener un número arbitrario de
líneas (y por tanto de números). Los números de un fichero inicial no tienen
ninguna relación con los del otro, siendo por tanto, dos listas de números
completamente independientes.

*/