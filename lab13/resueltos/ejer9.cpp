#include <iostream>
#include <cstdlib>
#include <pthread.h>
#include <unistd.h>

using namespace std;

#define NUM_THREADS 5
struct thread_data{
    int thread_id;
    char*message;
};

void* say_hello(void* args){
    int i;
    long tid;
    tid = (long) args;
    sleep(1);
    
    cout << "El thread esta durmiendo "<< endl;
    cout << "Thread con id: "<<tid<<"saliendo..."<< endl;
    cout << endl;
    pthread_exit(NULL);
}
//g++ -Wno-write-strings ejer8.cpp -lpthread -o ejer8
int main(){
    pthread_t tids[NUM_THREADS];
    struct thread_data td[NUM_THREADS];
    pthread_attr_t attr;
    int rc;
    int i;
    void * status;

    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

    

    for(i = 0; i < NUM_THREADS; i++){
        cout << "Main(): creando hilo i="<<i<<endl;
        rc = pthread_create(&tids[i], NULL, say_hello, (void*)(intptr_t) i);
        if(rc){
            cout << "pthread_create error: error_code="<< rc << endl;
            exit(-1);
        }
    }

    pthread_attr_destroy(&attr);
    for(i =0; i < NUM_THREADS; i++){
        rc = pthread_join(tids[i], &status);
        if(rc){
            cout << "Error Inhabilitado para join"<< rc<< endl;
            exit(-1);
        }
        cout << "Main id: del thread completado "<<endl;
        cout << "   Saliendo con el estado"<<status<<endl;
        
    }
    cout << "Main programas saliendo "<< endl;
    pthread_exit(NULL);
}
