#include "hmapa.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

void hstampaj(struct hmapa *mapa){
	for(int i=0; i < mapa->stvduz; i++){
		printf("%4d:\t", i);
		if(!mapa->niz[i])
			printf("(null)\n");
		else{
			struct hclan *t=mapa->niz[i];
			printf("\"%s\", heš: %llu, vred: %d\n", t->ime, t->hesv, t->vred.i);
		}
	}

}

static uint64_t hes(const char *s) { // Treba da bude static
	const int p = 31;
	const int m = 1e9 + 9;
	uint64_t hash_value = 0;
	uint64_t p_pow = 1;
	for (char *c = (char*)s; *c; c++) {
		hash_value = (hash_value + (*c - 'a' + 1) * p_pow) % m;
		p_pow = (p_pow * p) % m;
	}
	return hash_value;
}

struct hmapa* naphmapa(){
	struct hmapa *h = malloc(sizeof(*h));
	if(h){
		h->duz = 0;
		h->stvduz = HPOCDUZ;
		if(!(h->niz = malloc(HPOCDUZ*sizeof(struct hclan*)))){
			free(h);
			return NULL;
		}
		for(int i=0; i<HPOCDUZ; i++)
			h->niz[i]=NULL;
	}
	return h;
}

int dodhmapa(struct hmapa* h, const char* ime, enum tip tip, void* v){
	struct hclan* hc = malloc(sizeof(*hc));
	if(!hc)
		return -1;
	hc->tip=tip;
	switch(tip){
		case NCHAR:
			hc->vred.c=*(char*)v;
			break;
		case NINT:
			hc->vred.i=*(int*)v;
			break;
		case NFLOAT:
			hc->vred.fl=*(float*)v;
			break;
		case NDOUBLE:
			hc->vred.db=*(double*)v;
			break;
		case NPOK:
			hc->vred.pok=*(void**)v;
			break;
		default:
			free(hc);
			return -1;
	}

	hc->ime = malloc(sizeof(char)*(strlen(ime)+1));
	if(!hc->ime)
		return -1;

	strcpy(hc->ime, ime);

	if(h->duz >= (h->stvduz*3/4)){
		struct hclan **t = malloc(h->stvduz*2*sizeof(h->niz));
		if(!t)
			return -1;

		struct hclan *t1;
		for(int i=0; i<h->stvduz*2; t[i++]=NULL);
		for(int i=0; i<h->stvduz; i++){
			if(!(t1=h->niz[i]))
				continue;
			int ind;
			for(ind = t1->hesv % (h->stvduz*2); t[ind]; ind = (ind+1)%(h->stvduz*2));
			t[ind]=t1;

		}
		free(h->niz);
		h->niz=t;
		h->stvduz*=2;
	}


	hc->hesv = hes(ime);
	int i = hc->hesv % h->stvduz;
	for(; h->niz[i]; i = (i+1)%h->stvduz)
		if(!strcmp(ime, h->niz[i]->ime)){
			free(hc->ime);
			free(hc);
			return -1;
		}

	h->niz[i]=hc;
	h->duz++;

	return 0;
}

struct hclan* nadjhmapa(struct hmapa* h, const char* ime){
	uint64_t hesv = hes(ime);
	int i, duz = 0;
	struct hclan* t;
	if(!h->niz[hesv % h->stvduz])
		return NULL;
	for(i = hesv % h->stvduz, t = h->niz[i];
			(t) && (duz < h->stvduz) && (t->hesv != hesv) && (strcmp(t->ime, ime)); 
			i++, t = h->niz[i], duz++){

		//printf("h: %llu %llu %d\n", t->hesv, hesv, strcmp(t->ime, ime));
	}
	if(t==NULL)
		return NULL;

	if(!strcmp(t->ime, ime)){
		return t;
	}
	return NULL;
}
