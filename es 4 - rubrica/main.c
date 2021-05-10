#include <stdio.h>

#include "contatto.h"
#include "rubrica.h"

struct rubrica_t dump_rubrica(struct rubrica_t rubrica);
void test_rubrica(struct rubrica_t rubrica);

int main() {
    char filename[] = "rubrica.csv";
    struct rubrica_t rubrica;
    printf("Dimensione rubrica in byte: %li\n\n", sizeof(rubrica));

    //rubrica = dump_rubrica(rubrica);
    //save_rubrica(rubrica, filename);

    load_rubrica(&rubrica, filename);
    visualizza_rubrica(rubrica);
}

struct rubrica_t dump_rubrica(struct rubrica_t rubrica) {
    rubrica.dimensione = 0;
    struct contatto_t contatto1 = {"bombieri", "nicola", 333, "nicola.bombieri@univr.it", 2, {"Verona", 37134, "VR", "strada le grazie", "15"}};
    struct contatto_t contatto2 = {"boscaini", "maurizio", 333, "maurizio.boscaini@univr.it", COLLEGHI, {"Verona", 37134, "VR", "strada le grazie", "15"}};
    struct contatto_t contatto3 = {"quintarelli", "elisa", 333, "elisa.quintarelli@univr.it", COLLEGHI, {"Verona", 37134, "VR", "strada le grazie", "15"}};

    rubrica = inserisci(rubrica, "bombieri nicola", contatto1);
    rubrica = inserisci(rubrica, "boscaini maurizio", contatto2);
    rubrica = inserisci(rubrica, "quintarelli elisa", contatto3);

    return rubrica;
}

void test_rubrica(struct rubrica_t rubrica) {
    rubrica.dimensione = 0;
    visualizza_rubrica(rubrica);
    printf("-------------------\n\n");

    struct contatto_t contatto1 = {"bombieri", "nicola", 333, "nicola.bombieri@univr.it", 2, {"Verona", 37134, "VR", "strada le grazie", "15"}};
    struct contatto_t contatto2 = {"boscaini", "maurizio", 333, "maurizio.boscaini@univr.it", COLLEGHI, {"Verona", 37134, "VR", "strada le grazie", "15"}};
    struct contatto_t contatto3 = {"quintarelli", "elisa", 333, "elisa.quintarelli@univr.it", COLLEGHI, {"Verona", 37134, "VR", "strada le grazie", "15"}};

    printf("# Inserisco il nuovo contatto: \n");
    rubrica = inserisci(rubrica, "bombieri nicola", contatto1);
    visualizza_rubrica(rubrica);
    printf("-------------------\n\n");

    printf("# Inserisco il nuovo contatto: \n");
    visualizza_contatto(contatto2);
    rubrica = inserisci(rubrica, "boscaini maurizio", contatto2);
    visualizza_rubrica(rubrica);
    printf("-------------------\n\n");

    printf("# Inserisco il nuovo contatto: \n");
    visualizza_contatto(contatto3);
    rubrica = inserisci(rubrica, "quintarelli elisa", contatto3);
    visualizza_rubrica(rubrica);
    printf("-------------------\n\n");

    int pos = cerca(rubrica, "quintarelli elisa");

    if (pos >= 0) {
        printf("# Cancello il contatto in posizione %d\n", pos);
        printf("-------------------\n\n");

        rubrica = cancella(rubrica, "quintarelli elisa");
        visualizza_rubrica(rubrica);
        printf("-------------------\n\n");
    } else {
        printf("# Contatto non trovato\n");
    }

    while (rubrica.dimensione > 0) {
        printf("# Cancello il contatto in posizione 0\n");
        printf("chiave %s", rubrica.elementi[0].chiave);
        visualizza_contatto(rubrica.elementi[0].valore);
        rubrica = cancella(rubrica, rubrica.elementi[0].chiave);
        visualizza_rubrica(rubrica);
        printf("-------------------\n\n");
    }
}
