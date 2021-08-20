#include <iostream>
#include <fstream>

using namespace std;

int main(){
    int n[6] = {1,2,3,4,5,6};
    register int j;
    ofstream sal("demo.dat");
    if(!sal){
        cout << "No se puede abrir el archivo \n";
        return 1;
    }
    sal.write((char*)&n, sizeof (n));

    sal.close();
    for( j = 0; j < 6; j++){
        n[j] = 0;
    }

    ifstream ent("demo.dat");
    ent.read((char*)&n, sizeof(n));

    for(j =0; j < 6; j++){
        cout << n[j] << endl;
    }
    ent.close();

    return 0;
}