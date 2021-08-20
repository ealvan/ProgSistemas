#include "def.h"

//mostrar todos los datos de una persona(pregunte al usuario por name)
void display(Persona p){
    cout << "Nombre : "<<p.nombre << endl
    << "Direccion : "<< p.direccion << endl
    << "Telefono : "<<p.tlf << endl
    << "Email : "<< p.email << endl
    << "Fecha de nacimiento : "  
    << p.anio <<" / "<< p.mes 
    << " / "<< p.dia << endl;
}
//si el file existe!
bool exist(char fileName[]) {
    FILE *fp = fopen(fileName, "r");
    if (fp) {
        fclose(fp);
        return true;
    }
    return errno != ENOENT;
}

void escribirDatos(string filename, Persona agenda[capacidad]){
    fstream file;
    file.open(filename, ios::out | ios::binary);
    if(file.is_open()){
        //reinterpret_cast es una manera de "reinterpretar"
        //o castear un dato a formato char*, y eso se escribe en
        //el file en tes caso el objeto agenda
        //escribimos todos los 100 registros seria:
        //capacidad*sizeof(Persona)
        file.write(reinterpret_cast<char*>(agenda), capacidad*sizeof(Persona));
        file.close();
    }else{
        cout << "No puedo a abrir el "<<filename << "file";
    }
}
//imprime los datos
void printData(Persona agenda[capacidad], int foro){
    cout << "Cantidad actual de personas : "<<foro << " personas"<<endl;
    //todas las personas que esten en la agenda
    //no aceptamos registros no llenados 
    //por consola
    for(int i = 0; i < foro; i++){
        display(agenda[i]);
        cout << "------------------"<<endl;
    }
}
//lee datos
auto leerDatos(string filename, Persona agenda[capacidad]){
    fstream file;
    file.open(filename, ios::in | ios::binary);
    if(file.is_open()){
        //aqui recuperamos los datos de la agenda
        file.read(reinterpret_cast<char*>(agenda), capacidad*sizeof(Persona));
        file.close();
    }else{
        cout << "No puedo a abrir el "<<filename << "file";
    }
    //retornamos la agenda
    return agenda;
}

//aqui volcamos los datos hacia la estructura ptr
//esos satos vienen de consola
void saveAgenda(Persona &ptr, string nom,string dir, string tlf, string mail,int anio,int mes, int dia){
    //sprintf carga los datos de los strings
    //hacia los punteros de los char[]
    //como char nombre[]
    sprintf(ptr.nombre,"%s", nom.c_str());
    sprintf(ptr.direccion,"%s",dir.c_str());
    sprintf(ptr.tlf,"%s",tlf.c_str());
    sprintf(ptr.email,"%s",mail.c_str());
    //aqui capturamos el anio, mes y dia
    ptr.anio = anio;
    ptr.mes = mes;
    ptr.dia = dia;
}
//visualizar los nombres de las fichas existentes
void inputPersona(Persona& person){
    cout << "Añadir una nueva persona: "<<endl;
    string name, dir, tlf, email;
    int dia, mes, anio;    
    cin.ignore();//para ignorar las cosas que no fueron procesadas
    //anteriormente
    
    cout << "Nombre : ";
    getline(cin, name);//capturar el nombre
    cout << "Direccion : ";
    getline(cin, dir);//capturar direccion
    cout << "Telefono : ";
    getline(cin, tlf);//capturar el telefono
    cout << "Email : ";
    getline(cin, email);//el email
    //aqui capturamos el anio mes y dia en un solo input
    // <anio> <mes> <dia>
    cout << "Ingrese Fecha de Nacimiento por espacios( Año Mes Dia ) : ";    
    cin >> anio >> mes >> dia;
    //enviamos los datos para cargarlos en la estructura person
    saveAgenda(person, name,dir,tlf,email, anio, mes, dia);
    //ignoramos cosas no procesadas
    cin.ignore();
}

