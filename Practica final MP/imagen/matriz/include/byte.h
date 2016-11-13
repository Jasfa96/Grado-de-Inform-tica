
#ifndef _BYTE_H
#define _BYTE_H

typedef unsigned char byte;

void on(byte &b, int pos);

void off(byte& b, int pos);

bool getbyte(byte b, int pos);

void print(byte b);

void encender(byte& b);

void apagar(byte& b);

void asignar(byte& b, const bool v[]);

void volcar(byte b, bool v[]);

void encendidos(byte b, int posic[], int& cuantos);

#endif
