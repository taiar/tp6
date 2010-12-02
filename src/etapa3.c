/*
 * etapa3.c
 *
 *  Created on: 02/12/2010
 *      Author: taiar
 */

#include "etapa3.h"

void etapa3(Entrada *in, char **expressoes)
{
  int i, casou = 0, newLine = 1, startLine = 0;
  char buff;
  for (i = 0; i < EXPRESSOES_QUANT; i += 1)
  {
    printf("Expressao: \"%s\"\n", expressoes[i]);
    buff = getc(in->entrada);
    while (buff != EOF)
    {
      if(isalnum(buff) || buff == '-' || buff == '\n' || buff == ' ')
      {
        if(buff == '\n')
        {
          newLine += 1;
          buff = ' ';
        }
        if(expressoes[i][casou] == buff)
        {
          if(!startLine)
            startLine = newLine;
          casou += 1;
        }
        else
        {
          startLine = 0;
          casou = 0;
        }
      }
      if(expressoes[i][casou] == '\0')
      {
        printf("Linha %d\n", startLine);
        casou = 0;
      }
      buff = getc(in->entrada);
    }
    casou = 0;
    newLine = 1;
    entradaResetaLeitura(in);
  }
}
