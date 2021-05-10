//file header per la rubrica
#ifndef RUBRICA_H
#define RUBRICA_H

#include "contatto.h"

//costante per la dimensione
#define MAX_CONTATTI 32

//separatore di linea
#define SEP ';'

//endo of lime
#define EOL '\n'

//dichiarazione struttra elemento telefonico
struct elemento_t {
    char chiave[256];
    struct contatto_t valore;
};

//dichiarazione struttura per la rubrica
struct rubrica_t {
    struct elemento_t elementi[MAX_CONTATTI];
    int dimensione;
};

//dichiarazione delle funzioni
int cerca(struct rubrica_t rubrica, char chiave[]);

struct contatto_t get_contatto(struct rubrica_t rubrica, char chiave[]);

struct rubrica_t inserisci(struct rubrica_t rubrica, char chiave[], struct contatto_t contatto);

struct rubrica_t cancella(struct rubrica_t rubrica, char chiave[]);

void visualizza_rubrica(struct rubrica_t rubrica);

void save_rubrica(struct rubrica_t rubrica, char filename[]);

void load_rubrica(struct rubrica_t *rubrica, char filename[]);

#endif
