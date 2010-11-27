/*
 * stopWords.h
 *
 *  Created on: 27/11/2010
 *      Author: taiar
 */

#ifndef STOPWORDS_H_
#define STOPWORDS_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define STOP_WORDS_FILE "stopwords.txt"
#define STOP_WORDS_COUNTER 257

/**
 * Carrega Stop Words em memória e retorna um vetor delas.
 */
char** stopWordsCarrega();

/**
 * Verifica se uma palavra é Stop Word.
 */
int stopWordsVerifica(char*, char**);

#endif /* STOPWORDS_H_ */
