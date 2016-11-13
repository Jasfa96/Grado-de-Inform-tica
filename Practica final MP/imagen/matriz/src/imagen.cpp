#include <imagen.h>
#include <iostream>
#include <pgm.h>
#include <byte.h>
#include <lista.h>
#include <stdio.h>
#include <fstream>
#include <string>
#include <stdio.h>
#include <cstring>
typedef unsigned char byte;
//Practica 6

void Imagen::DestruirMemoria(){
	if(datos!=0){
	delete [] datos[0];
	delete [] datos;
}
	nfilas=0;
	ncolumnas=0;
	datos=0;

}

// LOS CONST NOS PETAN

Imagen::Imagen(const Imagen& orig){
	if(orig.datos==0){
		nfilas=0;
		ncolumnas=0;
		datos=0;
	}

	else{
		crear(orig.filas(),orig.columnas());
		for(int i=0;i<nfilas;i++){
			for(int j=0;j<ncolumnas;j++)
				set(i,j,orig.get(i,j));
		}
	}
}

Imagen::~Imagen(){
	DestruirMemoria();
}

Imagen Imagen::operator +(const Imagen &img1)const{

	Imagen nueva;

	// Si nfilas de this es mas grande que de img1, se crea el objeto con
	// las filas de this.
	if(nfilas>img1.filas())
		nueva.crear(nfilas,ncolumnas+img1.columnas());
	// Se crea el objeto con las filas de img1
	else
		nueva.crear(img1.filas(),ncolumnas+img1.columnas());


	// Asignamos al nuevo objeto los valores de this.
	for(int i=0;i<nfilas;++i){
		for(int j=0;j<ncolumnas;++j)
			nueva.set(i,j,get(i,j));

	}
	// Asignamos a continuacion los valores de img1, todos estos valores iran
	// desde la ultima columna de this (sin contar la ultima columna) hasta el final.
	for(int i=0;i<img1.filas();++i){
		for(int j=0;j<img1.columnas();++j)
			nueva.set(i,j+ncolumnas,img1.get(i,j));
	}
	return nueva;
}

const Imagen& Imagen::operator =(const Imagen &drch){

	// Comprueba que this y drch no son el mismo objeto.
	if(this != &drch){
		// Destruimos la memoria de this para asignar los nuevos valores.
		DestruirMemoria();
		// Creamos la imagen degradada actualizando filas y columnas.
		crear(drch.filas(),drch.columnas());
		// Asignacion de los valores de drch a this.
		for(int i=0;i<nfilas;++i){
			for(int j=0;j<ncolumnas;++j)
				set(i,j,drch.get(i,j));
		}
	}

	return *this;
}

//Fin practica 6

	Imagen::Imagen(){
		nfilas=0;
		ncolumnas=0;
		datos=0;
	}

	Imagen::Imagen(int filas, int columnas){
		crear(filas,columnas);
	}

	void Imagen::crear(int filas,int columnas){
		int dim=filas*columnas;
		if( dim<=0){
			nfilas=0;
			ncolumnas=0;
			datos=0;
		}

		else{
			nfilas=filas;
			ncolumnas=columnas;
			// Reserva de posiciones de memoria para la matriz
			datos=new byte*[filas];
			datos[0]=new byte[filas*columnas];

			// Asignacion de las posiciones a las que apunta cada fila de la matriz
			// La posicion 0 apunta donde empieza todo el contenido de datos de la matriz.
			for(int i=1;i<nfilas;i++)
				datos[i]=datos[0]+i*ncolumnas;

			// Todas las posiciones a 0 (color negro).
			for(int i=0;i<nfilas;i++){
				for(int j=0;j<ncolumnas;j++)
					datos[i][j]=0;
			}

		}
	}

	int Imagen::filas() const{
		return nfilas;
	}

	int Imagen::columnas() const{
		return ncolumnas;
	}

	void Imagen::set(int y, int x, byte v){
		if(y<=nfilas && x<=ncolumnas){
			datos[y][x]=v;
		}
	}

	byte Imagen::get(int y, int x) const {
		return datos[y][x];
	}

	// Asigna a una posicion del vector el dato de tipo byte
	void Imagen::setPos(int i, byte v){
		if(i<nfilas*ncolumnas){
			datos[0][i]=v;
		}
	}

	byte Imagen::getPos(int i){
		if( i <= nfilas*ncolumnas)
			return datos[0][i];
	}


	bool Imagen::leerImagen(const char nombreFichero[]){

		if(infoPGM(nombreFichero, nfilas, ncolumnas)==IMG_PGM_BINARIO){
			crear(nfilas,ncolumnas);
			// Lee la imagen y le asigna todos los datos de la imagen a la matriz datos.
			return leerPGMBinario(nombreFichero, datos[0], nfilas, ncolumnas);
		}

		else{
		crear(nfilas,ncolumnas);
		// Lee la imagen y le asigna todos los datos de la imagen a la matriz datos.
		return leerPGMTexto(nombreFichero, datos[0], nfilas, ncolumnas);
	}
	}

	bool Imagen::escribirImagen( const char nombreFichero[], bool esBinario){

		if(esBinario==true)
			return escribirPGMBinario(nombreFichero, datos[0], nfilas, ncolumnas);
		else
			return escribirPGMTexto(nombreFichero, datos[0], nfilas, ncolumnas);
	}

