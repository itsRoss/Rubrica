#ifndef RUBRICA_H
#define RUBRICA_H

#include <stdbool.h>
#include "contatto.h"

#define MAX_CONTATTI 32

struct rubrica_t{
	struct contatto_t contatti[MAX_CONTATTI];
	int dimensione;
};

struct rubrica_t ordina(struct rubrica_t rubrica);

/*
 * Ritorna la posizione a cui si trova il contatto.
 * Ritorna -1 se il contatto non viene trovato.
 */
int cerca(struct rubrica_t rubrica, struct contatto_t contatto);

struct rubrica_t inserisci(struct rubrica_t rubrica, struct contatto_t contatto);
struct rubrica_t cancella(struct rubrica_t rubrica, int posizione);
void visualizza_rubrica(struct rubrica_t rubrica);
#endif
