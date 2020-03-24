#ifndef LISTA_H
#define LISTA_H

#include "../tipovi.h"

//Makroi

//Tipovi

struct lista {
	struct clan* prvi;
	struct clan* posl;
	int duz;
};

struct clan {
	enum tip tip;
	union {
		char c;
		int i;
		float fl;
		double db;
		void *pok;
	} vred;
	struct clan* sled;
};

//Funkcije

struct lista*	naplist();
int 			dodlist(struct lista* l, enum tip tip, void* vred); 
struct clan*	nclanl(struct lista* l, int n);

#endif	/* LISTA_H */
