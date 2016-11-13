
#include <iostream>
#include <cmath>
#include "byte.h"
#include "imagen.h"
#include "pgm.h"

using namespace std;

// Enciende del byte b la posicion pos
void on(byte& b, int pos){
	byte mask;
	if((pos >= 0) && (pos < 8)){
		mask = 0x1 << pos;
		b = b | mask;
	}
}

// Apaga del byte b la posicion pos
void off(byte& b, int pos){

	byte mask;
	if((pos >=0) && (pos < 8 )){
		mask = 0x1 << pos;
		mask = ~mask;
		b = b & mask;

	}
}

// Devuelve estado de la posicion pos de byte b
bool getbyte(byte b, int pos){

	bool estado;
	byte mask;
	mask = 0x1 << pos;
	b = b & mask;
	if(b == mask)
		estado=true;
	else
		estado=false;

	return estado;

}



// Pone a 1 los 8 bits
void encender(byte& b){
	byte mask;
	mask = 0x0 << 7;

	mask = ~mask;


	b = b | mask;

}

// Pone a 0 los 8 bits
void apagar(byte& b){
	byte mask;

	mask = 0x0 << 7;

	b = b & mask;
}

// Asigna a byte b el array booleano
void asignar(byte& b, const bool v[]){

	for(int i=0, pos=7; i < 8; ++i, --pos){

		if(v[pos] == true)
			on(b,i);
		else
			off(b,i);
	}
}

// Guarda en el array los 8 bits de byte b
void volcar(byte b, bool v[]){
	int pos=7;

	for(int i=0; i <= 7; ++i, --pos)
		v[pos]=getbyte(b,i);

}

// Cuenta cuantos bits tienen el valor 1 y los guarda en el array
void encendidos(byte b, int posic[], int& cuantos){

	cuantos=0;
	for(int i=0; i <=7; ++i){

		if(getbyte(b,i)){
			posic[cuantos] = i;
			cuantos++;
		}
	}
}
