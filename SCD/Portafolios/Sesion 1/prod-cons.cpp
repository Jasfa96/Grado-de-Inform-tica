#include <iostream>
#include <cassert>
#include <pthread.h>
#include <semaphore.h>
using namespace std ;

// ---------------------------------------------------------------------
// constantes 
const unsigned 
  num_items  = 60 ,
  tam_vector = 20 ;              

// ---------------------------------------------------------------------

sem_t semaforouno;
sem_t semaforodos;
sem_t semaforotres;

int buffer[tam_vector];
int pos=0;

unsigned producir_dato()
{
  static int contador = 0 ;
  cout << "producido: " <<  contador << endl << flush ;
  return contador++ ;
}
// ---------------------------------------------------------------------

void consumir_dato( int dato )
{
    cout << "dato recibido: " << dato << endl ;
}
// ---------------------------------------------------------------------

void * productor( void * )
{   
  for( unsigned i = 0 ; i < num_items ; i++ )
  { 
    int dato = producir_dato() ;
	
	sem_wait(&semaforouno);
	buffer[pos]=dato;
	pos++;
	if (pos<tam_vector){
	sem_post(&semaforodos);
	}
	else{
	sem_wait(&semaforouno);
	}
       
  }
  return NULL ;
}
// ---------------------------------------------------------------------

void * consumidor( void * )
{   
  for( unsigned i = 0 ; i < num_items ; i++ )
  {   
    int dato ;
	sem_wait(&semaforodos);
	sem_wait(&semaforotres);
	pos--;
	dato=buffer[pos];
	sem_post(&semaforotres);
	sem_post(&semaforouno);
	
	consumir_dato(dato);
  }
  return NULL ;
}
//----------------------------------------------------------------------

int main()
{
   pthread_t hebrac,hebrap;

	sem_init(&semaforouno,0,1);
	sem_init(&semaforotres,0,1);
	sem_init(&semaforodos,0,0);

	pthread_create(&hebrac,NULL,consumidor,NULL);
	pthread_create(&hebrap,NULL,productor,NULL);

	pthread_join(hebrac, NULL);
	pthread_join(hebrap, NULL);

	sem_destroy(&semaforouno);
	sem_destroy(&semaforodos);
	sem_destroy(&semaforotres);

	pthread_exit(NULL);

   return 0 ; 
}
