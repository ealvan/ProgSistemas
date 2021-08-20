#include <cstdlib>
#include <iostream>
#include <fstream>

#include <string.h>
#include <stdio.h>
#include <stdlib.h>


using namespace std;
//DEFINIENDO LAS VARIABLES NECESARIAS
string nombre, auxnombre, semestre, edad;
int clave=0, auxclave=0;
char grupo[10];
char opca;
bool encontrado = false;


void altas()
{
    ///Variables de la biblioteca fstream para el manejo de archivos
    ofstream escritura;//esto es para escribir
    ifstream consulta;//esto es para leer

    do{
        //crea y escribe, si ya tiene texto une al final del archivo        
        escritura.open("alumnos.txt", ios::out | ios::app);
        //solamente consulta o lee usando la variable
        //sobre el archivo físico alumnos.txt
        consulta.open("alumnos.txt", ios::in);

        if (escritura.is_open() && consulta.is_open()){
                bool repetido=false; //empezqamos con false

                cout<<"\n";
                cout<<"\tIngresa la clave del alumno:    ";
                cin>>auxclave;
                
                //A continuación se aplica el tipo de
                // lectura de archivos secuencial
                consulta >> clave;//pedimos la clave(primera vez) 
                while (!consulta.eof()){
                    consulta>>nombre>>semestre>>grupo>>edad;
                    if (auxclave==clave){
                        //la clave existe, notificamos al usuario
                        //de este error
                        cout<<"\t\tYa existe la clave del alumno...\n";
                        repetido=true;
                        break;
                    }
                    consulta>>clave;//seguimos leendo la clave
                    //hasta que el if de arriba sea true o
                    //si llega al final del bucle
                    //el "repetido" no se modificara
                }
                //sino entro en el if, nunca se modifico "repetido"
                //asi que en el archivo no la clave no esta repetida
                //significa que es nueva
                if (repetido==false){
                    //pedimos nuesgtros datos
                    cout<<"\tIngresa el nombre del alumno:   ";
                    cin>>nombre;
                    cout<<"\tIngresa el semestre del alumno: ";
                    cin>>semestre;
                    cout<<"\tIngresa el grupo del alumno:    ";
                    cin>>grupo;
                    cout<<"\tIngresa la edad del alumno:     ";
                    cin>>edad;
                    //escribimos todos los datos
                    escritura<<auxclave<<" "<<nombre<<" "<<semestre<<" "<<grupo<<" "<<edad<<endl;
                    //notificamos al usuario
                    cout<<"\n\tRegistro agregado...\n";
                }
                //le preguntamos, 
                //ya sea que la calve este repetida
                //o no lo este
                cout<<"\n\tDeseas ingresar otro alumno? (S/N): ";
                cin>>opca;

        }else{
            //si no se abrio uno o ambos de los dos archivos
            cout<<"El archivo no se pudo abrir \n";
            //esto puede ocurrir sino se han creado aun
        }
        //cerramos los archivos
        escritura.close();
        consulta.close();
    }while (opca=='S' or opca=='s');
    //mientras la opcion es S o s, pedir clave
    //hasta que diga que otra letra que nos sea S o s
}
//sirve para eliminar alumnos
void bajas()
{
    ofstream aux;
    ifstream lectura;

    encontrado=false;

    //nos sirve para el traslado de datos
    aux.open("auxiliar.txt", ios::out);
    //es la base de datos
    lectura.open("alumnos.txt", ios::in);

    if (aux.is_open() && lectura.is_open()){

        cout<<"\n";
        cout<<"\tIngresa la clave del alumno que deseas eliminar: ";
        cin>>auxclave; //pedimos clave
            
            ///De nuevo se aplica el tipo de lectura de archivos secuencial,
            //esto quiere decir que lee campo por campo hasta
            ///hasta llegar al final del archivo gracias a la función .eof()
            lectura>>clave;//obtenemos clave de nuestro usuario
            while (!lectura.eof()){
                lectura>>nombre>>semestre>>grupo>>edad;
                if (auxclave==clave){//si hay una coincidencia
                        encontrado=true;//modificar encontrado
                        //mostrar data
                        cout<<"\n";
                        cout<<"\tClave:    "<<clave<<endl;
                        cout<<"\tNombre:   "<<nombre<<endl;
                        cout<<"\tSemestre: "<<semestre<<endl;
                        cout<<"\tGrupo:    "<<grupo<<endl;
                        cout<<"\tEdad:     "<<edad<<endl;
                        cout<<"\t________________________________\n\n";
                        //pedir opcion de nuevo
                        //para confirmar su decision(talvez se quivoco de clave para eliminar)
                        //y es otra(puede pasar)
                        cout<<"\tRealmente deseas eliminar el registro actual (S/N)? ---> ";
                        cin>>opca;
                        //Si su decision es S o s
                        if (opca=='S' or opca=='s'){
                            //notificarle que asido elminado
                            //un alumno,
                            //en realidad en este instante
                            //"ignoramos este alumno"
                            //y no copiamos los datos de este
                            // alumno en  "auxiliar.txt"
                            //lo que significa borrarlo
                            cout<<"\n\n\t\t\tRegistro eliminado...\n\n\t\t\a";
                        }else{
                            //pero si se arrepiente
                            //ya no ignoramos a este alumno
                            //en la copia "auxiliar.txt"
                            aux<<clave<<" "<<nombre<<" "<<semestre<<" "<<grupo<<" "<<edad<<endl;
                        }
                }else{
                    //mientras esta buscando
                    //la clave a eliminar
                    //pasamos todas los datos de "alumnos.txt"->"auxiliar.txt"
                    aux<<clave<<" "<<nombre<<" "<<semestre<<" "<<grupo<<" "<<edad<<endl;
                }
                lectura>>clave;//seguir pidiendo clave
                //hasta que el if sea verdadero o 
                //llegue alfinal del archivo
            }
    }else{
        //si alguno de estos archivos
        //no se puede abrir 
        //"alumnos.txt" : no se puede leer la data sino se abre
        //"auxiliar.txt": se crearia un archivo nuevo sino existe
        cout<<"\n\tEl archivo no se pudo abrir \n";
    }
    //si no fue enconctrado
    if (encontrado==false){
        //le notificamos luego de buscar en "alumnos.txt"
        cout<<"\n\tNo se encontro ningun registro con la clave: "<<auxclave<<"\n\n\t\t\t";
    }//Si fuera true, no tiene sentido//puesto que le mostraste
    //los datos antes de borrarlos
    
    //cerramos los archivos
    aux.close();
    lectura.close();
    //y aqui removemos la data orignial
    remove ("alumnos.txt");
    //y renombramos auxiliar.txt, alumnos
    //significa que actualizamos nuestros
    //datos
    rename("auxiliar.txt", "alumnos.txt");
}


