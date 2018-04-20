#include "belkan.h"
#include "conexion.h"
#include "environment.h"
#include <iostream>
#include <cstdlib>
#include <vector>
#include <utility>
#include <cstring>

using namespace std;



// -----------------------------------------------------------
void PasarVectoraMapaCaracteres(int fila, int columna, char m[200][200], char *v, int brujula){
  m[fila][columna]=v[0];

    switch(brujula){
        case 0: // Orientacion Norte

		m[fila-1][columna]=v[1];
		for (int i=0; i<3; i++){
		  m[fila-2][columna+i-1]=v[2+i];
		}
		for (int j=0; j<5; j++){
		  m[fila-3][columna+j-2]=v[5+j];
		}
	        break;
	case 1: // Orientacion Este
		m[fila][columna+1]=v[1];
		for (int i=0; i<3; i++){
		  m[fila+i-1][columna+2]=v[2+i];
		}
		for (int j=0; j<5; j++){
		  m[fila+j-2][columna+3]=v[5+j];
		}
	        break;
        case 2: // Orientacion Sur
		m[fila+1][columna]=v[1];
		for (int i=0; i<3; i++){
		  m[fila+2][columna+1-i]=v[2+i];
		}
		for (int j=0; j<5; j++){
		  m[fila+3][columna+2-j]=v[5+j];
		}
		                break;
        case 3: // Orientacion Oeste
		m[fila][columna-1]=v[1];
		for (int i=0; i<3; i++){
		  m[fila+1-i][columna-2]=v[2+i];
		}
		for (int j=0; j<5; j++){
		  m[fila+2-j][columna-3]=v[5+j];
		}

                break;
    }

}


// -----------------------------------------------------------
void Agent::Perceive(Environment &env)
{
	env.SenSorStatus(VISTA_, SURFACE_, MENSAJE_, REINICIADO_, EN_USO_, MOCHILLA_, PUNTUACION_, FIN_JUEGO_, SALUD_, false);

}


bool Agent::Perceive_Remote(conexion_client &Cliente, Environment &env)
{
	bool actualizado=false;


	actualizado = env.Perceive_Remote(Cliente);
	if (actualizado)
		env.SenSorStatus(VISTA_, SURFACE_, MENSAJE_, REINICIADO_, EN_USO_, MOCHILLA_, PUNTUACION_, FIN_JUEGO_, SALUD_, true);

    return actualizado;
}


// -----------------------------------------------------------
string ActionStr(Agent::ActionType accion)
{
	switch (accion)
	{
	case Agent::actFORWARD: return "FORWARD";
	case Agent::actTURN_L: return "TURN LEFT";
	case Agent::actTURN_R: return "TURN RIGHT";
	case Agent::actIDLE: return "IDLE";
	case Agent::actPICKUP: return "PICK UP";
	case Agent::actPUTDOWN: return "PUT DOWN";
	case Agent::actPUSH: return "PUSH";
	case Agent::actPOP: return "POP";
	case Agent::actGIVE: return "GIVE";
	case Agent::actTHROW: return "THROW";
	default: return "????";
	}
}

// -----------------------------------------------------------
void Agent::ActualizarInformacion(Environment *env){
	// Actualizar mi informacion interna
	if (REINICIADO_){ 
		// Lo que tengas que hacer si eres reposicionado en el juego
		for (int i=0;i<200;i++){
			for(int j=0; j<200; j++){
				mapa_entorno_[i][j]='?';	
				mapa_objetos_[i][j]='?';
			}
		}
	x_=99;
	y_=99;
	orientacion_=3;
	}

	switch(last_accion_){
	  case 0: //avanzar
	  switch(orientacion_){
	    case 0: // norte
		    y_--;
		    break;
	    case 1: // este
		    x_++;
		    break;
	    case 2: // sur
		    y_++;
		    break;
	    case 3: // este
		    x_--;
		    break;
	  }
	  break;
	  case 1: // girar izq
		  orientacion_=(orientacion_+3)%4;
		  break;
	  case 2: // girar dch
		  orientacion_=(orientacion_+1)%4;
		  break;
	}

	// Comprobacion para no salirme del rango del mapa
	bool algo_va_mal=false;
	if (y_<0){
		y_=0;
		algo_va_mal=true;
	} 
	else if (y_>199){
		y_=199;
		algo_va_mal=true;
	}
	if (x_<0){
		x_=0;
		algo_va_mal=true;
	} 
	else if (x_>199){
		x_=199;
		algo_va_mal=true;
	}

	if (algo_va_mal){
		cout << "CUIDADO: NO ESTAS CONTROLANDO BIEN LA UBICACION DE TU AGENTE\n";
	}


	PasarVectoraMapaCaracteres(y_,x_,mapa_entorno_,VISTA_,orientacion_);
	PasarVectoraMapaCaracteres(y_,x_,mapa_objetos_,SURFACE_,orientacion_);

	env->ActualizarMatrizUsuario(mapa_entorno_);

}

