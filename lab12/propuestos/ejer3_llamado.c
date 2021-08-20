#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int args, char* argv[]){
    //haciendo la diferencia entre EXECV() y FORK()
    //hacer un fork de este proceso que se llamara desde ejer3.c
    printf("Estamos en el proceso Llamado\n");
    pid_t process = fork();
    if(process == 0){
        //es el hijo
        printf("    Estamos en el HIJO del proceso llamado %d y padre %d\n", getpid(), getppid());
        sleep(3);
    }else{
        printf("    Estamos en el PADRE del proceso llamado %d y mi hijo %d \n", getpid(), process);
        sleep(3);
    }
}