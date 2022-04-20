#include <stdio.h>
#include "bli.h"

int main (void){
  char nome[50];
  char *tratar=nome;

  printf("Digite:\n");
  scanf("\n");
  scanf("%[^\n]*c",nome);

  captalizar(tratar);

  printf("\n%s",nome);
  
  return 0;
}
