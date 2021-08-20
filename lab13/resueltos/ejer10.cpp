#include <iostream>
#include <cstdlib>
#include <pthread.h>
#include <thread>

#include <unistd.h>
//programacion multihilo con 3 hilos , tres funciones diferentes
using namespace std;

#define NUM_THREADS 3
struct thread_data{
    int thread_id;
    char*message;
};
void* foo(int Z){
    for(int i =0; i < Z; i++){
        cout << "Z: Hilo usando funcion puntero como objeto invocable\n"<<endl;
    }
    return NULL;
}

class thread_obj{
    public:
        void operator()(int x){
            for(int i =0; i < x; i++){
                cout << "X : Hilo usando funcion puntero como objeto invocable\n"<<endl;
            }
        }
};
int main(){
    cout << "Hilos 1, 2 y 3"<< endl;
    cout << "Operando independientemente"<<endl;
    //este hilo es la funcion puntero como invocable
    thread th1(foo, 3);
    thread th2(thread_obj(), 3);
    auto f = [](int x){
        for(int i =0; i < x; i++){
            cout << "Funcion lambda expresion invocable"<< endl;
        }
    };
    thread th3(f,3);
    th1.join();
    th2.join();
    th3.join();
    return 0;
}   