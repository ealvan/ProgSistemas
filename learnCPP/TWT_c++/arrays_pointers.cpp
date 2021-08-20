#include <iostream>

using namespace std;

int main(){
    //array and pointers
    char arr[] = {'a','b','c','d','e'};

    for(char* pointer = arr; *pointer != arr[4]; pointer++){
        cout << *pointer <<endl;
    }

    int luckyNumbers[] = {1,2,3,4,5,6};
    int size = sizeof(luckyNumbers)/sizeof(luckyNumbers[0]);
    for(int* pointer = &luckyNumbers[0]; pointer != &luckyNumbers[size-1]; pointer++){
        cout << *pointer << endl;
    }
    return 0;
}