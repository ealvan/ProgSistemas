/**
* @author rventurar
* Ejercicio 6 mostrar texto pantalla a
* pantalla.
*
*/

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	// numero de filas antes de cambiar
	// a la siguiente pagina
	// numero de filas en la terminal antes 
	// de llenarse por completo.
	int colum = 12;
	// almacenar la fila correspondiente
	string fila;
	ifstream file("texto.txt");
	// inprimimos el archivo hasta el final
	// de este.
	while(!file.eof()) {
		for( int i = 0; i < colum; i++ )
		{
			if(file.eof()) break;
			getline( file, fila );
			cout << fila << endl;
		}
		//Hacemos una pausa.
		// para que el usuario presione algo
		getchar(); 
		// limpiampos la pantalla en sistema linux
		system("clear");
	}
	
	file.close();
	return 0;
}
