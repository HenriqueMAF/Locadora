#include <stdio.h>
#include <ctype.h>
/*exclicação da biblioteca ctype.h https://www.ime.usp.br/~pf/algoritmos/apend/ctype.h.html*/
int captalizar (char *p){
  for(int i=0;i<50;i++){  
    *(p+i)=tolower(*(p+i));  
    if(i<1){
     *(p+i)=toupper(*(p+i));
    }
    if(*(p+i) == ' '){
      ++i;
      *(p+i)=toupper(*(p+i));
    } 
  }
}