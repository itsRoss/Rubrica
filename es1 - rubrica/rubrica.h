//definzione file header per rubrica.h
#ifndef RUBRICA_H
#define RUBRICA_H

#include <stdbool.h>
#include "contatto.h"
#define MAX_CONTATTI 32

//definzione struttra rubrica
struct rubrica_t{
	struct contatto_t contatti[MAX_CONTATTI];
	int dimensione;
};


//dichiarazione funzioni della rubrica
struct rubrica_t ordina(struct rubrica_t rubrica);

//ritorna la posizone del contatto o -1 se non lo trova
int cerca(struct rubrica_t rubrica, struct contatto_t contatto);

struct rubrica_t inserisci(struct rubrica_t rubrica, struct contatto_t contatto);

struct rubrica_t cancella(struct rubrica_t rubrica, int posizione);

void visualizza_rubrica(struct rubrica_t rubrica);

#endif
