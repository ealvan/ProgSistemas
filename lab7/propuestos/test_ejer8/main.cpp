#include "impl.cpp"

int main(){
    int op;
    int n = 50;
    Persona people[n];
    getDataGlob(people, 50);
    do{
        displayMenu();
        pedirOP(op);
        switch(op){
            //las llaves en los case's
            //son para que las variables 
            //no salten entre caso
            //y caso, de tal forma que se queden en ese bloque
            case 1:
                {
                    cout << "Lista de Nombres: "<<endl;
                    for(int i =0; i< n; i++){
                        if(people[i].nombre == "")
                            break;
                        cout <<"#"<<(i+1)<<" "<<people[i].nombre<<endl;
                    }
                }
                break;
            case 2:
                {
                    int edad;
                    cout << "Ingrese la edad a buscar: ";
                    cin >> edad;
                    cout << "Lista de personas con "<<edad<<" años: "<<endl;
                    for(int i =0; i< n; i++){
                        if(people[i].nombre == "")
                            break;
                        if(people[i].edad == edad){
                            cout <<"#"<<(i+1)<<" ";
                            people[i].display();
                        }
                            
                            
                    }
                }
                break;
            case 3:
                {
                    char init;
                    cout << "Ingrese la inicial a buscar: ";
                    cin >> init;
                    cout << "Lista de personas con inicial "<<init<<" : "<<endl;
                    for(int i =0; i< n; i++){
                        if(people[i].nombre == "")
                            break;
                        if(people[i].nombre[0] == init)
                            people[i].display();
                    }
                }
                break;
            case 4:
                cout << "El programa termino, tenga un buen dia!"<<endl;
                break;
            default:
                cout << "No reconocemos esta opcion..."<<endl;
                break;
        }
        cout << endl;

    }while(op !=4);
}