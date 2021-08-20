/*
Crear una jerarquía de clases de excepciones que permitan controlar los
posibles errores que surjan de una manera controlada, clara y elegante. Para
ello, crear una clase padre/base ComputerException que tendrá solamente un
campo de tipo string mesage y que todas las demás clases de excepciones
heredarán de ella. Ahora, crear las clases InputException, ProcessorException
y OutputException que manejarán los respectivos errores a esos dispositivos.
Por ejemplo, si se tiene un tipo Keyboard que es un fichero del que se van a
leer las entradas, KeyboardException manejará los posibles problemas que
pudieran aparecer a la hora de abrir el fichero, leerlo, etc.
*/
#include <iostream>
#include <string>
#include <exception>
using namespace std;
class ComputerException{
    protected:
        string message = "";    
    public:
        ComputerException(string m){
            message = m; 
        }
        const char* what() const throw(){
            return message.c_str();
        }

};
class ProcessorException: public ComputerException{
    private:
        int motivo;
    public:
        ProcessorException(int ide): ComputerException(""){
            motivo = ide;
        }
        const char* what()const  throw(){
            switch (motivo){            
                case 1:
                    return "ERROR Procesor: Operacion no permitida!!";
                case 2:
                    return "ERROR Procesor: Direccion no permitida!!";
                default:
                    return "ERROR Procesor: Inesperado Error en el Procesador!!";
            }
        }
};
class InputException: public ComputerException{
    private:
        int motivo;
    public:
        InputException(int mot): ComputerException(""){
            motivo = mot;
        }
        const char* what()const  throw(){
            switch (motivo){            
                case 1:
                    return "ERROR Input: No admitimos Letras Extrañas!!";
                case 2:
                    return "ERROR Input: No ingreso ningun dato!!";
                default:
                    return "ERROR Input: Inesperado error en el buffer!! ";
            }
        }
};
int main(){
    cout << "Excepciones ..."<<endl;
    for(int i =0; i < 5; i++){
        try{
            //throw ComputerException("Exception A");
            
                if(i == 1) throw ProcessorException(1);
                if(i == 3) throw InputException(2);
                if(i == 4) throw ComputerException("Exception de la Computadora\n");
            
        }
        catch(InputException& e ){
            cout << "Exception : "<<e.what()<<endl;
        }
        catch(ProcessorException& e ){
            cout << "Exception : "<<e.what()<<endl;
        }
        catch(ComputerException& e ){
            cout << "Exception : "<<e.what()<<endl;
        }
    }

}
