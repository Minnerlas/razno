#ifndef HMAPA_H
#define HMAPA_H

#include <stdint.h>
#include "../tipovi.h"

//Makroi

#define HPOCDUZ 8

//Tipovi

struct hmapa {
	int duz;
	int stvduz;
	struct hclan **niz;
};

struct hclan {
	char *ime;
	enum tip tip;
	uint64_t hesv;
	union {
		char c;
		int i;
		float fl;
		double db;
		void* pok;
	} vred;
};

//Funkcije

struct hmapa*	naphmapa();
int 			dodhmapa(struct hmapa* h, const char* ime, enum tip tip, void* v);
struct hclan*	nadjhmapa(struct hmapa* h, const char* ime);
void 			hstampaj(struct hmapa *mapa);

#endif /* HMAPA_H */
