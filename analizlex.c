//analizlex.c

#include "global.h"
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