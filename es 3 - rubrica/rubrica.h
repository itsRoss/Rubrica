//file header rubrica vista come dizionario
#ifndef RUBRICA_H
#define RUBRICA_H

#include "contatto.h"

#define MAX_CONTATTI 32

//dichiaro struttura per un elemento telefonico
struct elemento_t{
	//chiave di tipo nome - cognome utilizzata per identificare un elemento
	char chiave[256];
	//contatto associato all'elemento
	struct contatto_t valore;
};

//dichiarazione struttra per la rubrica
struct rubrica_t{
	struct elemento_t elementi[MAX_CONTATTI];
	int dimensione;
};

//dichiarazione delle funzioni
int cerca(struct rubrica_t rubrica, char chiave[]);

struct contatto_t get_contatto(struct rubrica_t rubrica, char chiave[]);

struct rubrica_t inserisci(struct rubrica_t rubrica, char chiave[], struct contatto_t contatto);

struct rubrica_t cancella(struct rubrica_t rubrica, char chiave[]);

void visualizza_rubrica(struct rubrica_t rubrica);

#endif
