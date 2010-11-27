/*
 * stopWords.c
 *
 *  Created on: 27/11/2010
 *      Author: taiar
 */

#include "stopWords.h"

char* stopWordsCarrega()
{
  int i;
  FILE *arq;
  char **v = (char**) malloc(sizeof(char*) * STOP_WORDS_COUNTER);
  arq = fopen(STOP_WORDS_FILE, "r");
  if (!arq)
  {
    printf("Erro: arquivo %s não encontrado.\n", STOP_WORDS_FILE);
    exit(EXIT_FAILURE);
  }

  for (i = 0; i < STOP_WORDS_COUNTER; i += 1)
  {
    v[i] = (char*) malloc(sizeof(char) * 20);
    fscanf(arq, "%s\n", v[i]);
  }

  free(arq);

  return v;
}
