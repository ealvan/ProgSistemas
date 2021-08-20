//las primeras dos librerias
//nos otorgan la altura y el ancho de la consola
//en linux
#include <sys/ioctl.h> //ioctl() y TIOCGWINSZ
#include <unistd.h> // para STDOUT_FILENO
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/*
Problema 6:
Haga un programa para mostrar un archivo de texto pantalla a pantalla.
Después de completar la pantalla, el programa se para hasta que el usuario
pulse una tecla y entonces muestra la siguiente página.
*/


