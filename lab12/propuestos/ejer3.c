#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

int main(int args, char* argv[]){
    //haciendo la diferencia entre EXECV() y FORK()
    //hacer un excev de un programa
    //es hacer que se reemplace el proceso actual, por otro
    //pero no cambia el pid
    printf("Ejecutando Proceso Original...\n");
    for(int i =0; i < 3; i++){
        printf("    estamos en el original\n");
        sleep(2);
    }
    if(execv("./called", argv) < 0){
        printf("Error de invocacion\n");
        return 1;
    }
    return 0;

}