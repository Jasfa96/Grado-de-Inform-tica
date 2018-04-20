/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "DNS1.h"
#include <stdio.h>
#include <stdlib.h>
#include <rpc/pmap_clnt.h>
#include <string.h>
#include <memory.h>
#include <sys/socket.h>
#include <netinet/in.h>

#ifndef SIG_PF
#define SIG_PF void(*)(int)
#endif

static char **
_introducir_1 (introducir_1_argument *argp, struct svc_req *rqstp)
{
	return (introducir_1_svc(argp->arg1, argp->arg2, argp->arg3, rqstp));
}

static char **
_eliminar_1 (eliminar_1_argument *argp, struct svc_req *rqstp)
{
	return (eliminar_1_svc(argp->arg1, argp->arg2, rqstp));
}

static char **
_consultar_1 (consultar_1_argument *argp, struct svc_req *rqstp)
{
	return (consultar_1_svc(argp->arg1, argp->arg2, rqstp));
}

static void *
_introducirdns_1 (introducirdns_1_argument *argp, struct svc_req *rqstp)
{
	return (introducirdns_1_svc(argp->arg1, argp->arg2, rqstp));
}

static void *
_eliminardns_1 (nombre  *argp, struct svc_req *rqstp)
{
	return (eliminardns_1_svc(*argp, rqstp));
}

static void
dns1_1(struct svc_req *rqstp, register SVCXPRT *transp)
{
	union {
		introducir_1_argument introducir_1_arg;
		eliminar_1_argument eliminar_1_arg;
		consultar_1_argument consultar_1_arg;
		introducirdns_1_argument introducirdns_1_arg;
		nombre eliminardns_1_arg;
	} argument;
	char *result;
	xdrproc_t _xdr_argument, _xdr_result;
	char *(*local)(char *, struct svc_req *);

	switch (rqstp->rq_proc) {
	case NULLPROC:
		(void) svc_sendreply (transp, (xdrproc_t) xdr_void, (char *)NULL);
		return;

	case introducir:
		_xdr_argument = (xdrproc_t) xdr_introducir_1_argument;
		_xdr_result = (xdrproc_t) xdr_wrapstring;
		local = (char *(*)(char *, struct svc_req *)) _introducir_1;
		break;

	case eliminar:
		_xdr_argument = (xdrproc_t) xdr_eliminar_1_argument;
		_xdr_result = (xdrproc_t) xdr_wrapstring;
		local = (char *(*)(char *, struct svc_req *)) _eliminar_1;
		break;

	case consultar:
		_xdr_argument = (xdrproc_t) xdr_consultar_1_argument;
		_xdr_result = (xdrproc_t) xdr_wrapstring;
		local = (char *(*)(char *, struct svc_req *)) _consultar_1;
		break;

	case introducirdns:
		_xdr_argument = (xdrproc_t) xdr_introducirdns_1_argument;
		_xdr_result = (xdrproc_t) xdr_void;
		local = (char *(*)(char *, struct svc_req *)) _introducirdns_1;
		break;

	case eliminardns:
		_xdr_argument = (xdrproc_t) xdr_nombre;
		_xdr_result = (xdrproc_t) xdr_void;
		local = (char *(*)(char *, struct svc_req *)) _eliminardns_1;
		break;

	default:
		svcerr_noproc (transp);
		return;
	}
	memset ((char *)&argument, 0, sizeof (argument));
	if (!svc_getargs (transp, (xdrproc_t) _xdr_argument, (caddr_t) &argument)) {
		svcerr_decode (transp);
		return;
	}
	result = (*local)((char *)&argument, rqstp);
	if (result != NULL && !svc_sendreply(transp, (xdrproc_t) _xdr_result, result)) {
		svcerr_systemerr (transp);
	}
	if (!svc_freeargs (transp, (xdrproc_t) _xdr_argument, (caddr_t) &argument)) {
		fprintf (stderr, "%s", "unable to free arguments");
		exit (1);
	}
	return;
}

int
main (int argc, char **argv)
{
	register SVCXPRT *transp;

	pmap_unset (DNS1, DNSVERS);

	transp = svcudp_create(RPC_ANYSOCK);
	if (transp == NULL) {
		fprintf (stderr, "%s", "cannot create udp service.");
		exit(1);
	}
	if (!svc_register(transp, DNS1, DNSVERS, dns1_1, IPPROTO_UDP)) {
		fprintf (stderr, "%s", "unable to register (DNS1, DNSVERS, udp).");
		exit(1);
	}

	transp = svctcp_create(RPC_ANYSOCK, 0, 0);
	if (transp == NULL) {
		fprintf (stderr, "%s", "cannot create tcp service.");
		exit(1);
	}
	if (!svc_register(transp, DNS1, DNSVERS, dns1_1, IPPROTO_TCP)) {
		fprintf (stderr, "%s", "unable to register (DNS1, DNSVERS, tcp).");
		exit(1);
	}

	svc_run ();
	fprintf (stderr, "%s", "svc_run returned");
	exit (1);
	/* NOTREACHED */
}
