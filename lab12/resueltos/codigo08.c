// ejercicio5.c
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main(int args, char* argv[]) {
    int i;
    char a[2000];
    printf("Se esta ejecutando el prgrama codigo08.c");
    for(i =0; i < args; i++){
        printf("argv[%d] = %s", i, argv[i]);
    }
    sleep(10);
   return 0;
}