#include "rubrica.h"
#include "contatto.h"
#include "indirizzo.h"
#include <stdio.h>
#include <string.h>

//funzione per la ricerca di un contatto tramite una chiave
int cerca(struct rubrica_t rubrica, char chiave[]) {
    int posizione = 0;
    
    //cerco il contatto con la chiave
    while ((posizione < rubrica.dimensione) && (strcmp(rubrica.elementi[posizione].chiave, chiave) < 0)) {
        posizione++;
    }
    
    //caso in cui sia arrivato in fondo alla rubrica
    if (posizione >= rubrica.dimensione) {
        return -1;
    }
    
    //caso in cui non trovo l'elemento
    if (strcmp(rubrica.elementi[posizione].chiave, chiave) != 0) {
        return -1;
    }
    return posizione;
}

//funzioni per estrarre un contatto dalla rubrica
struct contatto_t get_contatto(struct rubrica_t rubrica, char chiave[]) {
	
	//trvo l aposizone del contatto
    int pos = cerca(rubrica, chiave);
    
    //ritrono il contatto trovato
    if (pos >= 0) {
        return rubrica.elementi[pos].valore;
    }
    else {
        struct contatto_t vuoto;
        return vuoto;
    }
}

//inserimento di un contatto nella rubrica tramite la chiave
struct rubrica_t inserisci(struct rubrica_t rubrica, char chiave[], struct contatto_t contatto) {
	
	//trovo la posizione a cui va inserito
    int posizione = 0;
    while (posizione < rubrica.dimensione && strcmp(rubrica.elementi[posizione].chiave, chiave) < 0) {
        posizione++;
    }
    
    //caso in cui si debba aggiungere il contatto in coda
    if (posizione >= rubrica.dimensione) {
		
        //inserisci nuovo contatto, in coda
        if (rubrica.dimensione + 1 < MAX_CONTATTI) {
            strcpy(rubrica.elementi[posizione].chiave, chiave);
            rubrica.elementi[posizione].valore = contatto;
            rubrica.dimensione++;
        }
    }
	
	//caso in cui si debba inserire il contatto in mezzo alla rubrica
    else if (strcmp(rubrica.elementi[posizione].chiave, chiave) != 0) {
		
        //inserisci nuovo contatto, nel mezzo
        if (rubrica.dimensione + 1 < MAX_CONTATTI) {
			
			//sposto i contatti indietro di una posizone
            for (int i = rubrica.dimensione; i > posizione; i--) {
                rubrica.elementi[i] = rubrica.elementi[i - 1];
            }
			
			//inserimento del contatto
            strcpy(rubrica.elementi[posizione].chiave, chiave);
            rubrica.elementi[posizione].valore = contatto;
            rubrica.dimensione++;
        }
    }
    else {
        //sovrascrivi contatto esistente
        rubrica.elementi[posizione].valore = contatto;
    }

    return rubrica;
}

//cancellazione di un contatto dalla rubrica
struct rubrica_t cancella(struct rubrica_t rubrica, char chiave[]) {
    int posizione = 0;
    
    //trovo la posizone del contatto
    while (posizione < rubrica.dimensione && strcmp(rubrica.elementi[posizione].chiave, chiave) < 0) {
        posizione++;
    }
    //sposto i contatti in avanti di uno
    if (posizione < rubrica.dimensione) {
        for (int i = posizione; i < rubrica.dimensione - 1; i++) {
            rubrica.elementi[i] = rubrica.elementi[i + 1];
        }
        rubrica.dimensione--;
    }
    return rubrica;
}

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
			printf("\n");
			printf("# chiave %s\n", rubrica.elementi[i].chiave);
			printf("\n");
			visualizza_contatto(rubrica.elementi[i].valore);
		}
	}
    printf("\n");
}
