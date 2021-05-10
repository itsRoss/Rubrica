#include <stdio.h>

#include "rubrica.h"

int main() {
    struct rubrica_t rubrica;
    rubrica.dimensione = 0;
    
    //inizio programma
    printf("-------------------\n");
    printf("Benvenuto nella tua rubrica\n");
    printf("-------------------\n");
    printf("\n");
    
    //visualizzo la rubrica per la prima volta
    visualizza_rubrica(rubrica);
    printf("-------------------\n");

	//dichiaro tre contatti
    struct contatto_t contatto1 = {"bombieri", "nicola", 333, "nicola.bombieri@univr.it", 2, {"Verona", 37134, "VR", "strada le grazie", "15"}};
    struct contatto_t contatto2 = {"boscaini", "maurizio", 333, "maurizio.boscaini@univr.it", 2, {"Verona", 37134, "VR", "strada le grazie", "15"}};
    struct contatto_t contatto3 = {"quintarelli", "elisa", 333, "elisa.quintarelli@univr.it", GRUPPO_COLLEGHI, {"Verona", 37134, "VR", "strada le grazie", "15"}};
	
	//inserimento primo contatto
    printf("# Inserisco il nuovo contatto: \n");
    rubrica = inserisci(rubrica, contatto1);
    visualizza_rubrica(rubrica);
    printf("-------------------\n");
	printf("\n");
	
	//inserimento secondo contatto
    printf("# Inserisco il nuovo contatto: \n");
    visualizza_contatto(contatto2);
    rubrica = inserisci(rubrica, contatto2);
    visualizza_rubrica(rubrica);
    printf("-------------------\n");
    printf("\n");

	//inserimento terzo contatto
    printf("# Inserisco il nuovo contatto: \n");
    visualizza_contatto(contatto3);
    rubrica = inserisci(rubrica, contatto3);
    visualizza_rubrica(rubrica);
    printf("-------------------\n");
    printf("\n");
    
	//cerco un contatto
    struct contatto_t contattoR = {"quintarelli", "elisa"};
    printf("# Cerco il contatto: \n");
    visualizza_contatto(contattoR);

    int pos = cerca(rubrica, contattoR);
    
	//contatto trovato
    if (pos >= 0) {
        printf("# Cancello il contatto in posizione %d\n%s %s\n", pos, contattoR.cognome, contattoR.nome);
        printf("-------------------\n");

        rubrica = cancella(rubrica, pos);
        visualizza_rubrica(rubrica);
        printf("-------------------\n");
    }
    else {
        printf("# Contatto non trovato\n");
    }
	
	//cancello tutti i contatti rimanenti
    while (rubrica.dimensione > 0) {
        printf("# Cancello il contatto in posizione 0\n");
        visualizza_contatto(rubrica.contatti[0]);
        rubrica = cancella(rubrica, 0);
        printf("-------------------\n");
        visualizza_rubrica(rubrica);
        printf("-------------------\n");
    }

    return 0;
}
