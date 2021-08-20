#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
//hacer un proceso zombie! para el hijo
int main(){
    //fork retorna el id, del proceso 
    //en el proceso padre
    pid_t child_pid = fork();
    if(child_pid >0){
        sleep(30);
    }else{//proceso hijo!
        exit(0);
    }
     return 0;



}