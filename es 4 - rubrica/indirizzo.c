#include "contatto.h"

/*
 * Salva i dati dell'indirizzo specificato su un file di testo utilizzando il separatore indicato
 */
void save_indirizzo(FILE *fp, struct indirizzo_t indirizzo, char sep) {
    fprintf(fp, "%s%c%d%c%s%c%s%c%s",
            indirizzo.citta, sep,
            indirizzo.cap, sep,
            indirizzo.provincia, sep,
            indirizzo.via, sep,
            indirizzo.civico);
}
