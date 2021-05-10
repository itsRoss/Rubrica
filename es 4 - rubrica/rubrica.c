#include "rubrica.h"
#include "contatto.h"
#include "indirizzo.h"
#include "util.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//separatore elementi nel file
#define SEP ';'

//end of line
#define EOL '\n'

//line size
#define LINE_SIZE 1000

//funzione per la ricerca di un contatto
int cerca(struct rubrica_t rubrica, char chiave[]) {
    int posizione = 0;
	
	//trovo la posizione
    while (posizione < rubrica.dimensione && strcmp(rubrica.elementi[posizione].chiave, chiave) < 0) {
        posizione++;
    }
	
	//caso in cui sono arrivato in fondo alla rubrica
    if (posizione >= rubrica.dimensione) {
        return -1;
    }
	
	//contatto non trovato
    if (strcmp(rubrica.elementi[posizione].chiave, chiave) != 0) {
        return -1;
    }

    return posizione;
}

//funzione per estrarre un contatto
struct contatto_t get_contatto(struct rubrica_t rubrica, char chiave[]) {
    int pos = cerca(rubrica, chiave);
	
	//ritorno il contatto trovato
    if (pos >= 0) {
        return rubrica.elementi[pos].valore;
    }
    else {
        struct contatto_t vuoto;
        return vuoto;
    }
}

//funzione per l'inserimento di un contatto 
struct rubrica_t inserisci(struct rubrica_t rubrica, char chiave[], struct contatto_t contatto) {
    int posizione = 0;
    
    //trovo la posizione
    while (posizione < rubrica.dimensione && strcmp(rubrica.elementi[posizione].chiave, chiave) < 0) {
        posizione++;
    }
    //inserimento in coda
    if (posizione >= rubrica.dimensione) {
        // Inserisci nuovo contatto, in coda
        if (rubrica.dimensione + 1 < MAX_CONTATTI) {
            strcpy(rubrica.elementi[posizione].chiave, chiave);
            rubrica.elementi[posizione].valore = contatto;
            rubrica.dimensione++;
        }
    } 
    //inserimento in mezzo
    else if (strcmp(rubrica.elementi[posizione].chiave, chiave) != 0) {
        // Inserisci nuovo contatto, nel mezzo
        if (rubrica.dimensione + 1 < MAX_CONTATTI) {
            
            //sposto i contatti indietro di una posizione
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
        // Sovrascrivi contatto esistente
        rubrica.elementi[posizione].valore = contatto;
    }

    return rubrica;
}

//cancellazione di un contatto dalla rubrica
struct rubrica_t cancella(struct rubrica_t rubrica, char chiave[]) {
    int posizione = 0;
    
    //trovo la posizione
    while (posizione < rubrica.dimensione && strcmp(rubrica.elementi[posizione].chiave, chiave) < 0) {
        posizione++;
    }
    if (posizione < rubrica.dimensione) {
		
		//sposto gli elemnti in avanti di uno
        for (int i = posizione; i < rubrica.dimensione - 1; i++) {
            rubrica.elementi[i] = rubrica.elementi[i + 1];
        }
        rubrica.dimensione--;
    }
    return rubrica;
}

//visualizzo la rubrica intera
void visualizza_rubrica(struct rubrica_t rubrica) {
    printf("Numero di contatti %d\n", rubrica.dimensione);
    
    if(rubrica.dimensione == 0){
		printf("Non sono ancora stati aggiunti contatti!!\n");
		
	}
	else{
		printf("Ecco i contatti: \n");
  
		for (int i = 0; i < rubrica.dimensione; i++) {
			printf("#%s\n", rubrica.elementi[i].chiave);
			visualizza_contatto(rubrica.elementi[i].valore);
		}
		printf("\n");
	}
}

/*
 * Salva i dati degli elementi della rubrica specificata su un file di testo utilizzando il separatore SEP.
 */
void save_rubrica(struct rubrica_t rubrica, char filename[]) {
    int i;
    struct elemento_t elemento;
    
    //puntatore di tipo file che punta la file in cui scrivere
    FILE *fp = fopen(filename, "w");

	//messaggio salavataggio dei contatti
	printf("-------------------\n");
    printf("Salvataggio in corso di %d contatti...\n", rubrica.dimensione);
	printf("-------------------\n");
	printf("\n");
	
	//errore apertura del file
    if (fp == NULL) {
        printf("\nErrore di apertura del file: %s\n", filename);
        exit(1);
    }
    //scrittura ll'interno del file
    else {
        for (i = 0; i < rubrica.dimensione; i++) {
            elemento = rubrica.elementi[i];
            fprintf(fp, "%s%c", elemento.chiave, SEP);
            save_contatto(fp, elemento.valore, SEP);
            fprintf(fp, "%c", EOL);
        }
		
        fclose(fp);
        
        //messaggio di fine
        printf("-------------------\n");
        printf("Salvataggio completato\n\n");
        printf("-------------------\n");
        printf("\n");
    }
}

/*
 * Popola la rubrica specificata con gli elementi presenti su un file di testo, utilizzando il separatore indicato
 */
void load_rubrica(struct rubrica_t *rubrica, char filename[]) {
	//puntatore in lettura la file specificato
    FILE *fp = fopen(filename, "r");
    char line[LINE_SIZE];
    int count = 0;
    int index;
    char str[20];
	
	//messaggio di caricamento della rubrica
	printf("-------------------\n");
    printf("Caricamento in corso della rubrica");
	printf("-------------------\n");
	printf("\n");
	
	//messaggio di errore
    if (fp == NULL) {
        printf("\nErrore di apertura del file: %s\n", filename);
        exit(1);
    }
    //scrittura sulla rubrica
    else {
        struct elemento_t elemento;

        while (fgets(line, LINE_SIZE, fp)) {
            index = 0;
            index = next_token(line, index, elemento.chiave, SEP);
            index = next_token(line, index, elemento.valore.cognome, SEP);
            index = next_token(line, index, elemento.valore.nome, SEP);
            index = next_token(line, index, str, SEP);
            elemento.valore.telefono = atoi(str);
            index = next_token(line, index, str, SEP);
            elemento.valore.gruppo = atoi(str);
            index = next_token(line, index, elemento.valore.email, SEP);

            // Indirizzo
            index = next_token(line, index, elemento.valore.indirizzo.citta, SEP);
            index = next_token(line, index, str, SEP);
            elemento.valore.indirizzo.cap = atoi(str);
            index = next_token(line, index, elemento.valore.indirizzo.provincia, SEP);
            index = next_token(line, index, elemento.valore.indirizzo.via, SEP);
            index = next_token(line, index, elemento.valore.indirizzo.civico, SEP);
			
			//aggiornamento dimensione della rubrica
            rubrica->elementi[count] = elemento;
            count++;
        }

        rubrica->dimensione = count;
        fclose(fp);
		
		//messaggio di fine
		printf("-------------------\n");
        printf("\nCaricamento completato\n");
        printf("-------------------\n");
        printf("\n");
    }
}
