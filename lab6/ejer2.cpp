#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <stdlib.h>     
#include <time.h>    

using namespace std;
bool equivocacion(string secret, char intento);
void displayCuerpo(int n);
void displayIntrucciones();
void pedirIntento(char* intento, int& contador);
bool mostrarCompletado2(string secret, char historial[], int& nroIntentos);
void control();
void transformer(string secret, char intento, char* word );
bool estamosCompletos(char* word, int size); 
void init_word(char* word, string secret); 
void printWord(char* word, int size );
bool yaEstaEnElHistorial(char h[], char intento, int nro_intentos);
string dameRandomWord();
int main(){
    control();
}
void control(){
    const int final_intentos = 7;//el numero de figuras que tenemos
    char historial[final_intentos];//guardara los intentos del participante
    int estadoCuerpo = 0;//guardara en que estado esta el cuerpo
    char currentIntento;//aqui se metera los intentos acutales
    bool estamos = false;
    string secret = dameRandomWord(); 
    int nro_intentos = 0;

    displayIntrucciones();

    char* wordUser = new char[secret.size()];

    //init word
    init_word(wordUser, secret);
    bool primera = true;
    do{
        displayCuerpo(estadoCuerpo);

        pedirIntento( &currentIntento, nro_intentos);

        historial[nro_intentos - 1] = currentIntento;

        cout << "Historial : ";
        for(int i = 0; i < nro_intentos ; i++){
            cout << historial[i]<< " " ;
        }
        cout << endl;
        bool equiv  = equivocacion(secret, currentIntento);
        if(equiv ){
            estadoCuerpo++;
            nro_intentos++;
        }
        transformer(secret, currentIntento, wordUser);
        printWord(wordUser,secret.size());

        estamos = estamosCompletos(wordUser, secret.size());

    }while(!estamos && estadoCuerpo < final_intentos && nro_intentos < final_intentos);
    if(nro_intentos < final_intentos){
        cout << "Usted a ganado el juego felicidades!!"<< endl;
    }else{
        cout << "Usted a Perdido el juego, mejor suerte a la proxima! "<< endl;
        cout << "Nro de intentos : " << nro_intentos << endl;
    }

}
string dameRandomWord(){
    int size = 9; 
    string letras[size] = {
        "agua",
        "pan",
        "gazorfiano",
        "simpson",
        "tomates",
        "lenguaje",
        "canotaje",
        "acetileno",
        "ibuprofeno",
    };
    srand(time(0));
    int random = rand() %(size+1);

    return letras[random];

}
bool estamosCompletos(char* word, int size){
    for(int i =0; i < size; i++ ){
        if(word[i] == '_'){
            return false;
        }
    }
    return true;
}

bool yaEstaEnElHistorial(char h[], char intento, int nro_intentos){
    for(int i = 0; i < nro_intentos; i++){
        if(h[i] == intento){
            return true;
        }
    }
    return false;
}

void init_word(char* word, string secret){
    for(int i = 0; i < secret.size(); i++){
        *(word + i ) = '_';
    }
}


//word tiene el mismo  letras, es identico
//solo que tiene todo con "_" -> _______
void transformer(string secret, char intento, char* word ){
    for(int i = 0; i < secret.size(); i++){
        if(secret[i] == intento){
            *(word+i) = secret[i];
        }
    }
}
void printWord(char* word, int size ){
    for(int i =0; i < size; i++){
        cout << *(word+i) << " ";
    }
    cout << endl;
} 

bool mostrarCompletado2(string secret, char historial[], int& nroIntentos){
    string word = "";
    for(int i =0; i< secret.size(); i++){
        for(int j =0; j < nroIntentos; j++ ){
            if(secret[i] == historial[j]){
                word += secret[i];                    
            }else{
                word += "_";
            }
            word += " ";
        }
    }
    cout << word << endl;

    for(int i = 0; i < word.size(); i++){
        if(word[i] == '_'){
            return false;
        }
    }
    return true;
}


//elegirpalabrasecreta()//aletaroio entre palabras
//.........
void displayIntrucciones(){
    string instrucciones = "Este es el juego del ahorcado, juegalo,\n  con la maquina, ella te dira si tu respuesta es correcta o no";
    cout <<  instrucciones << endl;
    cout << endl;
}
void pedirIntento(char* intento, int& contador){
    cout<< "Advine una letra: ";
    cin >> intento;
    
}
//diplayCuerpo()//display el cuerpo
void displayCuerpo(int n){
    const int size = 7;
    const string figuras[size] = {
        R"(+---+
      |   |
          |
          |
          |
          |
    =========)",
        R"(+---+
      |   |
      O   |
          |
          |
          |
    =========)",
        R"(+---+
      |   |
      O   |
      |   |
          |
          |
    =========)",
        R"(+---+
      |   |
      O   |
     /|   |
          |
          |
    =========)",
        R"(+---+
      |   |
      O   |
     /|\  |
          |
          |
    =========)",
        R"(+---+
      |   |
      O   |
     /|\  |
     /    |
          |
    =========)",
        R"(+---+
      |   |
      O   |
     /|\  |
     / \  |
          |
    =========)",
    };

    //0 : empezamos
    //1: un intento fallido
    //2 : dos intetos fallidso
    //3: tres intentos fallidos
    // ... y asi
    if(n > size || n < 0){
        cout <<"Cuerpo "<< n <<": Parametro de display novalido" << endl;
        return;
    }
    cout << "Cuerpo "<< n <<" : "<< figuras[n] << endl;
}
//mostrarLocompletado()//muestra todo lo que se ha completado hasta el momento
bool equivocacion(string secret, char intento){
    bool estados[secret.size()];
    for(int i = 0 ; i < secret.size(); i++){
        if(secret[i] == intento){
            estados[i] = true;//una letra fue adivinada            
        }else{
            estados[i] = false;//una letra no fue adivinada
        }
    }
    // false false true false
    int count =0;
    for(int i =0; i< secret.size(); i++){
        if(estados[i] == false){
            count++;
        }
    }
    if(count == secret.size()){
        return true;
    }
     return false;
}






