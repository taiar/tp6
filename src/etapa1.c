/*
 * etapa1.c
 *
 *  Created on: 27/11/2010
 *      Author: taiar
 */

#include "etapa1.h"

void etapa1(Entrada *in, char **stopWords)
{
  char palavra[50];
  int cPalavras = 0, cPalavrasNStop = 0, cLinhas = 1, cFrases = 0, cParagrafos =
      0;
  int tokenFlag;

  int nLinhaInicio;

  tokenFlag = entradaGetToken(in, palavra);

  while (tokenFlag)
  {
    // texto que começa com quebra(s) de linha
    if (tokenFlag == 3)
    {
      cLinhas += 1;
      nLinhaInicio = cLinhas;
      tokenFlag = entradaGetToken(in, palavra);
    }
    else if (tokenFlag > 3)
    {
      cLinhas += tokenFlag - 3;
      nLinhaInicio = cLinhas;
      tokenFlag = entradaGetToken(in, palavra);
    }
    else nLinhaInicio = cLinhas;

    fprintf(in->saidaE1, "Parágrafo %d começa na linha %d\n", cParagrafos + 1, nLinhaInicio);
    while (tokenFlag && tokenFlag <= 3)
    {
      //palavra
      if (tokenFlag == 1)
      {
        cPalavras += 1;
        if (!stopWordsVerifica(palavra, stopWords)) cPalavrasNStop += 1;
      }
      //frase
      else if (tokenFlag == 2)
      {
        cFrases += 1;
        cPalavras += 1;
        if (!stopWordsVerifica(palavra, stopWords)) cPalavrasNStop += 1;
        fprintf(in->saidaE1, "Frase %d\n", cFrases);
        fprintf(in->saidaE1, "Com stop words: %d\n", cPalavras);
        fprintf(in->saidaE1, "Sem stop words: %d\n", cPalavrasNStop);
        cPalavrasNStop = 0;
        cPalavras = 0;
      }
      //quebra de linha
      else if (tokenFlag == 3)
      {
        cPalavras += 1;
        cLinhas += 1;
        if (!stopWordsVerifica(palavra, stopWords)) cPalavrasNStop += 1;
      }
      tokenFlag = entradaGetToken(in, palavra);
    }
    //reinicia contadores
    cParagrafos += 1;
    cFrases = 0;
  }
}
