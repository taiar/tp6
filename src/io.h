#ifndef __io__
#define __io__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

/**
 * Armazena dados lidos da entrada.
 */
typedef struct
{
  int iFlag, oFlag;
  char *i, *o;
  FILE *entrada, *saida;
} Entrada;

/**
 * Seta os valores iniciais da estrutura de entrada.
 */
void entradaInit(Entrada*);

/**
 * Faz leitura dos dados de entrada e os armazena.
 */
int entradaLe(int, char**, Entrada*);

/**
 * Traz "token" do arquivo lido de seguindo a lógica do texto.
 * Retorna alguns sinais segundo o "token" que foi casado:
 * 0 EOF
 * 1 palavra
 * 2 frase
 * 3 linha
 * 4 parágrafo
 */
int entradaGetToken(Entrada*, char*);

/**
 * Libera dados utilizados na leitura da entrada.
 */
void entradaFree(Entrada*);

#endif
