#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
int main(){
    int p1,p2,p3;

    p1 = fork();

    if(p1 == 0){//hijo
        
        p2 = fork();
        if(p2 == 0){
            sleep(2);
            printf("Nieto!\n");
        }else{
            //es el padre del nieto
            wait(NULL);
            sleep(2);
            printf("Hijo!\n");
        }
    }else{
        //padre
        wait(NULL);//wait() hace que el padre espere a sus hijos
        //para que terminen sus proceso, al final el ejecutara el suyo
        sleep(2);
        printf("Padre!\n");
        
    }
    
}