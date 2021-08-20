#include <iostream>
#include <cstdlib>
#include <pthread.h>
using namespace std;

#define NUM_THREADS 5
struct thread_data{
    int thread_id;
    char*message;
};

void* say_hello(void* args){
    struct thread_data *my_data;
    my_data = (struct thread_data*)args;

    int tid = *((int *) args);
    cout << "Thread ID: "<< my_data->thread_id << endl;
    cout << "Mensaje: "<< my_data->message << endl;
    cout << endl;
    pthread_exit(NULL);
}
//g++ -Wno-write-strings ejer8.cpp -lpthread -o ejer8
int main(){
    pthread_t tids[NUM_THREADS];
    struct thread_data td[NUM_THREADS];
    int rc;
    int i;

    for(i = 0; i < NUM_THREADS; i++){
        cout << "Main(): creando hilo i="<<i<<endl;
        td[i].thread_id = i;
        td[i].message = "Este es el mensaje";

        rc = pthread_create(&tids[i], NULL, say_hello, (void*)&(td[i]));
        if(rc){
            cout << "pthread_create error: error_code="<< rc << endl;
            exit(-1);
        }
    }
    pthread_exit(NULL);
}
