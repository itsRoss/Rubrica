//definzione file header per contatto
#ifndef CONTATTO_H
#define CONTATTO_H

#include <stdio.h>
#include <string.h>
#include "indirizzo.h"

//dichiarazione struttura contatto telefonico
struct contatto_t {
	char cognome[256];
	char nome[256];
	int telefono;
	char email[256];
	char gruppo[256];
	struct indirizzo_t indirizzo;
};

//dichiarazione delle funzioni, poi definite in contatto.c
int compare(struct contatto_t a, struct contatto_t b);

void visualizza_contatto(struct contatto_t contatto);

#endif
