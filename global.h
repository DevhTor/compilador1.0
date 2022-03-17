#ifndef GLOBAL_H
#define GLOBAL_H
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define TAMBUFF 128
#define NINGUNO  -1
#define FDC     '\0'

#define NUM     256
#define DIV     257
#define MOD     258
#define ID      259
#define FIN     260
#define MAXLEX	999
#define MAXSIMN	100



void analsint();
extern int valcomplex;
extern int numlinea;

struct entrada {
	
	char *aplex;
	int complex;
};

extern struct entrada tablasimb[999];

int inic();
int error(char *);
int analex();
int busca(char []);
int inserta(char [],int);
void expr();
void termino();
void factor();
void parea(int);
void emite(int, int);
#endif