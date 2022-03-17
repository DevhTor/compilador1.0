
#include "global.h"
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "error.c"


char lexemas[MAXLEX];
int ultcar = -1; // ultimo caracter
struct entrada tablasimb[MAXLEX];
int ultent = 0; //ultima entrada
int preanalisis;

int busca(char s[])
{
	int p;
	for (p = ultent; p > 0; p = p - 1)
		if (strcmp(tablasimb[p].aplex, s) == 0)
			return p;
	return 0;
}
int inserta(s,clex) //inserta en tabla de simbolos

char s[]; //parametro lexema
int clex; //parametro codigo lexico
{
    int lon; //longitud del lexema
    lon = strlen(s)	; //longitud del lexema
    if (ultent + 1 >= MAXSIMN) //tabla llena
        error("tabla de simbolo llena"); //error
    if (ultcar + lon + 1 >= MAXLEX) //tabla llena
        error("matriz de lexemas llena"); //error
    ultent++; //incrementa ultima entrada
    tablasimb[ultent].complex = clex; //asigna codigo lexico a tabla de simbolos
    tablasimb[ultent].aplex = &lexemas[ultcar + 1]; //asigna lexema a tabla de simbolos
    ultcar = ultcar + lon + 1; //incrementa ultimo caracter
    strcpy(tablasimb[ultent].aplex, s); //copia lexema
    return ultent; //devuelve posicion de entrada
}



