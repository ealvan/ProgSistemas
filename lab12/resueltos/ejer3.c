#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>


int main(){
    if(fork() == 0){
        printf("Preceso HIJO!\n");
    }else{
        printf("Preceso PADRE!\n");
    }
    return 0;
}