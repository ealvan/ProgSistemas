#include <iostream>
#include <stdlib.h>     
#include <ctime>
using namespace std;
class Lugar{
    private:
        const static int TORRES = 7, PISOS=20,DEPARTAMENTOS=6;
        int complejo[TORRES][PISOS][DEPARTAMENTOS];
        int total_habitantes = 0;
        int tt=0,tp=0;
        int tp_i = 0;
    public:
        Lugar(){
            llenar();
        }
        void llenar(){
            for(int i =0; i < TORRES; i++){
                for(int j = 0; j < PISOS; j++){
                    for(int k =0; k < DEPARTAMENTOS; k++){
                        complejo[i][j][k] = rand()%14;
                        total_habitantes += complejo[i][j][k];
                    }
                } 
            }
        }
        void totalHabitantes(){
            cout << "Total de habitantes : "<< total_habitantes  << endl;

        }
        void prom_habitantes_piso(){
            for(int i =0; i < TORRES; i++){
                cout << "TORRE : "<<(i+1)<<endl;
                for(int j = 0; j < PISOS; j++){
                    int prom_piso = 0;
                    for(int k =0; k < DEPARTAMENTOS; k++){
                        prom_piso += complejo[i][j][k];
                    }
                    prom_piso /= 6;
                    cout << "   Piso #"<<(j+1)<<": Tiene el promedio de "<<prom_piso<<" personas"<<endl;
                }
            }
        }
        void prom_habitantes_torre(){
            
            for(int i =0; i < TORRES; i++){
                int prom_torre = 0;
                for(int j = 0; j < PISOS; j++){
                    for(int k =0; k < DEPARTAMENTOS; k++){
                        prom_torre += complejo[i][j][k];
                    }
                }
                prom_torre /= 7;
                cout << "Torre #"<<(i+1)<<": Tiene el promedio de "<<prom_torre<<" personas"<<endl;
            }

        }
};
