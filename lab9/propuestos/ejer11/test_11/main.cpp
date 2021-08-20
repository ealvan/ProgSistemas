#include "impl.cpp"

int main(){
    int len1 = 0;
    //obtenemos los nuemros
    int* a1 = getNumeros("nums1.txt", len1);
    
    int len2 = 0;
    //obtenemos los nuemros
    int* a2 = getNumeros("nums2.txt", len2);
    int init = 0;
    int len = len1 + len2;
    //los fusionamos en un solo array
    int *fusion = merge(a1, a2, len1, len2);
    //lo ordenamos
    mergeSort(fusion, init, len );
    //y los escribimos
    writeNumeros("output.txt", fusion, len);

}