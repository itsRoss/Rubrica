//definizione file header per indirizzo
#ifndef INDIRIZZO_H
#define INDIRIZZO_H

//dichiarazione struttura indirizzo
struct indirizzo_t {
    char citta[256];
    int cap;
    char provincia[256];
    char via[256];
    char civico[256];
};

#endif
