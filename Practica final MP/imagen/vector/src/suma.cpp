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
using namespace std;

int main(int argc,char *argv[]){
    Imagen img1,img2,img_out;
    // FALTA PODER METER EL TIPO QUE SEA B=BINARIO o T=TEXTO
    if(argc<=4){
		    cout<<"Has olvidado poner los 4 argumentos necesarios"<< endl;
		    exit(0);
		}

    if (!img1.leerImagen(argv[1])){
    cerr << "Error leyendo imagen " << endl;
    return 1;
    }

    if (!img2.leerImagen(argv[2])){
    cerr << "Error leyendo imagen " << endl;
    return 1;
    }

    img_out=img1+img2;


    if(*argv[4]=='B'){
      // Guardar la imagen destino en el fichero degradado.pgm
      if (img_out.escribirImagen(argv[3], true)){
        // si todo va bien
        cout <<  argv[3] <<" Guardado correctamente \n";
      } else { // si error
        cerr << "Error guardando "<< argv[3] <<"\n";
        return 1;
      }
    }
    else if(*argv[4]=='T'){
      if (img_out.escribirImagen(argv[3], false)){
        // si todo va bien
        cout <<  argv[3] <<" Guardado correctamente \n";
      } else { // si error
        cerr << "Error guardando "<< argv[3] <<"\n";
        return 1;
      }
    }
    else
      cout << "No se reconoce el tipo, compruebe que el tipo escrito está en mayúscula.";

  }
