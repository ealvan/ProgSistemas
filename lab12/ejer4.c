#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
    int pid = fork();
    if(pid > 0){
        printf("En el proceso padre!\n");
    }
    else if(pid == 0){
        sleep(30);
        printf("En el proceso hijo!\n");
    }
    return 0;
}