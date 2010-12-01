/*
 * tp6.c
 *
 *  Created on: 27/11/2010
 *      Author: taiar
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>

#include "io.h"
#include "stopWords.h"
#include "etapa1.h"

int main(int argc, char **argv)
{
  Entrada entrada;
  entradaInit(&entrada);
  if (!entradaLe(argc, argv, &entrada)) return EXIT_FAILURE;
  char **StopWords = stopWordsCarrega();

  etapa1(&entrada, StopWords);
  entradaResetaLeitura(&entrada);

  stopWordsFree(StopWords);
  entradaFree(&entrada);

  return EXIT_SUCCESS;
}
