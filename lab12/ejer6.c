#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
//mostrar el uso de la llamda fork()
int main(){
    pid_t pid;
    pid = fork();
    switch(pid){
        case -1:
            printf("No he podido crear la app\n");
        case 0:
            printf("Soy el hijo, mi PID es %d, y mi PPID  es %d \n", getpid(), getppid());
        default:
            printf("soy el padre %d, y el pid de mi hijo es %d \n", getpid(), pid);
            sllep(30);
    }
    printf("Final de ejecucion de %d \n", getpid());
    exit(0);
}