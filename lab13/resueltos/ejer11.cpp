#include <iostream>
#include <cstdlib>
#include <pthread.h>
#include <thread>
#include <mutex>
#include <unistd.h>
//compartir vaiables con threas y mutex
using namespace std;
mutex mymutex;
int counter;
void increment(){
    for(int i =0; i < 1000; i++){
        mymutex.lock();
        counter++;
        mymutex.unlock();
    }
}


int main(){
    auto start = chrono::high_resolution_clock::now();
    for(int i =0; i < 1000; i++){
        counter = 0;
        thread t1 = thread(increment);
        thread t2 = thread(increment);
        t1.join();
        t2.join();
        if(counter != 2000){
            cout << i << ": "<< counter << endl;
        }
    }
    auto stop = chrono::high_resolution_clock::now();
    return 0;
}