#include <stdio.h>

#include "rubrica.h"

struct rubrica_t rubrica;

int main_get_contatto();
void main_inserisci();
void main_cancella();
void main_modifica();
void main_visualizza_contatto();
void main_visualizza_rubrica();

int main() {
    rubrica.dimensione = 0;
    printf("Benvenuto nel programma di gestione rubrica\n");
    int scelta = 1;

    while (scelta > 0) {
        printf("Scegliere una operazione\n");
        printf("\tInserisci contatto  (1)\n");
        printf("\tCancella contatto   (2)\n");
        printf("\tModifica contatto   (3)\n");
        printf("\tVisualizza contatto (4)\n");
        printf("\tVisualizza rubrica  (5)\n");
        printf("\tEsci                (6)\n");

        scanf("%i", &scelta);

        switch (scelta) {
            case 1:
                main_inserisci();
                break;
            case 2:
                main_cancella();
                break;
            case 3:
                main_modifica();
                break;
            case 4:
                main_visualizza_contatto();
                break;
            case 5:
                main_visualizza_rubrica();
                break;
            case 6:
                scelta = -1;
                break;
            default:
                scelta = 7;
                break;
        };
    }

    printf("Arrivederci\n");
    return 0;
}

int main_get_contatto() {
    char cognome[256];
    char nome[256];
    printf("Inserire cognome del contatto:\n");
    scanf("%256s", cognome);
    printf("Inserire nome del contatto:\n");
    scanf("%256s", nome);

    struct contatto_t contatto;
    strcpy(contatto.cognome, cognome);
    strcpy(contatto.nome, nome);

    int pos = cerca(rubrica, contatto);
    return pos;
}

void main_inserisci() {
    char cognome[256];
    char nome[256];
    int telefono;
    char email[256];
    char gruppo[256];
    char citta[256];
    int cap;
    char provincia[256];
    char via[256];
    char civico[256];

    printf("Inserire cognome: ");
    scanf("%256s", cognome);
    printf("Inserire nome: ");
    scanf("%256s", nome);
    printf("Inserire telefono: ");
    scanf("%i", &telefono);
    printf("Inserire email: ");
    scanf("%256s", email);
    printf("Inserire gruppo: ");
    scanf("%256s", gruppo);
    printf("Inserire citta': ");
    scanf("%256s", citta);
    printf("Inserire CAP: ");
    scanf("%i", &cap);
    printf("Inserire provincia: ");
    scanf("%256s", provincia);
    printf("Inserire via: ");
    scanf("%256s", via);
    printf("Inserire numero civico: ");
    scanf("%256s", civico);

    struct contatto_t contatto;
    strcpy(contatto.cognome, cognome);
    strcpy(contatto.nome, nome);
    contatto.telefono = telefono;
    strcpy(contatto.email, email);
    strcpy(contatto.gruppo, gruppo);
    struct indirizzo_t indirizzo;
    strcpy(indirizzo.citta, citta);
    indirizzo.cap = cap;
    strcpy(indirizzo.provincia, provincia);
    strcpy(indirizzo.via, via);
    strcpy(indirizzo.civico, civico);
    contatto.indirizzo = indirizzo;

    printf("Informazioni nuovo contatto:\n");
    visualizza_contatto(contatto);
    printf("\n\n");

    printf("Continuare con l'operazione? (y) ");
    char c;
    scanf(" %c", &c);
    if (c == 'y') {
        rubrica = inserisci(rubrica, contatto);
    } else {
        printf("Operazione annullata\n");
    }
}

void main_cancella() {
    int pos = main_get_contatto();
    if (pos < 0) {
        printf("Contatto non esistente\n");
    } else {
        rubrica = cancella(rubrica, pos);
    }
}

void main_modifica() {
    int pos = main_get_contatto();
    if (pos < 0) {
        printf("Contatto non esistente\n");
    } else {
        printf("Modifia del contatto:\n");
        visualizza_contatto(rubrica.contatti[pos]);
        printf("\n");

        char cognome[256];
        char nome[256];
        int telefono;
        char email[256];
        char gruppo[256];
        char citta[256];
        int cap;
        char provincia[256];
        char via[256];
        char civico[256];

        printf("Inserire cognome: ");
        scanf("%256s", cognome);
        printf("Inserire nome: ");
        scanf("%256s", nome);
        printf("Inserire telefono: ");
        scanf("%i", &telefono);
        printf("Inserire email: ");
        scanf("%256s", email);
        printf("Inserire gruppo: ");
        scanf("%256s", gruppo);
        printf("Inserire citta': ");
        scanf("%256s", citta);
        printf("Inserire CAP: ");
        scanf("%i", &cap);
        printf("Inserire provincia: ");
        scanf("%256s", provincia);
        printf("Inserire via: ");
        scanf("%256s", via);
        printf("Inserire numero civico: ");
        scanf("%256s", civico);

        struct contatto_t contatto;
        strcpy(contatto.cognome, cognome);
        strcpy(contatto.nome, nome);
        contatto.telefono = telefono;
        strcpy(contatto.email, email);
        strcpy(contatto.gruppo, gruppo);
        struct indirizzo_t indirizzo;
        strcpy(indirizzo.citta, citta);
        indirizzo.cap = cap;
        strcpy(indirizzo.provincia, provincia);
        strcpy(indirizzo.via, via);
        strcpy(indirizzo.civico, civico);
        contatto.indirizzo = indirizzo;

        printf("Informazioni nuovo contatto:\n");
        visualizza_contatto(contatto);
        printf("\n\n");

        printf("Continuare con l'operazione? (y) ");
        char c;
        scanf(" %c", &c);
        if (c == 'y') {
            rubrica = cancella(rubrica, pos);
            rubrica = inserisci(rubrica, contatto);
        } else {
            printf("Operazione annullata\n");
        }
    }
}

void main_visualizza_contatto() {
    int pos = main_get_contatto();

    if (pos < 0) {
        printf("Contatto non esistente\n");
    } else {
        visualizza_contatto(rubrica.contatti[pos]);
    }
}

void main_visualizza_rubrica() {
    visualizza_rubrica(rubrica);
}
