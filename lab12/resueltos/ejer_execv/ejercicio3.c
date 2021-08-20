//ejercicio3.c
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main (int argc, char *argv[]) {
    int i;
    printf("Ejecutando el programa invocado (ejercicio3). Sus argumentos son:\n");
    for (i = 0; i < argc; i++)
        printf("argv[%d]: %s\n", i, argv[i]);
    sleep(10);
    exit(0);
}