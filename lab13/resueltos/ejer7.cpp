#include <iostream>
#include <cstdlib>
#include <pthread.h>
using namespace std;

#define NUM_THREADS 5

void* say_hello(void* args){
    int tid = *((int *) args);
    cout << "Hello World Parametro: "<< tid << endl;
    pthread_exit(NULL);
}

int main(){
    pthread_t tids[NUM_THREADS];
    int indexes[NUM_THREADS];
    int rc;
    int i;

    for(i = 0; i < NUM_THREADS; i++){
        cout << "Main(): parametro i="<<i<<endl;
        indexes[i] = i;
        rc = pthread_create(&tids[i], NULL, say_hello, (void*)&(indexes[i]));
        if(rc){
            cout << "pthread_create error: error_code="<< rc << endl;
            exit(-1);
        }
    }
    pthread_exit(NULL);
}
