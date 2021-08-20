#include "impl.cpp"

int main(){
    srand(time(NULL));
    int n;
    cout << "Ingrese numero de clientes a generar: ";
    cin >> n;
    generate(n);

}
