#include "def.h"

//algoritmo de divide y venceras "merge algorithm"
void merge(int arr[], int l, int m, int r){
	int n1 = m - l + 1;
	int n2 = r - m;

	// incializar los dos array
	int L[n1], R[n2];

	// copiar los datos, en dos arrays
	for (int i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (int j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	// indice inicial para el primer array
	int i = 0;

	// indice inicial para el segundo array
	int j = 0;

	// index inicial para el array union
	int k = l;

	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	// copiar los elementos restantes de L
	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}

	// copiar los elementos restantes de R
	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
}

// l :index izquierdo 
// r : index derecho
void mergeSort(int arr[],int l,int r){
	if(l>=r){
		return;//returns recursively
	}
	int m =l+ (r-l)/2;
	mergeSort(arr,l,m);
	mergeSort(arr,m+1,r);
	merge(arr,l,m,r);
}
//como un numero esta a razon de un numero por line
//debemos saber cuantas lineas hay
int getLines(string filename){
    fstream file;
    file.open(filename, ios::in);
    int lines = 0;
    if(file.is_open()){
        string line;
        while(getline(file, line)){
            lines++;
        }
    }
    return lines;
}

int* getNumeros(string filename, int& index){
    int lines = getLines(filename);
    int* arr = new int[lines];
    fstream file;

    file.open(filename, ios::in);
    if(file.is_open()){   
        string line;
        while(getline(file, line)){
            if(!line.empty()){
                int number = stoi(line);
                *(arr+index) = number;
                index++;
            }
        }
    }
    return arr;   
    
}
int* merge(int* arr1, int* arr2, int len1, int len2){
    int *fusion = new int[len1 + len2 ];

    for(int i = 0; i < len1; i++){
        *(fusion + i ) = *(arr1 + i);
    }
    for(int i = 0; i < len2; i++){
        *(fusion + i + len1 ) = *(arr2 + i);      
    }
    return fusion;
}


void writeNumeros(string filename,  int* data, int len){
    fstream file;
    file.open(filename, ios::out);
    if(file.is_open()){
        for(int i = 1; i < len; i++){
            file << *(data + i)<<endl;
        }
        file.close();
    }

}