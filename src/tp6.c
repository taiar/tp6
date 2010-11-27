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
  char **StopWords = stopWordsCarrega();
  printf("%d\n", stopWordsVerifica("vos", StopWords));
  return EXIT_SUCCESS;
}
