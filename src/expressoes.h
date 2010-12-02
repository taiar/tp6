/*
 * expressoes.h
 *
 *  Created on: 02/12/2010
 *      Author: taiar
 */

#ifndef EXPRESSOES_H_
#define EXPRESSOES_H_

#define EXPRESSOES_FILE "expressoes.txt"
#define EXPRESSOES_QUANT 7
#define EXPRESSOES_MAXLENGTH 190

#include "io.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Carrega expressõs em memória e retorna um vetor delas.
 */
char** expressoesCarrega();

/**
 * Libera a memória utilizada pelas expressões
 */
void expressoesFree(char**);

#endif /* EXPRESSOES_H_ */
