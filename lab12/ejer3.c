/*
un proceso que ya no tiene mas de un rop
*/

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

void forkExample(){
    if(fork() == 0){
        printf("Hola desde el hijo\n");
    }else{
        printf("Hola desde el padre!\n");
    }
}
int main(){
    forkExample();
    return 0;
}