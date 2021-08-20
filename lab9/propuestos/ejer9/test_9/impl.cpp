#include "def.h"

//noS dice si es una letra o no
bool ISLETRA(char c) {
    if(c == ' ')
        return false;
    if(c == '\t')
        return false;
    if(c == '\n')
        return false;
    if(c == '\v')
        return false;
    if(c == '\f')
        return false;
    
    if( (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (int(c) >=0 | int(c) <= 9) ){
        return true;
    }
    return false;
}

//nos retorna cuantas palabras hay en un archivo
int characters(string filename){
    //abrimos el archivo
    fstream file;
    file.open(filename, ios::in );

    char c;//nos sirve para leer caracter a caracter
    bool is;//nos indica si es letra o no
    string letra;//concatena los caracteres en letras
    int words = 1000;//palabras permitdas
    //nos indica el indice en el array en el que vamos
    int index = 0;
    //es una bandera, para decidir, si ignoramos
    //caracteres o no,(si no son letras ignoramos)
    bool ignore = false;

    //allocamos memoria en un array
    string* ptr = new string[words];
    
    if(file.is_open()){
        //mientras no lleguemos al final del dicumento
        while(c != EOF){
            //leer caracter a caracter
            c = file.get();
            //decidir si ese caracter es letra o no
            //de acuerdo a las expresiones regulares de ecmascript
            //una palabra es todo aquello que no sea 
            // \n \t " " \f entre otros mas
            //es decir que acepta los numeros como una palabra
            //significa que "num002" es una palabra
            //al igual que "00322323" tambien lo es
            is = ISLETRA(c);
            //si es 
            if(is){
                //concatenamos ese caracter
                letra += c;
                //y no debemos ignorarlo
                ignore = false;
            }else{
                //si no es un caracter
                //debemos ver si es el primer no caracter
                //pues aveces hay
                //"hola      amigos"
                //asi que debemos ignorar esos caracteres
                if(!ignore){
                    //si es el primer no caracter
                    //ponemos la palabra en el array
                    *(ptr + index) = letra;
                    //vaciamos la letra, para recolectar mas
                    letra = "";
                    //aumentamos el indice del array
                    index++;
                    //ignoramos la siguiente
                    //asumiendo que el siguiente sera no sera una letra
                    //pero si es una letra, cuando entre en el "if(is)"
                    //cambiaremos eso, para no ignorarlo
                    ignore = true;
                }
            }
        }
    }
    //retornamos el indice
    return index;

}