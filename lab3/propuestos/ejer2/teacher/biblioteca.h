#include <bits/stdc++.h>

class Tanque{
    private:
        double contenido;
    public:
        static const int capacidad=5000;
        Tanque();
        double getContenido() const;
        void agregar(double cantidad);
        void sacar(double cantidad);
        void sacaMitad(void);
        
}