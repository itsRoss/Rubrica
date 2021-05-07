#include "contatto.h"

#include <string.h>

#include "indirizzo.h"

int compare(struct contatto_t a, struct contatto_t b) {
    int ordine = strcmp(a.cognome, b.cognome);

    if (ordine == 0) {
        ordine = strcmp(a.nome, b.nome);
    }
    return ordine;
}

void visualizza_contatto(struct contatto_t contatto) {
    printf("%s %s\n", contatto.cognome, contatto.nome);
    printf("\t%s\n", contatto.gruppo);
    printf("\t%d %s\n", contatto.telefono, contatto.email);
    printf("\t%s %d %s %s %s\n", contatto.indirizzo.citta, contatto.indirizzo.cap, contatto.indirizzo.provincia, contatto.indirizzo.via, contatto.indirizzo.civico);
}
