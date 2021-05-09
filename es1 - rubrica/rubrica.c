#include "rubrica.h"
#include "indirizzo.h"
#include "contatto.h"
#include <stdio.h>

//funzione per scambiare due contatti nel caso in cui non siano in ordine
void swap(struct contatto_t contatti[], int i, int j) {
    struct contatto_t tmp = contatti[i];
    contatti[i] = contatti[j];
    contatti[j] = tmp;
}

//funzione che ordina la rubrica usando un bubble sort
struct rubrica_t ordina(struct rubrica_t rubrica) {
  	
  	//itero per il numero di elementi all'interno della rubrica
    for (int i = 0; i < rubrica.dimensione - 1; i++) {
    	//comincio il controllo degli elementi
        for (int j = i + 1; j < rubrica.dimensione; j++) {
        	//se due contatti non sono in ordine li scambio
            if (compare(rubrica.contatti[j], rubrica.contatti[i]) < 0) {
                swap(rubrica.contatti, i, j);
            }
        }
    }
    return rubrica;
}

//funzione per la ricerca di un contatto all'interno della rubrica
int cerca(struct rubrica_t rubrica, struct contatto_t contatto) {
	//dichiaro la posizione iniziale
    int posizione = 0;

    //itero finche non arrivo in fondo alla rubrica o finche non trovo la posizione ricercata
    while ((posizione < rubrica.dimensione) && (compare(rubrica.contatti[posizione], contatto) < 0)) {
        posizione++;
    }

    //caso in cui sono arrivato in fondo alla rubrica
    if (posizione >= rubrica.dimensione) {

    	//contatto non trovato
        return -1;
    }

    //caso in cui non trovo il contatto
    if (compare(rubrica.contatti[posizione], contatto) != 0) {

    	//contatto non trovato
        return -1;
    }

    //ritorno la posizione del contatto richiesto
    return posizione;
}

//funzione per l'inserimento di un contatto all'interno della rubrica
struct rubrica_t inserisci(struct rubrica_t rubrica, struct contatto_t contatto) {

	//controllo se posso aggiungere un contatto
    if (rubrica.dimensione + 1 < MAX_CONTATTI) {

    	//aggiungo il contatto
        rubrica.contatti[rubrica.dimensione] = contatto;
        rubrica.dimensione++;

        //ordino la rubrica
        ordina(rubrica);

        return rubrica;
    }
    else{
    	//stampo messaggio di errore
    	printf("Limite di contati raggiunto\n");
    }
    return rubrica;
}

//funzione per la rimozione di un contatto dalla rubrica
struct rubrica_t cancella(struct rubrica_t rubrica, int posizione) {

	//controllo che non si cerchi di elminare un contatto in una posizione che non esiste
    if ((posizione >= 0) && (posizione < MAX_CONTATTI) && (posizione < rubrica.dimensione)) {
 	
 		//sposto i conatti indietro di una posizione
        for (int i = posizione; i < rubrica.dimensione - 1; i++) {
            rubrica.contatti[i] = rubrica.contatti[i + 1];
        }
        rubrica.dimensione--;
    }
    return rubrica;
}

//funzione per la visualizzazione della rubrica
void visualizza_rubrica(struct rubrica_t rubrica) {

	//welcome rubrica
	printf("------------------\n");
	printf("\n");
	//stampo numero di conattti
    printf("Numero di contatti %d\n", rubrica.dimensione);
    
    printf("Ecco i contatti: \n");

    //messaggio in caso in cui non ci siano contatti
    if( rubrica.dimensione == 0){
    	printf("Non sono ancora stati aggiunti contatti!\n");
    	printf("\n");

    }
    else{
    	//stampo i contatti singolarmente
	    for (int i = 0; i < rubrica.dimensione; i++) {
	        visualizza_contatto(rubrica.contatti[i]);
	    }
	    printf("\n");
    }
    
    
}
