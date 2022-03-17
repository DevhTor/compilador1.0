// analizlex.c

#include "global.h"
//#include "error.c"

char buflex[TAMBUFF];
int numlinea = 1;
int valcomplex = NINGUNO;

int analex() // analizador lexico
{
	int t;	  // tipo de lexema
	while (1) // bucle infinito
	{
		t = getchar();
		// lee caracter
		if (t == ' ' || t == '\t') // si es espacio o tabulador
			;					   // no hace nada

		else if (t == '\n')			 // si es salto de linea
			numlinea = numlinea + 1; // incrementa numero de linea

		else if (isdigit(t)) // si es digito
		{
			ungetc(t, stdin);		  // devuelve caracter a la entrada
			scanf("%d", &valcomplex); // lee numero entero
			return NUM;				  // retorna NUM
		}
		else if (isalpha(t))
		{

			int p, b = 0;
			while (isalnum(t))
			{
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
		else
		{
			valcomplex = NINGUNO;
			return t;
		}
	}
}