#include "rubrica.h"
#include "contatto.h"
#include "indirizzo.h"
#include <stdio.h>


//funzione per la ricerca di un contatto all'interno della rubrica
int cerca(struct rubrica_t rubrica, struct contatto_t contatto) {
    int posizione = 0;
    while (posizione < rubrica.dimensione && compare(rubrica.contatti[posizione], contatto) < 0) {
        posizione++;
    }
    if (posizione >= rubrica.dimensione) {
        return -1;
    }
    if (compare(rubrica.contatti[posizione], contatto) != 0) {
        return -1;
    }
    return posizione;
}

//funzione usata per l'inserimento in una posizone di un contatto
int in_posizione(struct rubrica_t rubrica, struct contatto_t contatto) {
    int posizione = 0;
    while (posizione < rubrica.dimensione && compare(rubrica.contatti[posizione], contatto) < 0) {
        posizione++;
    }
    return posizione;
}

//funzione per inserire un contatto nella rubrica
struct rubrica_t inserisci(struct rubrica_t rubrica, struct contatto_t contatto) {
	
	int posizione = 0;
	
	//controllo se posso aggiungere il contatto
    if (rubrica.dimensione + 1 < MAX_CONTATTI) {
        posizione = in_posizione(rubrica, contatto);
        printf("# inserisco in posizione %d\n", posizione);

		//sposto i contatti indietro di una posizione
        for (int i = rubrica.dimensione; i > posizione; i--) {
            rubrica.contatti[i] = rubrica.contatti[i - 1];
        }
	
		//aggiungo il contatto
        rubrica.contatti[posizione] = contatto;
        rubrica.dimensione++;
    }
    return rubrica;
}

//funzione per la cancellazione di un contatto dalla rubrica
struct rubrica_t cancella(struct rubrica_t rubrica, int posizione) {
	
	//controllo se la posizione data è valida
    if ((posizione >= 0) && (posizione < MAX_CONTATTI) && (posizione < rubrica.dimensione)) {
        
        //sposto i contatti in avanti di una posizione
        for (int i = posizione; i < rubrica.dimensione - 1; i++) {
            rubrica.contatti[i] = rubrica.contatti[i + 1];
        }
        rubrica.dimensione--;
    }
    return rubrica;
};

//visualizzo la rubrica
void visualizza_rubrica(struct rubrica_t rubrica) {
	printf("Numero di contatti %d\n", rubrica.dimensione);
	
	if(rubrica.dimensione == 0){
		printf("Non sono ancora stati aggiunti contatti!!\n");
		
	}
	else{
		printf("Ecco i contatti: \n");
		
		//stampo i contatti uno ad uno
		for (int i = 0; i < rubrica.dimensione; i++) {
			visualizza_contatto(rubrica.contatti[i]);
		}
		printf("\n");
	}   
}
