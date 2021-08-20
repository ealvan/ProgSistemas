#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
    int hijo1, hijo2, hijo3;
    hijo1 = fork();

    if(hijo1 == 0){
        sleep(5);
        //es el primer hijo
        printf("Padre: %d \n", getppid());
        printf("Primer hijo creado %d\n", getpid());
        
    }else{ 
        //le devuelve el pid del hijo, al padre
        hijo2 = fork();
        if(hijo2 != 0){
            //es el padre
            hijo3 = fork();
            if(hijo3 == 0){
                sleep(5);
                //soy el tercer hijo
                printf("Padre: %d\n", getppid());
                printf("Tercer hijo creado %d\n", getpid());
                
            }else{
                sleep(5);
                //es el padre, que tiene tres hijos
                printf("Padre con tres hijos, soy %d\n", getpid());
            }
        }else{
            sleep(5);
            //es el  segundo hijo
            printf("Padre: %d\n", getppid());
            printf("Segundo hijo creado %d\n", getpid());
            
        }
    }


    return 0;
}