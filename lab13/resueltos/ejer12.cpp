#include <iostream>
#include <thread>
#include <atomic>
//compartir vaiables con threas y atomic
using namespace std;

atomic<int> myatomic;

int counter;
void increment(){
    for(int i =0; i < 1000; i++){
        counter++; 
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
    cout << "Tiempo : "<<
    chrono::duration_cast<chrono::milliseconds>(stop-start).count() << "ms" << endl;
    return 0;
}