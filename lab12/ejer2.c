//numero de veces, 
//que saldra la palabra hola
//en el caso que pongamos 
//tres llamadas al sistema fork()

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
    fork();
    fork();
    fork();
    printf("hola\n");
    return 0;
}

