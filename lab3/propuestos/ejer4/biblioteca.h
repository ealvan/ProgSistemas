#include <iostream>

class Carriage {
    private:
        bool asientos [40];//40 asientos
        bool primera;//es asiento de primera? SO o NO
    public:
        Carriage(bool prim){
            primera = prim;//si es de primera
            //inicializamos el array en 0(ninguno esta ocupado)
            for(int i = 0; i < 40; i++) 
                asientos[i] = 0;
        } 
        Carriage() {};
        //setters and gettes
        bool getAsientos(int ind) { 
            return asientos[ind]; 
        }
        
        bool getPrimera() { 
            return primera; 
        }
        void setPrimera(bool p) { 
            primera = p; 
        }
        //ocupar asientos de acuerdo a la probabilidad
        void ocupar(){
            //hay numeros del 0 al 1, 
            //si es primera -> 10% de probabilidad ocucpado
            //si no es primera -> 40% de probabilidad ocupado
            double probabilidad;
            if(primera == true){
                probabilidad = 0.1;
            }else{
                probabilidad = 0.4;
            }
            // ahora se dice que tenemos una barra
            // del 0 al 1 
            // si cae dentro de 0 a 0.1/0.4 esta ocupado
            // 0******0.1------vacio--------1
            // 0**************0.4------vacio-------1
            for(int i = 0; i < 40; i++) 
                asientos[i] = double( rand() ) / RAND_MAX < probabilidad;
        }
};

class Train {
    Carriage * carriages;//el vagon
    int numPrimeras;//asientos Primeras
    int numSegundas;//asientos Segundas
    char * inicio;//inicio
    char * destino;//final
    int precioPrimera;//precio ticket
    int precioSegunda;
    public: 
        //el constructor necesita inicializar
        //los argumentos que se les pasen ": para1(arg1),para2(arg2) , ...."
        //de lo contrario te pedira que hagas un constructor default
        Train(char * init, char * destiny,int nP, int nS,  int pP, int pS):
        inicio(init), destino(destiny),
        numPrimeras(nP), numSegundas(nS), 
        precioPrimera(pP),
        precioSegunda(pS) {
            //el nuemro de vagones = vagones de 1ra +vagones de 2da
            carriages = new Carriage[nP + nS];
            //
            for(int i = 0; i < nP + nS; i++){
                bool esPrimera = i < nP;//decimos que 
                //estos vagones son de primera clase
                carriages->setPrimera(esPrimera);
                //los demas seran 0, 
                //lo que significa que son de segunda
            } 
                
        };
    //nos da un vagon de un tren
    Carriage getCarriage(int i) { 
        return carriages[i]; 
    }
    //llenamos cada vagon
    void llenar(){
        for(int i = 0; i < numPrimeras + numSegundas; i++)
            carriages[i].ocupar();
    }
    //Sacar cuanto se recaudo por ticket
    int totalVentas(){
        int total = 0;
        for(int i = 0; i < numPrimeras + numSegundas; i++)
            if (carriages[i].getPrimera()){//si es de primera
                for(int j = 0; j < 40; j++)
                    total += carriages[i].getAsientos(j) * precioPrimera;
            }else {
                //si es de segunda
                for(int j = 0; j < 40; j++)
                    total += carriages[i].getAsientos(j) * precioSegunda;
            }
        return total;
    }
};