Imagen Imagen::plano(int k) {

		Imagen nueva(nfilas, ncolumnas);
		byte b,mask;

		for( int i = 0 ; i< nfilas; i++){

			for( int j = 0 ; j< ncolumnas; j++){
				b = get(i,j);
				mask=0;
				if(getbyte(b,k)){

					mask = 128;
				}
				b = mask;
				nueva.set(i,j,b);
			}
		}

		return nueva;
}

bool Imagen::aArteASCII(const char grises[], char arteASCII[], int maxlong)
{
    // pos_orig es la posición en el vector de la imagen original
    // pos_ascii es la posición en el vector de la imagen ascci
    int cardinal, cont = 0, pos_ascii = 0, pos_orig = 0 ;
    // ncolumnas+1 porque hay que añadirle el \n a cada columna.
    // + 1 para el \0
    int tope = nfilas*(ncolumnas+1) + 1;
    bool res = true ;

    // Cuenta el número de cardinales que hay en grises.
    for(cardinal = 0 ; grises[cardinal] != '\0' ; cardinal++) ;

    if(tope > maxlong)
        res = false ;
    else
    {
        while(pos_orig < nfilas*ncolumnas)
        {
            if(cont == ncolumnas)
            {
                arteASCII[pos_ascii] = '\n' ;
                pos_ascii++ ;
                cont = 0 ;
            }
            // el carácter de salida será el que ocupe la posición entera
            // valorDelPixel ∗ cardinal/256 dentro del conjunto de caracteres.
            else
            {
                arteASCII[pos_ascii] = grises[datos[0][pos_orig]*cardinal/256] ;
                cont++ ;
                pos_orig++ ;
                pos_ascii++ ;
            }
        }
        arteASCII[pos_ascii] = '\0' ;
    }

    return res ;
}

bool Imagen::listaAArteASCII(const Lista celdas){
    ofstream fsalida ;
    string nombreFiSalida = "ascii" ;
    string ficheroSalida ;

    char *arteASCII ;
    int tope ;

    tope = filas()*(columnas()+1) + 1 ;
    arteASCII = new char[tope] ;

		int tam = celdas.longitud();

    for(int i = 0 ; i < tam; i++){
        ficheroSalida = nombreFiSalida + to_string(i+1) + ".txt" ;
        fsalida.open(ficheroSalida.c_str()) ;
        fsalida << "\nLa imagen en arte ASCII es:\n";
        if(aArteASCII(celdas.getCelda(i).c_str(), arteASCII, tope)){
            fsalida << arteASCII ;
					}
        else
        {
            cerr << "La conversión no ha sido posible." << endl;
            return 0 ;
        }
        fsalida.close() ;
    }
    return 1 ;
}
