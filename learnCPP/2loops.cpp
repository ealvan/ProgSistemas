#include <iostream>
#include <string>

using namespace std;

int main(){
    cout << "saliendo con loops vreak and continue"<<endl;

    int j =0;
    while (j < 12){
        for(int i =0; i < 4; i++){
            if ( (j+i)%2 == 0){
                cout << "PAR " << j <<i<<endl;
                continue;
            }
            if(i == 3){
                cout <<"es 3"<<endl;
                break;
            }
        }
        j++;
    }
    
}