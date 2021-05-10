#include <stdio.h>
#include "contatto.h"
#include "rubrica.h"

int main() {
    struct rubrica_t rubrica;
    rubrica.dimensione = 0;
    
    //inizio programma
    printf("-------------------\n");
    printf("Benvenuto nella tua rubrica\n");
    printf("-------------------\n");
    printf("\n");
    
    //visualizzo rubrica
    visualizza_rubrica(rubrica);
    printf("-------------------\n");

	//dichiaro i tre contatti
    struct contatto_t contatto1 = {"bombieri", "nicola", 333, "nicola.bombieri@univr.it", 2, {"Verona", 37134, "VR", "strada le grazie", "15"}};
    struct contatto_t contatto2 = {"boscaini", "maurizio", 333, "maurizio.boscaini@univr.it", COLLEGHI, {"Verona", 37134, "VR", "strada le grazie", "15"}};
    struct contatto_t contatto3 = {"quintarelli", "elisa", 333, "elisa.quintarelli@univr.it", COLLEGHI, {"Verona", 37134, "VR", "strada le grazie", "15"}};

	//inserimento primo contatto
    printf("# Inserisco il nuovo contatto: \n");
    rubrica = inserisci(rubrica, "bombieri nicola", contatto1);
    visualizza_rubrica(rubrica);
    printf("-------------------\n");

	//inserimento secondo contatto
    printf("# Inserisco il nuovo contatto: \n");
    visualizza_contatto(contatto2);
    rubrica = inserisci(rubrica, "boscaini maurizio", contatto2);
    visualizza_rubrica(rubrica);
    printf("-------------------\n");

	//inserimento terzo contatto
    printf("# Inserisco il nuovo contatto: \n");
    visualizza_contatto(contatto3);
    rubrica = inserisci(rubrica, "quintarelli elisa", contatto3);
    visualizza_rubrica(rubrica);
    printf("-------------------\n");

	//cerco un contatto
    int pos = cerca(rubrica, "quintarelli elisa");
	
	//cancello il contatto trovato
    if (pos >= 0) {
        printf("# Cancello il contatto in posizione %d\n", pos);
        printf("-------------------\n");

        rubrica = cancella(rubrica, "quintarelli elisa");
        visualizza_rubrica(rubrica);
        printf("-------------------\n");
    }
    else {
        printf("# Contatto non trovato\n");
    }
	
	//cancello i rimanenti contatti
    while (rubrica.dimensione > 0) {
        printf("# Cancello il contatto in posizione 0\n");
        printf("\n");
        printf("chiave %s", rubrica.elementi[0].chiave);
        printf("\n");
        visualizza_contatto(rubrica.elementi[0].valore);
        rubrica = cancella(rubrica, rubrica.elementi[0].chiave);
        visualizza_rubrica(rubrica);
        printf("-------------------\n");
    }

    return 0;
}
