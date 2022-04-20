#include <stdio.h>
#include <time.h>
#include <locale.h> 

struct tempo {
  int tm_sec; // segundos 0 a 59
  int tm_min; // minutos de 0 a 59
  int tm_hour;  // horas de 0 a 24
  int tm_mday;  // dia do mes de 1 a 31
  int tm_mon; // meses do ano de 0 a 11
  int tm_year;  // anos apartir de 1900
  int tm_wday;  // dia da semana 0 (domingo) até 6 (sabado)
  int tm_yday;  // dia do ano 1 a 365
  int tm_isdst; // horario de verão se for diferente de (0) zero
};

//---------------------Aluguel---------------------

int registrar (void){

  struct tempo *data_hora_atual;

  time_t segundos; // declaração de variavel tipo timr_t
  time (&segundos); // recebe o valor da variavel em segundos
  data_hora_atual = localtime(&segundos); // convertar os segundos em horario do sistema

  int dia, mes, ano;
  int hora, minuto, segundo;

  dia = data_hora_atual -> tm_mday;
  mes = data_hora_atual -> tm_mon + 1;
  ano = data_hora_atual -> tm_year + 1900;
  hora = data_hora_atual -> tm_hour;
  minuto = data_hora_atual -> tm_min;
  segundo = data_hora_atual -> tm_sec;

  FILE *horario = fopen("Registros.txt","a");
  fprintf(horario,"\nLocal...........%s\n",setlocale(LC_ALL,""));
  fprintf(horario,"Data Atual.............%d/%d/%d\t",dia,mes,ano);
  fprintf(horario,"Horário Atual..........%d:%d:%d\n",hora,minuto,segundo);
  fclose(horario);
  
  return 0;
}

//----------------------Devolução---------------------

int devo (void){

  struct tempo *data_hora_atual;

  time_t segundos; // declaração de variavel tipo timr_t
  time (&segundos); // recebe o valor da variavel em segundos
  data_hora_atual = localtime(&segundos); // convertar os segundos em horario do sistema

  int dia, mes, ano;
  int hora, minuto, segundo;

  dia = data_hora_atual -> tm_mday;
  mes = data_hora_atual -> tm_mon + 1;
  ano = data_hora_atual -> tm_year + 1900;
  hora = data_hora_atual -> tm_hour;
  minuto = data_hora_atual -> tm_min;
  segundo = data_hora_atual -> tm_sec;

  FILE *horario = fopen("Devoluções.txt","a");
  fprintf(horario,"\nLocal...........%s\n",setlocale(LC_ALL,""));
  fprintf(horario,"Data Atual.............%d/%d/%d\t",dia,mes,ano);
  fprintf(horario,"Horário Atual..........%d:%d:%d\n",hora,minuto,segundo);
  fclose(horario);
  
  return 0;
}