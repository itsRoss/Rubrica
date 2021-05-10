//definizione file header per rubrica
#ifndef RUBRICA_H
#define RUBRICA_H

#include <stdbool.h>
#include "contatto.h"

//dichiaro dimensione massima rubruca (da specifica)
#define MAX_CONTATTI 32

//dichiarazione struttura rubrica
struct rubrica_t{
	struct contatto_t contatti[MAX_CONTATTI];
	int dimensione;
};

//dichiarazione delle funzioni
//ritorna la posizione del contatto oppure contatto non trovato
int cerca(struct rubrica_t rubrica, struct contatto_t contatto);

struct rubrica_t inserisci(struct rubrica_t rubrica, struct contatto_t contatto);

struct rubrica_t cancella(struct rubrica_t rubrica, int posizione);

void visualizza_rubrica(struct rubrica_t rubrica);

#endif
