#include <stdio.h>
#include "rubrica.h"

int main() {
	//dichiaro struttra rubrica
    struct rubrica_t rubrica;

    //welcome section
    printf("\n");
    printf("-------------------\n");
    printf("Benvenuto nella tua rubrica!\n");
    printf("-------------------\n");

    //setto al dimensione iniziale a zero
    rubrica.dimensione = 0;

    visualizza_rubrica(rubrica);

    printf("-------------------\n");
    printf("\n");
    
    //creo 3 contatti della mia rubrica
    struct contatto_t contatto1 = {"quintarelli", "elisa", 333, "elisa.quintarelli@univr.it", "colleghi", {"Verona", 37134, "VR", "strada le grazie", "15"}};
    struct contatto_t contatto2 = {"bombieri", "nicola", 333, "nicola.bombieri@univr.it", "colleghi", {"Verona", 37134, "VR", "strada le grazie", "15"}};
    struct contatto_t contatto3 = {"boscaini", "maurizio", 333, "maurizio.boscaini@univr.it", "colleghi", {"Verona", 37134, "VR", "strada le grazie", "15"}};


   	//comunicazione inserimento del primo contatto
    printf("# Inserisco il nuovo contatto: \n");

    //inserimento
    rubrica = inserisci(rubrica, contatto1);

    //visualizzazione rubrica
    visualizza_rubrica(rubrica);
    printf("-------------------\n");

    //comunicazione inserimento del seondo contatto
    printf("# Inserisco il nuovo contatto: \n");

    //inserimento contatto
    visualizza_contatto(contatto2);
    rubrica = inserisci(rubrica, contatto2);

    //visualizzazione rubrica
    visualizza_rubrica(rubrica);
    printf("-------------------\n");

    //comunicazione inserimento del terzo contatto
    printf("# Inserisco il nuovo contatto: \n");

    //inserimento contatto
    visualizza_contatto(contatto3);
    rubrica = inserisci(rubrica, contatto3);

    //visualizzazione rubrica
    visualizza_rubrica(rubrica);
    printf("-------------------\n");

    //dichiaro un contatto da cercare
    struct contatto_t contattoR = {"quintarelli", "elisa"};

    //visualizzo il contatto da cercare
    printf("# Cerco il contatto: \n");
    visualizza_contatto(contattoR);

    //cerco il contatto
    int pos = cerca(rubrica, contattoR);


   	//caso in cui il contatto sia stato trovato
    if (pos >= 0) {

    	//cancellazione contato
        printf("# Cancello il contatto in posizione %d\n%s %s\n", pos, contattoR.cognome, contattoR.nome);
        printf("-------------------\n");

        //cancellazione
        rubrica = cancella(rubrica, pos);

        //visualizzo la rubrica
        visualizza_rubrica(rubrica);
        printf("-------------------\n");

    }
    else {
    	//contatto non trovato
        printf("# Contatto non trovato\n");
    }


    //cancello tutti i contatti della rubrica
    while (rubrica.dimensione > 0) {

    	//messaggio cancellazione
        printf("# Cancello il contatto in posizione 0\n");
        
        //visualizzo contatto da cancellare
        visualizza_contatto(rubrica.contatti[0]);

        //cancellazione
        rubrica = cancella(rubrica, 0);

        //visualizzo rubrica
        visualizza_rubrica(rubrica);
        printf("-------------------\n");
    }

    return 0;
}
