/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#ifndef _DNS2_H_RPCGEN
#define _DNS2_H_RPCGEN

#include <rpc/rpc.h>


#ifdef __cplusplus
extern "C" {
#endif

#define TAM 100

typedef char *nombre;

typedef char *red;

typedef char *ip;

struct introducir_1_argument {
	nombre arg1;
	red arg2;
	ip arg3;
};
typedef struct introducir_1_argument introducir_1_argument;

struct eliminar_1_argument {
	nombre arg1;
	red arg2;
};
typedef struct eliminar_1_argument eliminar_1_argument;

struct consultar_1_argument {
	nombre arg1;
	red arg2;
};
typedef struct consultar_1_argument consultar_1_argument;

#define DNS2 0x20000002
#define DNS1 0x20000001
#define DNSVERS 1

#if defined(__STDC__) || defined(__cplusplus)
#define introducir 1
extern  char ** introducir_1(nombre , red , ip , CLIENT *);
extern  char ** introducir_1_svc(nombre , red , ip , struct svc_req *);
#define eliminar 2
extern  char ** eliminar_1(nombre , red , CLIENT *);
extern  char ** eliminar_1_svc(nombre , red , struct svc_req *);
#define consultar 3
extern  char ** consultar_1(nombre , red , CLIENT *);
extern  char ** consultar_1_svc(nombre , red , struct svc_req *);
extern int dns2_1_freeresult (SVCXPRT *, xdrproc_t, caddr_t);

#else /* K&R C */
#define introducir 1
extern  char ** introducir_1();
extern  char ** introducir_1_svc();
#define eliminar 2
extern  char ** eliminar_1();
extern  char ** eliminar_1_svc();
#define consultar 3
extern  char ** consultar_1();
extern  char ** consultar_1_svc();
extern int dns2_1_freeresult ();
#endif /* K&R C */

/* the xdr functions */

#if defined(__STDC__) || defined(__cplusplus)
extern  bool_t xdr_nombre (XDR *, nombre*);
extern  bool_t xdr_red (XDR *, red*);
extern  bool_t xdr_ip (XDR *, ip*);
extern  bool_t xdr_introducir_1_argument (XDR *, introducir_1_argument*);
extern  bool_t xdr_eliminar_1_argument (XDR *, eliminar_1_argument*);
extern  bool_t xdr_consultar_1_argument (XDR *, consultar_1_argument*);

#else /* K&R C */
extern bool_t xdr_nombre ();
extern bool_t xdr_red ();
extern bool_t xdr_ip ();
extern bool_t xdr_introducir_1_argument ();
extern bool_t xdr_eliminar_1_argument ();
extern bool_t xdr_consultar_1_argument ();

#endif /* K&R C */

#ifdef __cplusplus
}
#endif

#endif /* !_DNS2_H_RPCGEN */
