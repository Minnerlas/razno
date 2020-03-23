#include <stdio.h>
#include "dinniz.h"

int main(){
	struct dniz *niz=napniz(NCHAR);
	char c;
	
	for(; (c=getchar())!='\n'; dodniz(niz, &c));
	c='\0';
	dodniz(niz, &c);

	printf("%s\n", niz->niz);

	brisniz(niz);
	return 0;
}
