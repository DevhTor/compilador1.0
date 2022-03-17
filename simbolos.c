
#include "global.h"
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "error.c"


char lexemas[MAXLEX];
int ultcar = -1;
struct entrada tablasimb[MAXLEX];
int ultent = 0;
int preanalisis;

int busca(char s[])
{
	int p;
	for (p = ultent; p > 0; p = p - 1)
		if (strcmp(tablasimb[p].aplex, s) == 0)
			return p;
	return 0;
}
int inserta(s,clex)

char s[];
int clex;
{
    int lon;
    lon = strlen(s)	;
    if (ultent + 1 >= MAXSIMN)
        error("tabla de simbolo llena");
    if (ultcar + lon + 1 >= MAXLEX)
        error("matriz de lexemas llena");
    ultent = ultent + 1;
    tablasimb[ultent].complex = clex;
    tablasimb[ultent].aplex = &lexemas[ultcar + 1];
    ultcar = ultcar + lon + 1;
    strcpy(tablasimb[ultent].aplex, s);
    return ultent;
}





//analizlex.c

//#include "error.c"

char buflex[TAMBUFF];
int numlinea = 1;
int valcomplex= NINGUNO;

int analex()
{ 
	int t;
	while(1) {
		t = getchar();
		if (t == ' '|| t == '\t')
			;				
		else if (t== '\n')
			numlinea = numlinea + 1;
			else if (isdigit(t)) {
					ungetc(t, stdin);
					scanf("%d", &valcomplex);
					return NUM;
				}
				else if(isalpha(t)) {
					int p, b = 0;
					while (isalnum (t)) {
						buflex[b] = t;
						t = getchar();
						b = b + 1;
						if (b >= TAMBUFF)
							error("ERROR DE COMPILADOR");
					}
					buflex[b] = FDC;
					if (t != EOF)
						ungetc(t, stdin);
					p = busca(buflex);
					if (p == 0)
						p = inserta(buflex, ID);
					valcomplex = p;
					return tablasimb[p].complex;
				}
				else if (t == EOF)
					return FIN;
				else {
					valcomplex = NINGUNO;
					return t;
				}
	}
}




//analsint

#include "emisor.c"
//#include "error.c"

void analsint() {
	
	preanalisis = analex();
	while (preanalisis != FIN) {
		expr();
        parea(';');
	}
}

void expr(){
	int t;
	termino();
	while(1)
		switch (preanalisis) {
			case '+': case '-':
				t = preanalisis;
				parea (preanalisis);
				termino();
				continue;
			default:
				return;
		}
}

void termino() {
	int t;
	factor();
	while(1)
		switch (preanalisis) {
			case '*': case '/': case DIV: case MOD:
				t = preanalisis;
				parea (preanalisis); factor(); emite(t, NINGUNO);
				continue;
			default:
				return;
		}	
}

void factor(){
	switch(preanalisis) {
		case '(':
			parea ('(');
			expr();
			parea(')');
			break;
		case NUM:
			emite(NUM, valcomplex);
			parea(NUM);
			break;
		case ID:
			emite(ID, valcomplex);
			parea(ID);
			break;
		default:
			error("Error de sintaxis");
	}
}
void parea(t)
int t;
{
	if (preanalisis == t){
		preanalisis = analex();
    }else{
        error("Error de sintanxis");
    }
}
