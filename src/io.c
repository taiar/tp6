#include "io.h"

void entradaInit(Entrada *entrada)
{
  entrada->iFlag = 0;
  entrada->oFlag = 0;

  entrada->i = NULL;
  entrada->o = NULL;

  entrada->entrada = NULL;
  entrada->saida = NULL;
}

int entradaLe(int argc, char** argv, Entrada *entrada)
{
  entradaInit(entrada);
  int c;
  while ((c = getopt(argc, argv, "i:o:")) != -1)
  {
    switch (c)
    {
      case 'i':
        entrada->iFlag = 1;
        entrada->i = optarg;
        break;
      case 'o':
        entrada->oFlag = 1;
        entrada->o = optarg;
        break;
    }
  }
  if (entrada->iFlag != 1 || entrada->oFlag != 1)
  {
    printf("Parâmetros não foram passados corretamente na linha de comando:\n");
    printf("%s -i <arquivo de entrada> -o <arquivo de saída>\n", argv[0]);
    return 0;
  }

  entrada->entrada = fopen(entrada->i, "rb");
  if (!entrada->entrada)
  {
    printf("O arquivo de entrada não está correto.\n");
    return 0;
  }

  entrada->saida = fopen(entrada->o, "w");
  if (!entrada->saida)
  {
    printf("Não foi possível criar o arquivo de saída.\n");
    return 0;
  }
  return 1;
}

int entradaGetToken(Entrada *in, char *token)
{
  int count = 0, estado = 0, nlCounter = 0;
  char buff;

  token[0] = '\0';
  buff = getc(in->entrada);

  while (buff != EOF)
  {
    if(estado == 0)
    {
      if(isalnum(buff) || buff == '-') //recebe o primeiro caractere de palavra
        estado = 1;
      else if(buff == '\n') //recebe quebra de linha
        estado = 2; //trata nova linha
      else if(buff == EOF)
        return 0; //casa fim do arquivo
    }
    if(estado == 1)
    {
      if(isalnum(buff) || buff == '-') //continua recebendo caracteres válidos
      {
        token[count] = buff;
        count += 1;
        token[count] = '\0';
      }
      else if(buff == ' ') //recebe espaço
        return 1; //casa a palavra
      else if(ispunct(buff)) //recebe pontuação
      {
        if(buff == ',') //não indica fim de frase
          return 1; //casa a palavra
        else
          return 2; //casa a frase
      }
      else if(buff == '\n') //recebe quebra de linha
        estado = 2; //estado que analisa quebras de linha
      else if(buff == EOF)
        return 0; //casa fim do arquivo
    }
    if(estado == 2)
    {
      printf("Oi manolos\n");
      buff = getc(in->entrada);
      if(buff == '\n') //recebe um parágrafo
      {
        while(buff == '\n')
        {
          buff = getc(in->entrada);
          nlCounter += 1;
        }
        nlCounter += 2;
        return nlCounter; //casa o parágrafo
      }
      fseek(in->entrada, -1, SEEK_CUR);
      return 3; //casa quebra de linha
    }
    buff = getc(in->entrada);
  }
  return 0; //EOF
}

void entradaFree(Entrada *entrada)
{
  fclose(entrada->entrada);
  fclose(entrada->saida);
}
