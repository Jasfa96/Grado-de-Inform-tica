#include <iostream>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>      // incluye "time(....)"
#include <unistd.h>    // incluye "usleep(...)"
#include <stdlib.h>    // incluye "rand(...)" y "srand"

// ----------------------------------------------------------------------------
// función que simula la acción de fumar  como un retardo aleatorio de la hebra

sem_t s_papel;
sem_t s_tabaco;
sem_t s_cerillas;
sem_t s_mostrador;

void fumar() 
{ 
   //  inicializa la semilla aleatoria  (solo la primera vez)
   static bool primera_vez = true ;
   if ( primera_vez )
   {   primera_vez = false ;
      srand( time(NULL) );    
   }
   
   // calcular un numero aleatorio de milisegundos (entre 1/10 y 2 segundos)
   const unsigned miliseg = 100U + (rand() % 1900U) ; 

   // retraso bloqueado durante 'miliseg' milisegundos
   usleep( 1000U*miliseg ); 
}
// ----------------------------------------------------------------------------
void * sin_tabaco(void *){
	while(true){
		sem_wait(&s_tabaco);
		sem_post(&s_mostrador);
		fumar();
	}
	return NULL;
}

void * sin_cerillas(void *){
	while(true){
		sem_wait(&s_cerillas);
		sem_post(&s_mostrador);
		fumar();
	}
	return NULL;
}

void * sin_papel(void *){
	while(true){
		sem_wait(&s_papel);
		sem_post(&s_mostrador);
		fumar();
	}
	return NULL;
}

void * mostrador(void  *){
	while(true){
		sem_wait(&s_mostrador);
		int aleatorio=rand()%3;
		if (aleatorio==1){
			sem_post(&s_tabaco);
		}
		if (aleatorio==2){
			sem_post(&s_papel);
		}
		if (aleatorio==3){
			sem_post(&s_cerillas);
		}
	}
	return NULL;
}
// ----------------------------------------------------------------------------

int main()
{
pthread_t h_papel, h_cerillas, h_tabaco, h_estanquero;

	sem_init (&s_papel,0,0);
	sem_init (&s_tabaco,0,0);  
	sem_init (&s_cerillas,0,0);  
	sem_init (&s_mostrador,0,1);

	pthread_create(&h_papel,NULL,sin_papel,NULL);
	pthread_create(&h_tabaco,NULL,sin_tabaco,NULL);
	pthread_create(&h_cerillas,NULL,sin_cerillas,NULL);
	pthread_create(&h_estanquero,NULL,mostrador,NULL);

//Esperar fin de hebra.

	pthread_join(h_tabaco, NULL);
	pthread_join(h_cerillas, NULL);
	pthread_join(h_papel, NULL);
	pthread_join(h_estanquero, NULL);

//Destruir semaforo.
	sem_destroy(&s_mostrador);
	sem_destroy(&s_papel);
	sem_destroy(&s_cerillas);
	sem_destroy(&s_tabaco);
	return 0 ;
}
