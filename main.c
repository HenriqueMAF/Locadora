#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "biblio.h"

/*
- Criar funções para cada menu, submenu
- Cadastro, alteração e exclusão utilizar arquivo .txt
http://linguagemc.com.br/arquivos-em-c-categoria-usando-arquivos/
*/


int main(void) {
  int menu, ctrl=1, i=0, retorno=1, op, cad, clie=0, codloc, devol=1, exclu, pag;
  char comparar[]={"Sem cadastro"}, CCC[]={"000.000.00-00"}, busca[30];
  struct locadora cliente [5];

  for(int i=0;i<5;i++){
    strcpy(cliente[i].locatario,comparar);
    strcpy(cliente[i].CPF,CCC);
  }//End for
  
  FILE *file = fopen("Registros.txt","w");
  fclose (file);
  FILE *file2 = fopen ("Devoluções.txt","w");
  fclose(file2); 

    while(ctrl!=0){//begin while
      system("clear || cls");

      printf("\t=============\n");
      printf("\tPRIME LOCAÇÕES\n");
      printf("\t=============\n");
      
      printf("\nDigite:\n[1] Cadastro de cliente\n[2] Descrição dos veiculos\n[3] Aluguel de veiculos\n[4] Devolução de veiculo\n[5] Clientes cadastrados\n[6] Area do Cliente\n[0] SAIR\n\n");
      printf("=> ");
      scanf("%d",&menu);
      switch(menu){//begin switch

        case 0: //-----------Fim do programa---------------
          printf("\nAté a proxima, volte sempre!\n");
          sleep(1);
          return 0;

        case 1: //-----------cadastro------------
          for(int x=0;x<5;x++){
            retorno=strcmp(comparar,cliente[i].locatario);
            if(retorno==0){
              cliente[i]=afiliar();
              i++;
              printf("Deseja realizar outro cadastro?\nDigite:\n[1] sim\n[2] não\n");
              scanf("%d",&cad);
              
              system ("clear");
              if(cad!=1){
                x=6;
                break;
              }
            }//end if
          }//end for
          if(i>4){
              printf("\nLimite de clientes cadastrados alcançado.\n");
              getchar();getchar();
            }
          system ("clear");
        break;

        case 2: //----------descrição dos veiculos---------
          printf("Descrição dos modelos Disponiveis\n");
          catalogo();
          getchar();getchar();
          system ("clear");
        break;

        case 3: //--------------aluguel-------------
          printf("\n\tLista de Clientes\n");
          clie=0;
          for(int i=0;i<4;i++){
            retorno=strcmp(cliente[i].locatario,comparar);
            if(retorno>0 || retorno<0 || retorno!=0){
              printf("\nCodigo \t Nome\n\n%d - %s",i,cliente[i].locatario);
              clie++;
            }//end for
          }//End for
          if(clie!=0){
            printf("\nDigite o codigo do locatario: ");
            scanf("%d",&codloc);
            system("clear");
            printf("\n%s\n",cliente[codloc].locatario);
            clientess = cliente[codloc].locatario;
            CPPF = cliente[codloc].CPF;
            alugar(codloc);
          }else{
            printf("\nNão há clientes cadastrados\n");
          }
          getchar(); getchar();
          system ("clear");
        break;

        case 4: //---------------Devolução de veiculos---------------
          devol=1;
          while(devol){
            printf("\nDigite o codigo do locatario: ");
            scanf("%d",&codloc);
            printf("\n\n%s\n%s",cliente[codloc].locatario, cliente[codloc].CPF);
            printf("\n\nLocatario corresponde ao codigo?\nDigite:\n[1] SIM\n[2] NÃO\n[3] SAIR DESTE MENU\n");
            scanf("%d",&devol);
            if(devol==1){
              system("clear");
              printf("\n\n%s\n%s",cliente[codloc].locatario, cliente[codloc].CPF);
              clientess = cliente[codloc].locatario;
              CPPF = cliente[codloc].CPF;
              devolucao(codloc);
              devol=0;
            }else if(devol==2){
             printf("\nFavor repetir o processo\n");
             getchar();getchar();
            }else if(devol==3){
              devol=0;
              break;
            }else{
              printf("\nERRO\n\nFavor repetir o processo\n");
              getchar();getchar();
            }
          }//end while 
        break;

        case 5: //-----------------Lista cliente----------------
          printf("\n\tLista de Clientes");
          for(int i=0;i<5;i++){
            printf("\n%d - %s",i+1,cliente[i].locatario);
            printf("\nCPF: %s\n",cliente[i].CPF);
          }//End for
          getchar(); getchar(); 
          system("clear");
        break;
        case 6: //------------Area do cliente-----------
          printf("\nDigite o CPF do Cliente.\n");
          scanf("\n");
          scanf("%[^\n]*c",busca);
          
          for(int i=0;i<5;i++){
            codloc=strcmp(busca,cliente[i].CPF);
            if (codloc==0) {
              printf("\nClinete: %s\nCPF: %s\n",cliente[i].locatario,cliente[i].CPF);
              AreaCliente(i);
              printf("\n\n[0]Excluir cadastro\t[1]SAIR\n");
              scanf("%i",&exclu);
              if(exclu==0){
                pag = verifica(i);
                if(pag==0){
                  strcpy(cliente[i].locatario,comparar);
                  strcpy(cliente[i].CPF,CCC);
                  printf("\nCliente desvinculado com sucesso.");
                  getchar();getchar();

                }else if(pag!=0){
                  printf("\nAinda há um debito em aberto, legalize a cituação para deletar o cadastro");
                  getchar();getchar();

                }
              }
              i=6;
              codloc=0;
            }
          }
          if(codloc!=0){
             printf("\nCPF não cadastrado.\nFavor realizar um novo cadastro\n");
             getchar();getchar();
          }
        break;
        default: //--------retorno ao menu--------------
          printf("\nOpção invalida...\n");
          sleep(1);
          system ("clear");
          main();
      }//end switch
    }//end while

  return 0;
}