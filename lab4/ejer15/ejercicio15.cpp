#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void print(char set,string prefix, int n, int k){

    if(k==0) return;

    for(int i =0; i < n; i++){
        string newPrefix;
        newPrefix = prefix = set(i);

        print(set, newPrefix, n,k-1);
    }

}
void printPack(char set,string prefix, int n, int k){
    print(set,"",n,k);
}    

int main(){
    cout << "Primera prueba!" <<endl;

    char set() = "ab";
    int k = 3;
    printPack()
    
}