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

  int val;
  char palavra[90];

  int pal = 0;
  int nl = 1;
  int frase = 0;
  int parag = 0;

  val = entradaGetToken(&entrada, palavra);
  while (val)
  {
    if (val == 1) pal += 1;
    else if (val == 2)
    {
      pal += 1;
      frase += 1;
    }
    else if (val == 3)
      nl += 1;
    else if (val > 3)
    {
      parag += 1;
      nl += val - 2;
    }
    val = entradaGetToken(&entrada, palavra);
  }

  printf("Palavras: %d\nFrases: %d\nLinhas: %d\nParagrafos: %d\n", pal, frase, nl, parag);

  stopWordsFree(StopWords);
  entradaFree(&entrada);

  return EXIT_SUCCESS;
}
