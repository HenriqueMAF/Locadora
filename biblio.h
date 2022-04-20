#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <unistd.h>
#include "data.h"
#include "bli.h"

#define ModeloA 180 //Carro compacto com ar
#define ModeloB 240 //Carro intermediaria completo 
#define ModeloC 300 //Pick-up e Carros de lux
#define ModeloD 360 // MiniVan e afim
#define juros 0.15

char *clientess; 
char *CPPF;
char *tratar;

struct locadora{
  char locatario[50];
  char CPF[15];
  char Modelo[10];
  int Dias;
  float Valor, valorjuros;
}aluguel[5];

//---------------Cadastro cliente--------------------
struct locadora afiliar (){
  struct locadora cadastro;
  printf("\nDigite o nome completo do locatario:\n\t");
  scanf("\n");
  scanf("%[^\n]*c",cadastro.locatario);
  tratar=cadastro.locatario;
  captalizar(tratar);
  printf("\nDigite o CPF do locatario:\n\t");
  scanf("\n");
  scanf("%[^\n]*c",cadastro.CPF);
  return cadastro;
}//end afiliado

//--------------------Catalogo--------------------
int catalogo (){
 
  printf("\nModelo A:\tValor da diaria: R$ 180,00\tCodigo: A147\n\n\tCarros populares, compactos e com ar\n\n");
  printf("Modelo B:\tValor da diaria: R$ 240,00\tCodigo: B258\n\n\tCarros intemediarios, sedan, com ar e direção\n\n");
  printf("Modelo C:\tValor da diaria: R$ 300,00\tCodigo: C369\n\n\tCarros de luxo, Pick-up, SUV completos\n\n");
  printf("Modelo D:\tValor da diaria: R$ 360,00\tCodigo: D456\n\n\tMinivans, microonibus e afins\n\n");

  return 0;
}

