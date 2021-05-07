#include <stdio.h>

#include "rubrica.h"

int main() {
    struct rubrica_t rubrica;
    rubrica.dimensione = 0;
    visualizza_rubrica(rubrica);
    printf("-------------------\n");

    struct contatto_t contatto1 = {"quintarelli", "elisa", 333, "elisa.quintarelli@univr.it", "colleghi", {"Verona", 37134, "VR", "strada le grazie", "15"}};
    struct contatto_t contatto2 = {"bombieri", "nicola", 333, "nicola.bombieri@univr.it", "colleghi", {"Verona", 37134, "VR", "strada le grazie", "15"}};
    struct contatto_t contatto3 = {"boscaini", "maurizio", 333, "maurizio.boscaini@univr.it", "colleghi", {"Verona", 37134, "VR", "strada le grazie", "15"}};

    printf("# Inserisco il nuovo contatto: \n");
    rubrica = inserisci(rubrica, contatto1);
    visualizza_rubrica(rubrica);
    printf("-------------------\n");

    printf("# Inserisco il nuovo contatto: \n");
    visualizza_contatto(contatto2);
    rubrica = inserisci(rubrica, contatto2);
    visualizza_rubrica(rubrica);
    printf("-------------------\n");

    printf("# Inserisco il nuovo contatto: \n");
    visualizza_contatto(contatto3);
    rubrica = inserisci(rubrica, contatto3);
    visualizza_rubrica(rubrica);
    printf("-------------------\n");

    struct contatto_t contattoR = {"quintarelli", "elisa"};
    printf("# Cerco il contatto: \n");
    visualizza_contatto(contattoR);

    int pos = cerca(rubrica, contattoR);

    if (pos >= 0) {
        printf("# Cancello il contatto in posizione %d\n%s %s\n", pos, contattoR.cognome, contattoR.nome);
        printf("-------------------\n");

        rubrica = cancella(rubrica, pos);
        visualizza_rubrica(rubrica);
        printf("-------------------\n");
    } else {
        printf("# Contatto non trovato\n");
    }

    while (rubrica.dimensione > 0) {
        printf("# Cancello il contatto in posizione 0\n");
        visualizza_contatto(rubrica.contatti[0]);
        rubrica = cancella(rubrica, 0);
        visualizza_rubrica(rubrica);
        printf("-------------------\n");
    }

    return 0;
}