void consultas()
{
    //Lectura de archivos
    ifstream lectura;
    lectura.open("alumnos.txt", ios::out | ios::in);//CREA, ESCRIBE O LEE
    if (lectura.is_open()){
       //LEYENDO Y MOSTRANDO CADA CAMPO DEL ARCHIVO DE FORMA SECUENCIAL
       lectura>>clave;
       //aqui imprimimos 
       //todos los datos que estan en "alumnos.txt"
       while (!lectura.eof()){
            lectura>>nombre>>semestre>>grupo>>edad;
            cout<<"\n";
            cout<<"\tClave:    "<<clave<<endl;
            cout<<"\tNombre:   "<<nombre<<endl;
            cout<<"\tSemestre: "<<semestre<<endl;
            cout<<"\tGrupo:    "<<grupo<<endl;
            cout<<"\tEdad:     "<<edad<<endl;
            lectura>>clave;
            cout<<"\t________________________________\n";
       }
    }else{
        //notificamos de un error al usuario
        //sino se pudo abrir
        cout<<"El archivo no se pudo abrir \n";
    }
    //esta linea cerramos el archivo
    lectura.close();
}

//consulta sobre un alumno y te muestra
//Sus datos del alumno
void buscar(){

    ifstream lectura;
    lectura.open("alumnos.txt", ios::out | ios::in);
    //en principio no hemos encontrado nada
    encontrado=false;

    if (lectura.is_open()){
        cout<<"\n\tIngresa la clave del alumno que deseas buscar: ";
        cin>>auxclave;//pedimos la clave
        lectura>>clave;//leemos por primera vez el archivo
        while(!lectura.eof()){
            //cargamos los datos subsiguientes en 
            //las variables globales
            //hacemos esto para que la linea
            //"lectura>>clave;" sea la siguiente
            //en ser leida, y asi hasta que encontremos
            //la clave correcta
            lectura>>nombre>>semestre>>grupo>>edad;
            //si encontramos la clave correcta
            if(auxclave==clave){
                //mostramos en pantallas los datos
                //que se cargaron en la linea
                //"lectura>>nombre>>semestre>>grupo>>edad;"
                cout<<"\n";
                cout<<"\tClave:    "<<clave<<endl;
                cout<<"\tNombre:   "<<nombre<<endl;
                cout<<"\tSemestre: "<<semestre<<endl;
                cout<<"\tGrupo:    "<<grupo<<endl;
                cout<<"\tEdad:     "<<edad<<endl;
                cout<<"\t________________________________\n";
                encontrado=true;//lo encontramos
                //cortamos el bucle, pues
                //ya encontramos el alumno
                //ya que no tenemos claves duplicadas
                break;
            }//fin del if mostrar encontrado

            //esta linea lee
            //desde la segunda clave hasta 
            //que encontremos la clave del usuario
            //o termine de leerese el file alumnos.txt
            lectura>>clave;
        }//fin del while
        //si no fue encontrado
        if (encontrado==false){
            //notificamos al usuario
            cout<<"\n\n\tNo hay registros con la clave: "<<auxclave<<"\n\n\t\t\t";
        }
    }else{
        //si no se puede abrir
        //no podemos leer los datos de "alumnos.txt"
        cout<<"\n\tAun no se pudo abrir el archivo...";
    }
    //cerramos el file
    lectura.close();
}
//modificar
//modifica el nombre del usuario
void modificar(){
    //archivo de leer y escribir
    ofstream aux;
    ifstream lectura;
    //inicializamos con false, pues no lo encontramos
    //aun
    encontrado=false;
    //abrirmos
    aux.open("auxiliar.txt", ios::out);
    lectura.open("alumnos.txt", ios::in);
    //si se abrio correctamente
    if (aux.is_open() && lectura.is_open()){
        cout<<"\n";
        //le pedimos la clave de alumno
        //para modificar 
        cout<<"\tIngresa la clave del alumno que deseas modificar: ";
        cin>>auxclave; // pedimos su clave
            //primera clave del file en ser leida
            lectura>>clave;
            //entramos a leer el file
            while (!lectura.eof()){
                //volcamos los datos
                //para que el siguiente 
                //dato en leer sea la siguiente clave
                //"lectura>>clave;"
                lectura>>nombre>>semestre>>grupo>>edad;
                //si encuentramos la clave
                if (auxclave==clave){
                    encontrado=true;//modificamos
                    //mostramos en pantalla
                    cout<<"\n";
                    cout<<"\tClave:    "<<clave<<endl;
                    cout<<"\tNombre:   "<<nombre<<endl;
                    cout<<"\tSemestre: "<<semestre<<endl;
                    cout<<"\tGrupo:    "<<grupo<<endl;
                    cout<<"\tEdad:     "<<edad<<endl;
                    cout<<"\t________________________________\n\n";
                    cout<<"\tIngresa el nuevo nombre del alumno con la clave: "<<auxclave<<"\n\n\t---> ";
                    cin>>auxnombre;//decimos que ingrese el nuevo alumno
                    //volcamos los datos en "auxiliar.txt"
                    aux<<clave<<" "<<auxnombre<<" "<<semestre<<" "<<grupo<<" "<<edad<<endl;
                    //notificamos al usario
                    cout<<"\n\n\t\t\tRegistro modificado...\n\t\t\a";
                }else{
                    //mientras no encontramos la clave
                    //copiamos los datos de "alumnos.txt" -> "auxiliar.txt"
                    aux<<clave<<" "<<nombre<<" "<<semestre<<" "<<grupo<<" "<<edad<<endl;
                }
                //leemos la siguinte clave hasta
                //encontrarla o terminar de leer el file 
                lectura>>clave;
            }
    }else{
        //no se pudo abrir:
        //alumnos.txt : no podemos leer sus datos entonces
        //auxiliar.txt: se crea un nuevo archivo vacio
        cout<<"\n\tEl archivo no se pudo abrir \n";
    }
    //si no encontramos entonces 
    if (encontrado==false){
        //notificamos al usuario
        cout<<"\n\tNo se encontro ningun registro con la clave: "<<auxclave<<"\n\n\t\t\t";
    }
    //cerramos files
    aux.close();
    lectura.close();
    //removemos la antigua data
    remove ("alumnos.txt");
    //y renombramos a la data
    //actualizada alumnos.txt
    //para que otras funciones utilicen sus datos
    //actualizados
    rename("auxiliar.txt", "alumnos.txt");
}

