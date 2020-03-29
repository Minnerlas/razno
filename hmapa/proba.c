#include "hmapa.h"
#include <stdio.h>

int main(){


	struct hmapa* mapa = naphmapa();

	int a=1;
	dodhmapa(mapa, "nikola1", NINT, &a);
	a=2;
	dodhmapa(mapa, "nikola2", NINT, &a);
	a=3;
	dodhmapa(mapa, "nikola3", NINT, &a);
	a=4;
	dodhmapa(mapa, "nikola4", NINT, &a);
	a=5;
	dodhmapa(mapa, "nikola5", NINT, &a);
	a=6;
	dodhmapa(mapa, "nikola6", NINT, &a);
	a=7;
	dodhmapa(mapa, "nikola7", NINT, &a);
	a=8;
	dodhmapa(mapa, "nikola8", NINT, &a);
	a=9;
	dodhmapa(mapa, "nikola9", NINT, &a);
	a=10;
	dodhmapa(mapa, "nikola10", NINT, &a);
	a=11;
	dodhmapa(mapa, "nikola11", NINT, &a);
	a=12;
	dodhmapa(mapa, "nikola12", NINT, &a);
	a=13;
	dodhmapa(mapa, "nikola13", NINT, &a);

	hstampaj(mapa);

	char t[]="nikola300";

	scanf("%s", t);

	struct hclan *hc = nadjhmapa(mapa, t);
	if(!hc)
		printf("nema\n");
	else
		printf("%s %d\n", hc->ime, hc->vred.i);



	//	char s[100];
	//	fgets(s, 100, stdin);
	//
	//	printf("\n%llu\n", hes(s));
	return 0;
}