//añadir un dato nuevo
void addPersona(Persona&ptr, int& cantActual){
    if(cantActual >= 100){
        cout << "Tu agenda esta llena, no podemos agregar mas contactos";
        return;
    }
    //se da por entedido que se agregara una persona
    inputPersona(ptr);//pedimos los datos
    ++cantActual;//incrementamos la cantidad de contactos
}
void displayMenu(){
    int size = 4;
    //aqui tenemos el menu de opcions
    string menu[size]= {
        "opcion 1) añadir un dato nuevo",
        "opcion 2) visualizar los nombres de las fichas existentes",
        "opcion 3) mostrar todos los datos de una persona ",
        "opcion 4) Salir",
    };
    //lo imprimimos por medio de punteros
    //que trabajan con direcciones
    for(string* ptr = menu; ptr <= &menu[size-1]; ptr ++){
        cout << *ptr << endl;
    }
    //le decimos ingrese opcion
    cout << "Ingrese opcion: ";
}
//nos busca un determinado contacto o registro
//de la agenda
void buscarData(string name, Persona agenda[capacidad], int foro){
    int flag  = 0;
   //recorremos la agenda 
    for(int i =0; i < foro; i++){
        //si hay alguien con el mismo nombre
        if(agenda[i].nombre == name){
            //imprimimos los datos
            cout << "Datos de las persona buscada : " << endl;
            display(agenda[i]);
            flag = 1;//significa que lo encontramos
            break;
        }
    }
    //si no se modifico el flag
    if(flag == 0){
        //notificamos al usuario que no los encontramos
        cout << "No encontramos el nombre de esa persona en la agenda"<<endl;
    }
}
//recuepra los datos de un archivo -> a la agenda
Persona* retrieve(string filename, Persona agenda[100]){
    fstream file;
    file.open(filename, ios::in | ios::binary);
    
    if(file.is_open()){
        //reinterpreatmos de char* a la agenda
        file.read(reinterpret_cast<char*>(agenda), 100*sizeof(Persona));
        file.close();
    }else{
        cout << "ERROR\n";
    }
    //retornamos
    return agenda;
}
//actuliza la cantidad actual de contactos
void updateForo(string filename,int foro){
    fstream file;
    file.open(filename, ios::out | ios::binary);
    if(file.is_open()){
        //escribimos el numero
        file.write((char*)&foro, sizeof(foro));
    }else{
        cout << "ERROR\n";
    }
}
//recupera el numero actual de foro
int retrieveForo(string filename){
    fstream file;
    int foro;
    file.open(filename, ios::in | ios::binary);
    if(file.is_open()){
        //recuperamos el dato
        file.read((char*)&foro, sizeof(foro));
        file.close();
    }else{
        cout << "ERROR\n";
    }
    //retornamos el valor de foro
    //recuperado del foro
    return foro;
}
//imprime los datos de la agenda
void display(Persona* ptr, int foro){
    cout << "AGENDA : Tienes "<<foro << " contactos en la agenda"<<endl;
    for(int i =0; i < foro; i++ ){
        cout << endl;
        display(*(ptr+i));
    }    
    //linea para diferenciar lo que despues se muestre
    //de los datos que mostramos antes
    cout <<"--------------------------"<<endl;
    
}
//usa lasfuncion anteriores
void wrapperAgenda(){

    int foro = 0;//alcmienzo hay cero personas
    int op;//es opcion del usaurio
    //datos de donde se recupera el foro
    string fileForo = "foro.dat";
    //datos de donde se recupera los contactos 
    //de la agenda
    string filename = "records.dat";
    //esto
    char f[]= "records.dat";
    //incializamos la agenda
    struct Persona agenda[capacidad];
    Persona* ptr;
    do{
        cout << endl;
        //displayMenu()
        displayMenu();
        cin >> op;//pedimos opcion
        switch(op){
            case 1:
            {
                //añadir nuevo en la agenda
                //aqui se aumenta foro en 1
                addPersona(agenda[foro],foro);
                //actualizamos la agenda del archivo
                escribirDatos(filename,agenda);
                //actualizamos el foro
                updateForo(fileForo, foro);
            }
                break;
            case 2:
            {   
                //si no existe
                if(!exist(f)){
                    //notificamos al usuario
                    //de que esta vacia su agenda
                    // y por ende no podemos recueperar los datos
                    cout << endl;
                    cout << "La agenda esta vacia no hay nada que mostrarte"<<endl;
                }else{
                    //recuperamos el foro
                    foro = retrieveForo(fileForo);                
                    //recuperamos la agenda
                    ptr = retrieve(filename, agenda);
                    //mostrar toda la agenda
                    display(ptr,foro);
                }
            }
                break;
            case 3:
            {   
                //mostrar una persona
                string name;
                cout << "Ingrese el nombre de la persona: ";
                cin >> name;//pedimos el nombre
                buscarData(name, agenda, foro);//lo buscamos
            }
                break;
            case 4:
                //notificar al usuario que salio del programa
                cout << "El programa finalizo exitosamente, tenga un buen dia!"<<endl;
                break;
            default:
                //si no existe la opcion en el switch
                //decimos que no es una opcion disponibla al usuario
                cout << "OPcion no disponible, mire el menu porfavor"<<endl;
                break;
        }

    }while(op != 4);//corremos el programa
    //mientras no sea la opcion 4(salir)

}