//-------------------------Alugar----------------------------
int alugar (int codigo){
  
  char teste[10], M[4][10]={{"A147"},{"B258"},{"C369"},{"D456"}};
  int comparar=10, confirma=1, erro=1;

  while(erro){
  catalogo();
  
  printf("\nDigite o codigo do Modelo de veiculo que deseja locar.\n"); 
  scanf("%s",aluguel[codigo].Modelo);
  
  for(int i=0;i<4;i++){
    comparar=strcmp(aluguel[codigo].Modelo,M[i]);
    if(comparar==0){
      comparar=i;
      i=5;
    }
  }// end for
  //getchar();getchar(); 
  switch(comparar){
    case 0: //MODELO A
      system("clear");
      while(confirma){
        printf("\nModelo A\n");
        printf("Dias de locação: ");
        scanf("%d",&aluguel[codigo].Dias);

        aluguel[codigo].Valor=aluguel[codigo].Dias*ModeloA;

        printf("\nValor do aluguel: R$ %.2f",aluguel[codigo].Valor);
        printf("\n\nDeseja finalizar aluguel?\nDigite:\n[1] SIM\n[2] NÃO\n");
        scanf("%d",&confirma);

        if(confirma==1){
          printf("\nAluguel concluido com SUCESSO\n");
          registrar(); //função de registro 
          FILE*salvar=fopen("Registros.txt","a");
          fprintf(salvar,"Cliente: %s\nCPF: %s",clientess,CPPF);
          fprintf(salvar,"\nModelo reservado: %s;\nDias reservado: %d;\nDebito: R$ %.2f\n",aluguel[codigo].Modelo,aluguel[codigo].Dias,aluguel[codigo].Valor);
          fclose(salvar);
          confirma=0;
        }//end if
        else if(confirma==2){
          printf("Deseja cancelar ou alterar os dias de locação?\n[1] CANCELAR\n[2] ALTEAR OS DIAS\n");
          scanf("%d",&confirma);
          if(confirma==1){
            strcpy(aluguel[codigo].Modelo,"VAZIO");
            printf("\nOPERAÇÃO CANCELADA COM SUCESSO...\n");
            confirma=0;
          }else{
            confirma=1;
            system("clear");
          }
        }//end else if
      }//end while
      erro=0;
    break;
    case 1: //MODELO B
      system("clear");
      while(confirma){
        printf("\nModelo B\n");
        printf("Dias de locação: ");
        scanf("%d",&aluguel[codigo].Dias);

        aluguel[codigo].Valor=aluguel[codigo].Dias*ModeloB;

        printf("\nValor do aluguel: R$ %.2f",aluguel[codigo].Valor);
        printf("\n\nDeseja finalizar aluguel?\nDigite:\n[1] SIM\n[2] NÃO\n");
        scanf("%d",&confirma);

        if(confirma==1){
          printf("\nAluguel concluido com SUCESSO\n");
          registrar(); //função de registro 
          FILE*salvar=fopen("Registros.txt","a");
          fprintf(salvar,"Cliente: %s\nCPF: %s",clientess,CPPF);
          fprintf(salvar,"\nModelo reservado: %s;\nDias reservado: %d;\nDebito: R$ %.2f\n",aluguel[codigo].Modelo,aluguel[codigo].Dias,aluguel[codigo].Valor);
          fclose(salvar);
          confirma=0;
        }//end if
        else if(confirma==2){
          printf("Deseja cancelar ou alterar os dias de locação?\n[1] CANCELAR\n[2] ALTEAR OS DIAS\n");
          scanf("%d",&confirma);
          if(confirma==1){
            strcpy(aluguel[codigo].Modelo,"VAZIO");
            printf("\nOPERAÇÃO CANCELADA COM SUCESSO...\n");
            confirma=0;
          }else{
            confirma=1;
            system("clear");
          }
        }//end else if
      }//end while
      erro=0;
    break;
    case 2: //MODELO C
       system("clear");
      while(confirma){
        printf("\nModelo C\n");
        printf("Dias de locação: ");
        scanf("%d",&aluguel[codigo].Dias);

        aluguel[codigo].Valor=aluguel[codigo].Dias*ModeloC;

        printf("\nValor do aluguel: R$ %.2f",aluguel[codigo].Valor);
        printf("\n\nDeseja finalizar aluguel?\nDigite:\n[1] SIM\n[2] NÃO\n");
        scanf("%d",&confirma);

        if(confirma==1){
          printf("\nAluguel concluido com SUCESSO\n");
          registrar(); //função de registro 
          FILE*salvar=fopen("Registros.txt","a");
          fprintf(salvar,"Cliente: %s\nCPF: %s",clientess,CPPF);
          fprintf(salvar,"\nModelo reservado: %s;\nDias reservado: %d;\nDebito: R$ %.2f\n",aluguel[codigo].Modelo,aluguel[codigo].Dias,aluguel[codigo].Valor);
          fclose(salvar);
          confirma=0;
        }//end if
        else if(confirma==2){
          printf("Deseja cancelar ou alterar os dias de locação?\n[1] CANCELAR\n[2] ALTEAR OS DIAS\n");
          scanf("%d",&confirma);
          if(confirma==1){
            strcpy(aluguel[codigo].Modelo,"VAZIO");
            printf("\nOPERAÇÃO CANCELADA COM SUCESSO...\n");
            confirma=0;
          }else{
            confirma=1;
            system("clear");
          }
        }//end else if
      }//end while
      erro=0;
    break;
    case 3: //MODELO D
      system("clear");
      while(confirma){
        printf("\nModelo D\n");
        printf("Dias de locação: ");
        scanf("%d",&aluguel[codigo].Dias);

        aluguel[codigo].Valor=aluguel[codigo].Dias*ModeloD;

        printf("\nValor do aluguel: R$ %.2f",aluguel[codigo].Valor);
        printf("\n\nDeseja finalizar aluguel?\nDigite:\n[1] SIM\n[2] NÃO\n");
        scanf("%d",&confirma);

        if(confirma==1){
          printf("\nAluguel concluido com SUCESSO\n");
          registrar(); //função de registro 
          FILE*salvar=fopen("Registros.txt","a");
          fprintf(salvar,"Cliente: %s\nCPF: %s",clientess,CPPF);
          fprintf(salvar,"\nModelo reservado: %s;\nDias reservado: %d;\nDebito: R$ %.2f\n",aluguel[codigo].Modelo,aluguel[codigo].Dias,aluguel[codigo].Valor);
          fclose(salvar);
          confirma=0;
        }//end if
        else if(confirma==2){
          printf("Deseja cancelar ou alterar os dias de locação?\n[1] CANCELAR\n[2] ALTEAR OS DIAS\n");
          scanf("%d",&confirma);
          if(confirma==1){
            strcpy(aluguel[codigo].Modelo,"VAZIO");
            printf("\nOPERAÇÃO CANCELADA COM SUCESSO...\n");
            confirma=0;
          }else{
            confirma=1;
            system("clear");
          }
        }//end else if
      }//end while
      erro=0;
    break;
    default:
      printf("\nERRO\nModelo não localizado. Favor repetir o processo\n");
      getchar();getchar();
    break;
  }//end switch
  }//end while
  return 0;
}
//-----------------------Devolução---------------------
int devolucao(int codigo){
  int diaDev;
  char devolvido[]="VAZIO";
  float maisdias, NvValor;

  if(aluguel[codigo].Valor==0){
    printf("\nNão há Debito em aberto\n");
  }else{
    printf("\nModelo: %s\nDias: %d\nDebito: %.2f\n",aluguel[codigo].Modelo, aluguel[codigo].Dias, aluguel[codigo].Valor);
  }
  printf("\nDigite com quantos dias o locatario fico com o veiculo em sua posse: ");
  scanf("%d",&diaDev);
  if(diaDev==aluguel[codigo].Dias){
    printf("\nConfirmando pagamento... \n");
    devo(); //função de registro 
    FILE *file2 = fopen("Devoluções.txt","a");
    fprintf(file2,"Cliente: %s\nCPF: %s",clientess,CPPF);
    fprintf(file2,"\nModelo: %s\nDias: %d\nDebito: %.2f\n",aluguel[codigo].Modelo, aluguel[codigo].Dias, aluguel[codigo].Valor);
    fclose(file2);
    getchar();getchar();
  }else{
    printf("\nCalculando novo valor...\n");

    maisdias=(aluguel[codigo].Valor/aluguel[codigo].Dias)*(diaDev-aluguel[codigo].Dias);
    aluguel[codigo].valorjuros= (maisdias+aluguel[codigo].Valor)*juros;
    NvValor=aluguel[codigo].Valor+aluguel[codigo].valorjuros;
    sleep(1);

    printf("\nValor reajustado: R$ %.2f\n",NvValor);
    devo(); //função de registro 
    FILE *file2 = fopen("Devoluções.txt","a");
    fprintf(file2,"Cliente: %s\nCPF: %s",clientess,CPPF);
    fprintf(file2,"\nModelo: %s\nDias: %d\nDebito: %.2f\n",aluguel[codigo].Modelo, aluguel[codigo].Dias, aluguel[codigo].Valor);
    fprintf(file2,"Dias de locação: %d\nValor reajustado: R$ %.2f\n",diaDev,NvValor);
    fclose(file2);
    getchar();getchar();
  }
  printf("\nPagamento Realizado com sucesso.\n");
  
  strcpy(aluguel[codigo].Modelo,devolvido);
  aluguel[codigo].Dias=0;
  aluguel[codigo].Valor=0.00;
  aluguel[codigo].valorjuros=0.00;

  getchar();getchar();
  return 0;
}
//-----------------Area do Cliente ------------------------
void AreaCliente (int codigo){

  printf("Modelo reservado: %s;\nDias reservado: %d;\nDebito: R$ %.2f",aluguel[codigo].Modelo,aluguel[codigo].Dias,aluguel[codigo].Valor);


}
int verifica (int x){
  int debitoativo = aluguel[x].Valor;
  return debitoativo;
}