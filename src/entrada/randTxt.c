#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <sys/resource.h>

#define PALMAXCHARS 15
#define TAMANHOALFABETO 26
#define QUANTPALAVRAS 1000000

int main()
{
  int i, j;
  int tamPal;
  char txt[30];
  char term[PALMAXCHARS + 5];
  
  srand(time(NULL));
  strcpy(txt, "abcdefghijklmnopqrstuvwxyz");
  
  for(i = 0; i < QUANTPALAVRAS; i += 1)
  {
    tamPal = rand()%PALMAXCHARS;
    tamPal = (tamPal<=1)?2:tamPal;
    
    for(j = 0; j < tamPal; j += 1)
      term[j] = txt[rand()%TAMANHOALFABETO];
    
    term[tamPal] = '\0';
    printf("%s", term);
    
    if((rand()%100)>=90) printf(". ");
    else if((rand()%100)>=99) printf(".\n\n");
    else printf(" ");
  }
  return 0;
}

