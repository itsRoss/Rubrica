//file header per indirizzo
#ifndef INDIRIZZO_H
#define INDIRIZZO_H

struct indirizzo_t{
	char citta[256];
	int cap;
	char provincia[256];
	char via[256];
	char civico[256];
};

//dichiarazioen funzione per il salvataggio indirizzo su file
void save_indirizzo(FILE *fp, struct indirizzo_t indirizzo, char sep);

#endif
