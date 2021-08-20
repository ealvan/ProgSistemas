#include <iostream>
#include <thread>
using namespace std;

#define NUM_THREADS 1

void* say_hello(void* args){
    cout << "Hello World" << endl;
    return NULL;
}

int main(){
    pthread_t tids[NUM_THREADS];
    for(int i = 0; i < NUM_THREADS; i++){
        int ret = pthread_create(&tids[i],NULL,say_hello, NULL);
        if(ret != 0){
            cout << "pthread_create error: error_code="<< ret << endl;
        }
    }
    pthread_exit(NULL);
}
