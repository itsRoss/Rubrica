#include "util.h"

/*
 * Copia in field i caratteri della stringa s a partire da index fino a sep o alla fine di s,
 * ritornando il numero dei caratteri copiati.
 */
int next_token(char s[], int index, char field[], char sep) {
    int i = 0;

    while (s[index] && s[index] != sep) {
        field[i++] = s[index++];
    }

    field[i] = '\0';
    index++;
    return index;
}
