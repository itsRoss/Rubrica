//file header per contatto
#ifndef CONTATTO_H
#define CONTATTO_H

#include <stdio.h>
#include <string.h>
#include "indirizzo.h"

//enum GRUPPO{ AMICI = 0, PARENTI = 1, COLLEGHI = 2, SCONOSCIUTI = 3};
typedef enum { AMICI, PARENTI, COLLEGHI, SCONOSCIUTI} GRUPPO;

//dichiarazione struttra contatto
struct contatto_t {
	char cognome[256];
	char nome[256];
	int telefono;
	char email[256];
	GRUPPO gruppo;
	struct indirizzo_t indirizzo;
};

//dichiarazione funzioni, poi definite in contatto.c
int compare(struct contatto_t a, struct contatto_t b);

void visualizza_contatto(struct contatto_t contatto);

#endif
