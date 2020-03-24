#include "lista.h"

#include <stdlib.h>
#include <stdio.h>

struct lista* naplist(){
	struct lista *l = malloc(sizeof(struct lista));
	l->prvi=NULL;
	l->posl=NULL;
	l->duz=0;
	return l;
}

int dodlist(struct lista* l, enum tip tip, void* vred){
	struct clan *c = malloc(sizeof(struct clan));
	if(!c)
		return 0;


	switch(tip){
		case NCHAR:
			c->vred.c=*(char*)vred;
			break;
		case NINT:
			c->vred.i=*(int*)vred;
			break;
		case NFLOAT:
			c->vred.fl=*(float*)vred;
			break;
		case NDOUBLE:
			c->vred.db=*(double*)vred;
			break;
		case NPOK:
			c->vred.pok=*(void**)vred;
			break;
		default:
			return 0;
	}


	c->tip=tip;
	c->sled=NULL;
	if(!l->prvi){
		l->prvi=l->posl=c;
		l->duz++;
	}else{
		l->posl->sled=c;
		l->posl=c;
		l->duz++;
	}

	return 1;
}

struct clan* nclanl(struct lista* l, int n){
	if(n==l->duz-1)
		return l->posl;
	struct clan* c=l->prvi;
	for (int i=0; (i<n)&&(c!=NULL); i++,c=c->sled); 
	return c;
}
