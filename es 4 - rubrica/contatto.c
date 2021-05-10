#include "contatto.h"
#include "indirizzo.h"
#include <string.h>

//funzione per confrontare i contatti
int compare(struct contatto_t a, struct contatto_t b) {
	//confronto i cognomi
    int ordine = strcmp(a.cognome, b.cognome);
	
	//confronto i nomi
    if (ordine == 0) {
        ordine = strcmp(a.nome, b.nome);
    }
    return ordine;
}

//visualizzo il contatto
void visualizza_contatto(struct contatto_t contatto) {
	
	//stampa informazioni contatto
	printf("\n");
    printf("\tCognome:\t%s\n", contatto.cognome);
    printf("\tNome:\t\t%s\n", contatto.nome);
    printf("\tTelefono:\t%d\n", contatto.telefono);
    printf("\tEmail:\t\t%s\n", contatto.email);
    printf("\tGruppo:\t\t");

	//stampo il gruppo
    switch (contatto.gruppo) {
        case AMICI:
            printf("amici\n");
            break;
        case PARENTI:
            printf("parenti\n");
            break;
        case COLLEGHI:
            printf("colleghi\n");
            break;
        case SCONOSCIUTI:
            printf("sconosciuti\n");
            break;
        default:
            printf("gruppo non assegnato\n");
            break;
    }
    printf("\tIndirizzo:\t%s %d %s %s %s\n", contatto.indirizzo.citta, contatto.indirizzo.cap, contatto.indirizzo.provincia, contatto.indirizzo.via, contatto.indirizzo.civico);
	printf("\n");
}

/*
 * Salva i dati del contatto specificato su un file di testo utilizzando il separatore indicato
 */
void save_contatto(FILE *fp, struct contatto_t contatto, char sep) {
    fprintf(fp, "%s%c%s%c%d%c%s%c%d%c",
            contatto.cognome, sep,
            contatto.nome, sep,
            contatto.telefono, sep,
            contatto.email, sep,
            contatto.gruppo, sep);
    save_indirizzo(fp, contatto.indirizzo, sep);
}