// -----------------------------------------------------------
Agent::ActionType Agent::Think()
{
	Agent::ActionType accion = actFORWARD; // Por defecto avanza
	
	//tomar accion, añadido como ejemplo en clase
	if(giro_final){
	cout<<"regla 3: ultimo movimiento";
	accion = actTURN_R;
	giro_final=false;
	}	
	
	else if(VISTA_[1]=='d' or VISTA_[1]=='e' or VISTA_[1]=='j' or VISTA_[1]=='k' or VISTA_[1]=='l' or VISTA_[1]=='m' or VISTA_[1]=='n' or VISTA_[1]=='o' or VISTA_[1]=='p' or VISTA_[1]=='q' or VISTA_[1]=='r' or VISTA_[1]=='s' or VISTA_[1]=='t' or VISTA_[1]=='u' or VISTA_[1]=='v' or VISTA_[1]=='w' or VISTA_[1]=='x' or VISTA_[1]=='y' or VISTA_[1]=='z'){
		if(rand()%2==0){
			accion = actTURN_L;
		}
		else{
			accion = actTURN_R;
		}
	cout << "HUYE CONDENADO\n";
	}
/*
	else if(VISTA_[0]=='K'){
	CapturaFilaColumnaPK(MENSAJE_, x_, y_); No se si lo de x_ e y_ es correcto
	}
*/
	else if(VISTA_[0]=='0' or VISTA_[0]=='1' or VISTA_[0]=='2' or VISTA_[0]=='3' or VISTA_[0]=='4' or VISTA_[0]=='5' or VISTA_[0]=='6' or VISTA_[0]=='7' or VISTA_[0]=='8' or VISTA_[0]=='9'){
	accion = actPICKUP;
	cout << "COGERLO\n";
	}

	else if(VISTA_[1]=='B' or VISTA_[1]=='M' or VISTA_[1]=='P' or VISTA_[1]=='A'){
		if(rand()%2==0){
			accion = actTURN_L;
		}
		else{
			accion = actTURN_R;
		}	
		giro_inicial=true;
		giro_final=false;
		cout << "Regla 1: Evita obstaculos en el terreno\n";

	}
	

	else if( giro_inicial){
		cout<< "Regla 2: primera parte del movimiento\n";	
		accion=actFORWARD;	
		giro_inicial=false;
		giro_final=true;
	}

	else if (avance<20){
		cout<<"Regla 4: Sigo para alante\n";
		accion = actFORWARD;
		avance++;
	}
	
	else if (rand()%2==0){
		cout <<"Regla 5a: Mirar nuevas cosas\n";
		accion = actTURN_L;
		avance=0;	
	}

	else{
		cout <<"Regla 5b: Mirar nuevas cosas\n";
		accion = actTURN_R;
		avance=0;
	}



	// recuerdo la ultima accion realizada
	last_accion_ = accion;

	return accion;

}

void Agent::CapturaFilaColumnaPK (string mensaje, int &fila, int &columna){
	if (mensaje.substr(0,8)=="PK fila:"){
		int pos = mensaje.find('c');
		string valor = mensaje.substr(9,pos-8);
		fila = atoi(valor.c_str());
		
		int pos2 = mensaje.find('.');
		pos = pos+8;
		valor = mensaje.substr(pos,pos2-1);
		columna = atoi(valor.c_str());
	}
}
