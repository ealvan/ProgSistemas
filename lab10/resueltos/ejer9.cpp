#include <iostream>
#include <exception>
using namespace std;
int main()
{
    int *x;
    int y = 100000000;
    try{
        x = new int[y];
        x[0] = 01;
        cout << "Puntero : "<< (void*) x << endl;
        delete[] x;
    }catch(bad_alloc &exp){
        cout << "Insufficent Memory"<< endl;
    }

    try
    {
        int* millionNums = new int [1000000];
        // do something with the million integers
        delete []millionNums;
    }catch(exception& exp)
    {
        int* anotherMillion = new int [1000000];
        // take back up of millionNums and save it to disk
    }
}