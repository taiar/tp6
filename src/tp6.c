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

int main(int argc, char **argv)
{
  Entrada entrada;
  entradaInit(&entrada);
  if (!entradaLe(argc, argv, &entrada)) return EXIT_FAILURE;
  char **StopWords = stopWordsCarrega();

  char buff[1024];

  fscanf(entrada.entrada, "", buff);

  printf("%s\n", buff);

  //printf("%d\n", stopWordsVerifica("vos", StopWords));

  stopWordsFree(StopWords);
  entradaFree(&entrada);

  return EXIT_SUCCESS;
}
