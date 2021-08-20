#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdbool.h>
#include <errno.h>
using namespace std;
// DEFINICIONES ...
struct Persona{
    char nombre[50];
    char direccion[50];
    char tlf[20];
    char email[40];
    short int dia;
    short int mes;
    short int anio;
};
// max capacidad de la agenada 100;
const short int capacidad = 100;

//Problema 5:
/*
Crear una agenda que maneje los siguientes datos: nombre, dirección, tlf
móvil, email, y día, mes y año de nacimiento (estos tres últimos datos deberán
ser números enteros cortos). Deberá tener capacidad para 100 fichas. Se deberá
poder añadir un dato nuevo, visualizar los nombres de las fichas existentes, o
mostrar todos los datos de una persona (se preguntará al usuario cual es el
nombre de esa persona que quiere visualizar). Al empezar el programa, leerá
los datos de un fichero llamado “agenda.dat” (si existe). Al terminar, guardará
todos los datos en ese fichero.
*/

//declaracion de funciones
void display(Persona p);
//nos dice si un file existe o no
bool exist(char fileName[]);
//escribe datos en file, todos los datos de la agenda
void escribirDatos(string filename, Persona agenda[capacidad]);
//imprime los datos de todos los contactos de la agenda
void printData(Persona agenda[capacidad], int foro);
//lee datos de la agenda, recupera los datos de un archivo
auto leerDatos(string filename, Persona agenda[capacidad]);
//carga todos los datos en un registro de la agenda, que es un puntero
void saveAgenda(Persona &ptr, string nom,string dir, string tlf, string mail,int anio,int mes, int dia);
//pide los datos de la persona
void inputPersona(Persona& person);
//agrega una persona a la agenda e incrementa la cantidad de personas
//en la agenda
void addPersona(Persona&ptr, int& cantActual);
//muestra en consola el menu
void displayMenu();
//busca de acuerdo al nombre en la agenda
void buscarData(string name, Persona agenda[capacidad], int foro);
//recupera losdatos de un file y los carga a una agenda
Persona* retrieve(string filename, Persona agenda[100]);
//escribe o actualiza el nro de contactos de un archivo
void updateForo(string filename,int foro);
//recupera el nro de contactos de un archivo
int retrieveForo(string filename);
//imprime todos los datos de la agenda
void display(Persona* ptr, int foro);
//usa las funciones anteriores
void wrapperAgenda();
