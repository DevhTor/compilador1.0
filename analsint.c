//analsint

#include "global.h"
#include "emisor.c"
//#include "error.c"
#include "analizlex.c"
#include "simbolos.c"

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
