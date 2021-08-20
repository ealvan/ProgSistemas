#include <iostream>
using namespace std;
int main(){
    int size = 5;
    int arr[size] = {1,2,3,4,5};
    int* ptr = arr;
    cout << arr[2]<<endl;
    cout << *(arr+2)<<endl;
    cout << *(ptr+2) << endl;
}