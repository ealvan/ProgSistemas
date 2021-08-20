#pragma once// esto hace que tenga un codigo de prteccion
// a lahora de sobreescribir los metodos de las clases

//es aqui donde se define la clase persona
class Persona{
    //el nombre es privado
    private:
        char nombre[20];
    public:
    //todos estos metodos nos sirven
    //para poner la sigantura del metodo
    //estos se implementaran en un archivo
    //metodos.cpp
        void dormir();
        void hablar();
        void contar();
        void adquirirNombre();
        void decirNombre();
};
