#include <iostream>
#include <fstream>
using namespace std;

void getVocales(string filename){
    fstream file;
    file.open(filename, ios::in);
    int arr[5] = {0,0,0,0,0};
    int* ptr = arr;
    if(file.is_open()){
        char c;
        while(c != EOF){
            c = file.get();
            switch(c){
                case 'a':
                case 'A':
                    arr[0]++;
                    break;
                case 'e':
                case 'E':
                    arr[1]++;
                    break;
                case 'i':
                case 'I':
                    arr[2]++;
                    break;
                case 'o':
                case 'O':
                    arr[3]++;
                    break;
                case 'u':
                case 'U':
                    arr[4]++;
                    break;
                    
            }
        }
        file.close();
    }else{
        cout << "ERROR\n";
    }
    for(int i =0; i < 5; i++){
        cout << *(arr + i) << endl;
    }
    
}

int main(){
    getVocales("data.txt");

}