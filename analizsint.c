//analizsint

#include "global.h"

struct entrada palsclave[]={ //palabras clave
	"div", DIV, //div
	"mod", MOD, //mod
	0,     0	//fin de palabras clave
};
int inic()
{
	struct entrada *p; //puntero a entrada
	for (p = palsclave; p->complex; p++){ //busca palabras clave
        inserta(p->aplex, p->complex); //inserta el lexema y el token en tabla de simbolos
    }
}