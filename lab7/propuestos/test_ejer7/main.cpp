#include "impl.cpp"


int main(){
    int month = -1;
    Persona ocho[8];
    getDataGlob(ocho, 8);
    do{
        getRequestMes(&month);
        for(int i =0; i < 8; i++){
            if(ocho[i].bourne.mes == month){
                display(&ocho[i]);
            }
        }
        cout << endl;

    }while(month!=0);
}