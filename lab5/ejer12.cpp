/*
Cree un programa que muestre
que este prohibido asignar cualquier direccion
a una variable arreglo, mostrando un error al
compilarlo
*/

int main(){
    int arr[] = {10, 20}, x = 10;
    int *ptr = &x;
    //esta es la forma
    // arr = &x; // esto esta mal
    return 0;
}