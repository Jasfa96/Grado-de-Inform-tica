/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "DNS2.h"

char *
dns2_1(char *host, char *nombre, char *red, char *ip, int codigo)
{
	CLIENT *clnt;
	char * *result_1;
	char * *result_2;
	char * *result_3;


	if(codigo==0){ //Introducir
		#ifndef	DEBUG
			clnt = clnt_create (host, DNS2, DNSVERS, "udp");
			if (clnt == NULL) {
				clnt_pcreateerror (host);
				exit (1);
			}
		#endif	/* DEBUG */

		result_1 = introducir_1(nombre, red, ip, clnt);
		if (result_1 == (char **) NULL) {
			clnt_perror (clnt, "call failed");
		}

		#ifndef	DEBUG
			clnt_destroy (clnt);
		#endif	 /* DEBUG */

		return *result_1;
	}

	if(codigo==1){

		#ifndef	DEBUG
			clnt = clnt_create (host, DNS2, DNSVERS, "udp");
			if (clnt == NULL) {
				clnt_pcreateerror (host);
				exit (1);
			}
		#endif	/* DEBUG */
		result_2 = eliminar_1(nombre, red, clnt);
		if (result_2 == (char **) NULL) {
			clnt_perror (clnt, "call failed");
		}
		#ifndef	DEBUG
			clnt_destroy (clnt);
		#endif	 /* DEBUG */

			return *result_2;
	}

	if(codigo==2){
		#ifndef	DEBUG
			clnt = clnt_create (host, DNS2, DNSVERS, "udp");
			if (clnt == NULL) {
				clnt_pcreateerror (host);
				exit (1);
			}
		#endif	/* DEBUG */

		result_3 = consultar_1(nombre, red, clnt);
		if (result_3 == (char **) NULL) {
			clnt_perror (clnt, "call failed");
		}
		#ifndef	DEBUG
			clnt_destroy (clnt);
		#endif	 /* DEBUG */

			return *result_3;
	}
}

int
main (int argc, char *argv[])
{
	char *host="localhost";
	char *equipo2;
	char *red2;
	int codigo;
	char *ip2;
	char *resultado;
	int comprobacion=0;
	do{

		printf("\nIntroduzca el codigo, 0 para insertar, 1 para borrar, 2 para consultar y -1 para salir. \n");
		scanf("%i", &codigo);

	  if(codigo==-1){exit;}

	  printf("Introduzca el nombre del equipo: ");
	  equipo2=malloc(100);
	  scanf("%s", equipo2);

			printf("Introduzca a la red que pertenece, recuerde, estamos en la Red2: ");
			red2=malloc(103);
	  	scanf("%s", red2);

	  if(codigo==0)
	  {
			printf("Introduzca la ip: ");
	  	ip2=malloc(102);
	  	scanf("%s", ip2);
	    resultado=dns2_1(host,equipo2,red2,ip2,codigo);
	    printf ("%s\n",resultado);

	  }else if(codigo==1){
			resultado=dns2_1(host,equipo2,red2,ip2,codigo);
	    printf ("%s\n",resultado);
	  }else if(codigo==2){
			resultado=dns2_1(host,equipo2,red2,ip2,codigo);
			printf ("%s\n",resultado);
	  }


	}while(codigo!=5);

				free(equipo2);
				free(red2);
				free(ip2);
exit (0);
}
