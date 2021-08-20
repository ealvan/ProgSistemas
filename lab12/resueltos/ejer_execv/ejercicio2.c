//ejercicio2.c
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#include <stdlib.h>
int main (int argc, char *argv[]) {
    int i;
    printf("Ejecutando el programa invocador (ejercicio2). Sus argumentos son:\n");
    for (i = 0; i < argc; i++)
        printf("argv[%d]: %s\n", i, argv[i]);
    sleep(10);
    //strcpy(argv[0], "ejercicio3");
    if (execv ("./ejercicio3", argv) < 0) {
        printf("Error en la invocacion a ejercicio3\n");
        exit(1);
    };
    exit(0);
}