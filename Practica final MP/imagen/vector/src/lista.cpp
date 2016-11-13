#include <string>
#include <fstream>
#include <lista.h>
#include <iostream>

using namespace std;
//Practica 6

	Lista::Lista(const Lista &otro){
			copiarDatos(otro);
	}

	Lista::~Lista(){
			liberarEspacio();
	}

void Lista::liberarEspacio(){
	Celda *pCelda=cabecera;
	Celda *pSiguiente;
	while(pCelda!=0){
		pSiguiente=pCelda->siguiente;
		delete pCelda;
		pCelda=pSiguiente;
	}
}

void Lista::copiarDatos(const Lista &otro){
	cabecera=0;
	int tam = otro.longitud();
	for(int i=0;i<tam;i++){
		insertar(otro.getCelda(i));
	}
}

//SOBRECARGA +

const Lista Lista::operator +(const string &dato){
	Celda *pCelda=cabecera;
	while(pCelda->siguiente!=0){
		pCelda=pCelda->siguiente;
	}
	Celda *pNueva=new Celda;
	pNueva->datos=dato;
	pNueva->siguiente=0;
	pCelda->siguiente=pNueva;
	return *this;

}


//SOBRECARGA ASIGNACION =
const Lista &Lista::operator =(const Lista &otro){
	if(this!=&otro){
		liberarEspacio();
		copiarDatos(otro);
	}
		return *this;
	}

//Fin Practica 6
Lista::Lista(){
	cabecera=0;
}

Lista::Lista(string valor){
	cabecera=new Celda;
	cabecera->datos=valor;
	cabecera->siguiente=0;
}


void Lista::destruir(){

	Celda * aux=cabecera;


	if (cabecera->siguiente==0){
		delete cabecera;
		cabecera=0;
	}
	else{

		while(aux->siguiente!=0){
			delete cabecera;
			cabecera=0;
			cabecera=aux->siguiente;
			aux=cabecera;
		}

		delete aux;
		aux=0;
	}
}


void Lista::insertar(string valor){
	Celda* pNueva=new Celda;
	pNueva->datos=valor;
	pNueva->siguiente=0;
	if(cabecera==0){
		cabecera=pNueva;
	}
	else{
		Celda *pCelda=cabecera;
		while(pCelda->siguiente!=0){
			pCelda=pCelda->siguiente;
		}
		pCelda->siguiente=pNueva;
	}

}

string Lista::getCelda(int pos) const{
		Celda * aux=cabecera;
		for(int i=0;i<pos;i++){
			if(aux == 0){
				return "";
		  }
			aux=aux->siguiente;
		}
		return aux->datos;
}

int Lista::longitud() const{
    Celda *pCelda = cabecera ;
    int longitud = 1 ;

    if(cabecera != 0){
        while(pCelda->siguiente != 0){
            pCelda = pCelda->siguiente ;
            longitud++ ;
        }
    }
    return longitud ;
}

/**
 * @brief Construye una lista de celdas enlazadas a partir de la informacion
 * contenida en un fichero.
 * @param nombreFichero ruta del fichero de texto con el contenido de las datoss
 * a insertar en la lista
 * @retval true si ha tenido éxito en la lectura y el formato es el correcto
 * @retval false si se ha producido algún error en la lectura
 *
 * Lee desde disco los elementos almacenados en @a nombreFichero y los guarda
 * en la lista. La función debe asegurarse de que la estructura sigue un patron
 * determinado, y se ha de crear la lista con el numero de elementos que contenga.
 */
bool Lista::leerLista(const char nombrefichero[]){
	ifstream fin;
	fin.open(nombrefichero);
	if(!fin){
		cerr << "No existe el fichero " << nombrefichero << endl;
		return false;
	}else{
		string grises;
		int lineas;
		getline(fin,grises); //la primera linea se ignora
		fin >> lineas; //leo el numero de datos de grises
		getline(fin,grises); //leer salto de linea
		if (!fin){
			cerr << "Fichero mal formado" << endl;
			return false;
		}else {
			int i = 0;
			getline(fin,grises); //leer cadena de caracteres
			while ((i < lineas)&&(fin)){
				if (grises != ""){
					insertar(grises);
					i++;
				}
				getline(fin,grises); //leer cadena de caracteres
			}
		}
		fin.close();

	}
	return true;
}
