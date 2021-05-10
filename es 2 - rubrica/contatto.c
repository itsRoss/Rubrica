#include "contatto.h"
#include <string.h>
#include "indirizzo.h"

//definizione funzione che compara due contatti tra loro
int compare(struct contatto_t a, struct contatto_t b) {
	
	//controllo i cognomi
    int ordine = strcmp(a.cognome, b.cognome);
    
    //se i due contatti hanno lo stesso cognome controllo il nome
    if (ordine == 0) {
        ordine = strcmp(a.nome, b.nome);
    }
    return ordine;
}

//definizione funzione per la visualizzazione del contatto
void visualizza_contatto(struct contatto_t contatto) {
	
	printf("\n");
	//visualizzo cognome e nome
    printf("%s %s\n", contatto.cognome, contatto.nome);
    
    //stampo il gruppo di appartenenza
    switch (contatto.gruppo) {
        case 0:
            printf("\tamici\n");
            break;
        case 1:
            printf("\tparenti\n");
            break;
        case 2:
            printf("\tcolleghi\n");
            break;
        case 3:
            printf("\tsconosciuti\n");
            break;
        default:
            printf("\tgruppo non assegnato\n");
            break;
    }
    
    //stampo le restanti informazioni
    printf("\t%d %s\n", contatto.telefono, contatto.email);
    printf("\t%s %d %s %s %s\n", contatto.indirizzo.citta, contatto.indirizzo.cap, contatto.indirizzo.provincia, contatto.indirizzo.via, contatto.indirizzo.civico);
    printf("\n");
}

