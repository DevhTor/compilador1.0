//analizsint

#include "global.h"

struct entrada palsclave[]={
	"div", DIV,
	"mod", MOD,
	0,     0		
};
int inic()
{
	struct entrada *p;
	for (p = palsclave; p->complex; p++){
        inserta(p->aplex, p->complex);
    }
}