/*
 * expressoes.c
 *
 *  Created on: 02/12/2010
 *      Author: taiar
 */

#include "expressoes.h"

char** expressoesCarrega()
{
  int i, n = 0;
  FILE *arq;
  char buff;
  char **v = (char**) malloc(sizeof(char*) * EXPRESSOES_QUANT);

  arq = fopen(EXPRESSOES_FILE, "r");
  if (!arq)
  {
    printf("Erro: arquivo %s não encontrado.\n", EXPRESSOES_FILE);
    exit(EXIT_FAILURE);
  }

  for (i = 0; i < EXPRESSOES_QUANT; i += 1)
  {
    v[i] = (char*) malloc(sizeof(char) * EXPRESSOES_MAXLENGTH);
    v[i][0] = '\0';
    buff = getc(arq);
    while (buff != '\n' && buff != EOF)
    {
      if (isalnum(buff) || buff == '-' || buff == ' ')
      {
        v[i][n] = buff;
        n += 1;
      }
      buff = getc(arq);
    }
    n += 1;
    v[i][n] = '\0';
    n = 0;
  }

  fclose(arq);
  return v;
}

void expressoesFree(char **expressoes)
{
  int i;
  for (i = 0; i < EXPRESSOES_QUANT; i += 1)
    free(expressoes[i]);
  free(expressoes);
}
