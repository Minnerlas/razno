#include "dinniz.h"

#include <stdlib.h>

struct dniz *napniz(enum tip tip){
	struct dniz *n=malloc(sizeof(struct dniz));
	n->duz=0;
	n->stvduz=POC_DUZ;
	n->tip = tip;
	size_t vel=0;
	switch(tip){
		case NCHAR:
			vel=sizeof(char);
			break;
		case NINT:
			vel=sizeof(int);
			break;
		case NFLOAT:
			vel=sizeof(float);
			break;
		case NDOUBLE:
			vel=sizeof(double);
			break;
		case NPOK:
			vel=sizeof(void*);
			break;
		default:
			return NULL;
	}

	n->niz=malloc(POC_DUZ*vel);
	return n;
}


void brisniz(struct dniz *niz){
	free(niz->niz);
	free(niz);
}

union pok{
	char   *c;
	int    *br;
	float  *fl;
	double *db;
	void  **pok;
};

int dodniz(struct dniz *niz, void *vred){
	int i;
	union pok p;
	switch(niz->tip){
		case NCHAR:
			p.c=niz->niz;
			if(niz->duz==niz->stvduz){
				niz->stvduz*=2;
				char *t1=malloc(niz->stvduz*sizeof(char));
				if(t1==NULL)
					return 0;
				for(i=0; i<niz->duz; t1[i]=p.c[i],i++);
				free(p.c);
				p.c=niz->niz=t1;

				//printf("vel %d, svel %d, vred %c\n", niz->duz, niz->stvduz, *(char*)vred);
			}
			p.c[niz->duz]=*(char*)vred;
			niz->duz++;
			break;

		case NINT:
			p.br=niz->niz;
			if(niz->duz==niz->stvduz){
				niz->stvduz*=2;
				int *t1=malloc(niz->stvduz*sizeof(int));
				if(t1==NULL)
					return 0;
				for(i=0; i<niz->duz; t1[i]=p.br[i],i++);
				free(p.br);
				p.br=niz->niz=t1;
			}
			p.br[niz->duz]=*(int*)vred;
			niz->duz++;
			break;

		case NFLOAT:
			p.fl=niz->niz;
			if(niz->duz==niz->stvduz){
				niz->stvduz*=2;
				float *t1=malloc(niz->stvduz*sizeof(float));
				if(t1==NULL)
					return 0;
				for(i=0; i<niz->duz; t1[i]=p.fl[i],i++);
				free(p.fl);
				p.fl=niz->niz=t1;
			}
			p.fl[niz->duz]=*(float*)vred;
			niz->duz++;
			break;

		case NDOUBLE:
			p.db=niz->niz;
			if(niz->duz==niz->stvduz){
				niz->stvduz*=2;
				double *t1=malloc(niz->stvduz*sizeof(double));
				if(t1==NULL)
					return 0;
				for(i=0; i<niz->duz; t1[i]=p.db[i],i++);
				free(p.db);
				p.db=niz->niz=t1;
			}
			p.db[niz->duz]=*(double*)vred;
			niz->duz++;
			break;

		case NPOK:
			p.pok=niz->niz;
			if(niz->duz==niz->stvduz){
				niz->stvduz*=2;
				void **t1=malloc(niz->stvduz*sizeof(void*));
				if(t1==NULL)
					return 0;
				for(i=0; i<niz->duz; t1[i]=p.pok[i],i++);
				free(p.pok);
				p.pok=niz->niz=t1;
			}
			p.pok[niz->duz]=*(void**)vred;
			niz->duz++;
			break;

		default:
			return 0;
	}

	return 1;
}

void *nizcl(struct dniz *niz, int n){
	if(n>=niz->duz || n<0)
		return NULL;

	union pok p;
	switch(niz->tip){
		case NCHAR:
			p.c=niz->niz;
			return (void*)(p.c+n);
		case NINT:
			p.br=niz->niz;
			return (void*)(p.br+n);
		case NFLOAT:
			p.fl=niz->niz;
			return (void*)(p.fl+n);
		case NDOUBLE:
			p.db=niz->niz;
			return (void*)(p.db+n);
		case NPOK:
			p.pok=niz->niz;
			return (void*)(p.pok+n);
		default:
			return NULL;
	}
}