int main(){

    system ("color f0");
    // "F : es blanco brillante"
    // "0 : es negro"
    int opc;//es la opcion que quiere el usuario
    do{
        system("cls");//ejecuta el comando cls en windows
        //para limpiar la pantalla, si esta en linuz
        //no surte efecto

        cout<<"\n\tManejo de archivos en c++\n\n";
        cout<<"\n\t1.-Altas";
        cout<<"\n\t2.-Bajas";
        cout<<"\n\t3.-Consultas";
        cout<<"\n\t4.-Buscar un registro";
        cout<<"\n\t5.-Modificaciones";
        cout<<"\n\t6.-Salir";
        cout<<"\n\n\tElige una opcion:  ";
        cin>>opc;
        switch (opc){
            //los corchetes
            //que engloban el contenido
            //de los cases, son para
            //que cuando se creen nuevos datos
            //en esos bloques de codigo
            //no salten hacia otros cases
            // y sagan de su scope(area de dominio)
            case 1:{
                //Meter nuevos alumnos
                system("cls");
                //metemos datos
                altas();                
                cout<<"\n\t\t";
                system ("pause");
                break;
            }
            case 2:{
                //borrar alumno
                //limpiamos
                system("cls");
                //eliminamos
                bajas();
                cout<<"\n\t\t";
                system ("pause");
                break;
            }
            case 3:{
                //imprimimos todos los datos
                //de nuestros alumnos
                //limpiamos
                system("cls");
                //consultamos
                consultas();
                cout<<"\n\t\t";
                system ("pause");
                break;
                }
            case 4:{
                //limpiamos
                system("cls");
                //buscar un alumno, ´por clave
                buscar();
                cout<<"\n\t\t";
                system ("pause");
                break;
            }
            case 5:{
                //modificar el nombre de algun alumno
                //limpiamos
                system("cls");
                //modifcamos
                modificar();
                cout<<"\n\t\t";
                system ("pause");

                break;
            }
            case 6:{
                //el usuario a elegido salir
                cout<<"\n\n\tHa elegido salir...\n\n\t\t"; system ("pause");
                break;
            }
            default:{
                //si su opcion no fue ninguna de las anteriores
                cout<<"\n\n\tHa elegido una opcion inexistente...\n\n\t\t";
                system ("pause");
                break;
            }
        }//fin switch

    }while (opc!=6);//mientras no sea 6, seguimos en el programa
    //limpiamos
    system("cls");
    return 0;
}