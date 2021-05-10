//file header per i contatti
#ifndef CONTATTO_H
#define CONTATTO_H

#include <stdio.h>
#include <string.h>
#include "indirizzo.h"

//definisco i gruppi come costanti
#define GRUPPO_AMICI 0
#define GRUPPO_PARENTI 1
#define GRUPPO_COLLEGHI 2
#define GRUPPO_SCONOSCIUTI 3

//dichiarazione struttura di un contatto
struct contatto_t {
	char cognome[256];
	char nome[256];
	int telefono;
	char email[256];
	int gruppo;
	struct indirizzo_t indirizzo;
};

//dichiarazione funzioni, poi definite in contatto.c
int compare(struct contatto_t a, struct contatto_t b);
void visualizza_contatto(struct contatto_t contatto);

#endif
