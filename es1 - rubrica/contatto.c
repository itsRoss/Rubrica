#include "contatto.h"
#include "indirizzo.h"
#include <string.h>

/*funzione per confrontare i contatti in ordine alfabetico
*
* strcmp ritorna i seguenti valori:
* 0 se i contat sono uguali
* valore negativo se a viene prima di b
* positivo se b viene dopo di a
*
*/
int compare(struct contatto_t a, struct contatto_t b) {
    int ordine = strcmp(a.cognome, b.cognome);

    //se i cognomi sono guali controllo il nome
    if (ordine == 0) {
        ordine = strcmp(a.nome, b.nome);
    }
    return ordine;
}

//definizione funzione per la visualizzaazione dei contatti
void visualizza_contatto(struct contatto_t contatto) {

	printf("\n");

    printf("%s %s\n", contatto.cognome, contatto.nome);

    printf("\t%s\n", contatto.gruppo);

    printf("\t%d %s\n", contatto.telefono, contatto.email);
    
    printf("\t%s %d %s %s %s\n", contatto.indirizzo.citta, contatto.indirizzo.cap, contatto.indirizzo.provincia, contatto.indirizzo.via, contatto.indirizzo.civico);

    printf("\n");
}
