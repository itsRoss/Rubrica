#include "contatto.h"
#include "indirizzo.h"
#include <string.h>

//fuzione per confrontare due contatti tra loro
int compare(struct contatto_t a, struct contatto_t b) {
	
	//controllo i cognomi
    int ordine = strcmp(a.cognome, b.cognome);
    
    //controllo i nomi
    if (ordine == 0) {
        ordine = strcmp(a.nome, b.nome);
    }
    return ordine;
}

//funzione per la visualizzazione di un contatto
void visualizza_contatto(struct contatto_t contatto) {
	
	//stampa cognome e nome
	printf("\n");
    printf("%s %s\n", contatto.cognome, contatto.nome);
    
    //stamo il gruppo
    switch (contatto.gruppo) {
        case AMICI:
            printf("\tamici\n");
            break;
        case PARENTI:
            printf("\tparenti\n");
            break;
        case COLLEGHI:
            printf("\tcolleghi\n");
            break;
        case SCONOSCIUTI:
            printf("\tsconosciuti\n");
            break;
        default:
            printf("\tgruppo non assegnato\n");
            break;
    }
    
    //stampa informazioni rimanenti
    printf("\t%d %s\n", contatto.telefono, contatto.email);
    printf("\t%s %d %s %s %s\n", contatto.indirizzo.citta, contatto.indirizzo.cap, contatto.indirizzo.provincia, contatto.indirizzo.via, contatto.indirizzo.civico);
	printf("\n");
}

