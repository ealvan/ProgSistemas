#pragma once
class Tanque {
    double contenido;
    public:
        static const int capacidad = 5000.0;
        Tanque();
        double getContenido() const;
        // no superar la capacidad
        void agregar(double cantidad);
        // no sacar más de lo que hay
        void sacar(double cantidad);
        //sacaMitad
        void sacaMitad();
        
};
