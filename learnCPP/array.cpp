#include <iostream>
#include <string>

using namespace std;

int main(){
    int ages[] = {1, 2 ,3 , 4 , 5};
    string chains[] = {"hola","jajjaa","lola","lalolanda"};

    int random[12];
    cout << "random array : " << random[0] <<endl;
    cout << "random array : " << random[11] <<endl;
    
    cout << ages<<endl;
    cout << "Size of chains array: " << (sizeof(chains)/sizeof(chains[3])) << endl;
    cout << "Size of ages array: " << (sizeof(ages)/sizeof(ages[2])) << endl;
    
}