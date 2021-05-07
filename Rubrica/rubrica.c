#include "rubrica.h"

#include <stdio.h>

#include "contatto.h"
#include "indirizzo.h"

void swap(struct contatto_t contatti[], int i, int j) {
    struct contatto_t tmp = contatti[i];
    contatti[i] = contatti[j];
    contatti[j] = tmp;
}

struct rubrica_t ordina(struct rubrica_t rubrica) {
    int i, j;
    for (i = 0; i < rubrica.dimensione - 1; i++) {
        for (j = i + 1; j < rubrica.dimensione; j++) {
            if (compare(rubrica.contatti[j], rubrica.contatti[i]) < 0) {
                swap(rubrica.contatti, i, j);
            }
        }
    }
    return rubrica;
}

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

int cerca_binary_search(struct rubrica_t rubrica, struct contatto_t contatto) {
    int posizione = -1;
    if (rubrica.dimensione > 0) {
        int i = 0;
        int j = rubrica.dimensione - 1;
        int m = (i + j) / 2;
        
        while (i <= j) {
            if (compare(rubrica.contatti[m], contatto) < 0) {
                i = m + 1;
            } else if (compare(rubrica.contatti[m], contatto) == 0) {
                posizione = m;
                break;
            } else {
                j = m - 1;
            }
            m = (i + j) / 2;
        }
        if (j < i) {
            posizione = -1;
        }
    }
    return posizione;
}

int cerca_recursive_binary_search_(struct rubrica_t rubrica, struct contatto_t contatto, int i, int j) {
    if (i <= j) {
        int m = (i + j) / 2;
        if (compare(rubrica.contatti[m], contatto) == 0) {
            return m;
        } else if (compare(rubrica.contatti[m], contatto) < 0) {
            //i = m + 1;
            return cerca_recursive_binary_search_(rubrica, contatto, m + 1, j);
        } else {
            //j = m - 1;
            return cerca_recursive_binary_search_(rubrica, contatto, i, m - 1);
        }
    }
    //	else if(i == j){
    //		if(compare(rubrica.contatti[i], contatto) == 0){
    //			return i;
    //		}
    //		else{
    //			return -1;
    //		}
    //	}
    else {
        return -1;
    }
}

int cerca_recursive_binary_search(struct rubrica_t rubrica, struct contatto_t contatto) {
    if (rubrica.dimensione > 0) {
        return cerca_recursive_binary_search_(rubrica, contatto, 0, rubrica.dimensione - 1);
    }
    return -1;
}

struct rubrica_t inserisci(struct rubrica_t rubrica, struct contatto_t contatto) {
    if (rubrica.dimensione + 1 < MAX_CONTATTI) {
        rubrica.contatti[rubrica.dimensione] = contatto;
        rubrica.dimensione++;
        return ordina(rubrica);
    }
    return rubrica;
}

struct rubrica_t cancella(struct rubrica_t rubrica, int posizione) {
    if (posizione >= 0 && posizione < MAX_CONTATTI && posizione < rubrica.dimensione) {
        int i;
        for (i = posizione; i < rubrica.dimensione - 1; i++) {
            rubrica.contatti[i] = rubrica.contatti[i + 1];
        }
        rubrica.dimensione--;
    }
    return rubrica;
}

void visualizza_rubrica(struct rubrica_t rubrica) {
    printf("Numero di contatti %d\n", rubrica.dimensione);
    int i;
    for (i = 0; i < rubrica.dimensione; i++) {
        visualizza_contatto(rubrica.contatti[i]);
    }
    printf("\n");
}
