//error.c

#include "global.h"

int error(char *m) /* genera todos los mensajes de error */
{
  fprintf(stderr, "línea %d: %s \n", numlinea, m);

  exit(1); /* terminación sin éxito */
}