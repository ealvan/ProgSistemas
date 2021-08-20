// ejercicio5.c
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main(int args, char* argv[]) {
   for(int  i =0; i < args; i++){
       printf("argv[%d] = %s \n", i , argv[i]);
   }
   sleep(10);
   srtcpy(argv[0], "codigo08");
   if(execv("./codigo08", argv) < 0){
       printf("Error en la invocacion del ejercicio\n");
       exit(1);
   }
   return 0;
}