#ifndef DINNIZ_H
#define DINNIZ_H

//Makroi

#define POC_DUZ 8

//Tipovi

enum tip {
	NCHAR,
	NINT,
	NFLOAT,
	NDOUBLE,
};

struct dniz {
	void *niz;
	int duz;
	int stvduz;
	enum tip tip;
};

//Funkcije

struct dniz	*napniz(enum tip tip);
void		brisniz(struct dniz *niz);
int			dodniz(struct dniz *niz, void *clan);
void		*nizcl(struct dniz *niz, int n);

#endif /* DINNIZ_H */
