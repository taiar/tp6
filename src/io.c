#include "io.h"

void entradaInit(Entrada *entrada)
{
  entrada->iFlag = 0;
  entrada->oFlag = 0;

  entrada->i = NULL;
  entrada->o = NULL;

  entrada->entrada = NULL;
  entrada->saidaE1 = NULL;
  entrada->saidaE2 = NULL;
  entrada->saidaE3 = NULL;
}

void entradaResetaLeitura(Entrada *in)
{
  fseek(in->entrada, 0, SEEK_SET);
}

int entradaLe(int argc, char** argv, Entrada *entrada)
{
  entradaInit(entrada);
  int c;
  char nomeSaida[100];
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

  strcpy(nomeSaida, entrada->o);
  strcat(nomeSaida, "1");
  entrada->saidaE1 = fopen(nomeSaida, "w");
  if (!entrada->saidaE1)
  {
    printf("Não foi possível criar o arquivo de saida 1.\n");
    return 0;
  }

  strcpy(nomeSaida, entrada->o);
  strcat(nomeSaida, "2");
  entrada->saidaE2 = fopen(nomeSaida, "w");
  if (!entrada->saidaE2)
  {
    printf("Não foi possível criar o arquivo de saida 2.\n");
    return 0;
  }

  strcpy(nomeSaida, entrada->o);
  strcat(nomeSaida, "3");
  entrada->saidaE3 = fopen(nomeSaida, "w");
  if (!entrada->saidaE3)
  {
    printf("Não foi possível criar o arquivo de saida 3.\n");
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
    if (estado == 0)
    {
      //recebe o primeiro caractere de palavra
      if (isalnum(buff) || buff == '-') estado = 1;

      //recebe quebra de linha
      else if (buff == '\n') estado = 2; //trata nova linha

      else if (buff == EOF) return 0; //casa fim do arquivo
    }
    if (estado == 1)
    {
      //continua recebendo caracteres válidos
      if (isalnum(buff) || buff == '-')
      {
        token[count] = buff;
        count += 1;
        token[count] = '\0';
      }

      //recebe espaço
      else if (buff == ' ') return 1; //casa a palavra

      //recebe pontuação
      else if (ispunct(buff))
      {
        if (buff == ',') //não indica fim de frase
        return 1; //casa a palavra
        else return 2; //casa a frase
      }

      //recebe quebra de linha
      else if (buff == '\n') estado = 2; //estado que analisa quebras de linha

      //casa fim do arquivo
      else if (buff == EOF) return 0;
    }

    if (estado == 2)
    {
      buff = getc(in->entrada);

      //recebe um parágrafo
      if (buff == '\n')
      {
        while (buff == '\n')
        {
          buff = getc(in->entrada);
          nlCounter += 1;
        }
        nlCounter += 4;
        fseek(in->entrada, -1, SEEK_CUR);
        return nlCounter; //casa o parágrafo
      }

      if (buff == EOF) return 0;
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
  fclose(entrada->saidaE1);
  fclose(entrada->saidaE2);
  fclose(entrada->saidaE3);
}
