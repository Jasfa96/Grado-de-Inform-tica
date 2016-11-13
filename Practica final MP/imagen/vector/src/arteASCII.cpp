/**
 * lee cualquier imagen indicada por el usuario y un fichero con cadenas
 * de caracteres y crea ficheros de imagen transformadas, una por cadena
*/
#include<iostream>
#include<fstream>
#include<cstring>
#include "imagen.h"
#include "lista.h"

using namespace std;


const int MAXLONG = 1000;

void leelinea(char *s){
	do{
		cin.getline(s, MAXLONG);
	} while (s[0]=='\0');
}

int main(int argc, char *argv[]){
    char ficheroGrises[MAXLONG];
    char ficheroImagen[MAXLONG];
    Imagen origen;
    Lista celdas;
		if(argc!=3){
		    cout<<"Has olvidado poner los 2 argumentos necesarios"<< endl;
		    exit(0);
		}

    // Leer la imagen desde fichero
    if (!origen.leerImagen(argv[1])){
		cerr << "Error leyendo imagen " << ficheroImagen << endl;
		return 1;
    }


	// Leer cadenas desde fichero
	if (celdas.leerLista(argv[2])){
		cerr << "Realizar las conversiones " << endl;
		if (origen.listaAArteASCII(celdas)){
			cout << "Exito en la conversion." << endl;
			cout << "Chequee los ficheros asciiX.txt" << endl;
			cout << endl;
		}else{
			cerr << "La conversion no ha sido posible" << endl;
			cerr << endl;
		}
		// liberar memoria listas
	}else{
		cerr << "Error lista de grises " << ficheroGrises << endl;
	}


}
