#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 6000

#define bool int
#define TRUE 1
#define FALSE 0

#define NAME_SIZE 51
#define CITIES_SIZE 11
#define BI_SIZE 5
#define DAY_SIZE 2
/*
A companhia aérea “Já Fui” tem nove voos diários na Europa a partir de Lisboa
(com e sem escala). 

Neste trabalho não vão interessar os voos de regresso. 

Os nove voos estão mostrados na figura em baixo. 

Cada avião pode transportar 20 passageiros.

O mês em questão tem 30 days e a gestão dos passageiros consiste em fazer reservas de voos,
propor datas alternativas aos clientes e mudanças de escala se forem possíveis.
*/

//https://stackoverflow.com/questions/17598572/read-and-write-to-binary-files-in-c#17598785

//fprintf - escrever
//fscanf - ler



void addWhiteSpacesToString(char word[], int lenght) {

  for (int i = 0; i < lenght; i++) //num_space_req < 20  
  {
    memset(word, ' ', lenght);
    //name[num_space_req] = '\0'; - o stor pede para nós não termos isto
  }
}

void changeText(char dest[], char src[], int sizeOfSrc) {
  strncpy(dest, src, sizeOfSrc);
}

typedef struct passangerText {
  char bi[BI_SIZE];
  char name[NAME_SIZE];
  char partida[CITIES_SIZE];
  char chegada[CITIES_SIZE];
  char day[DAY_SIZE];
}
PASSANGER_TEXT_FILE;

typedef struct passangerBinary {
  int bi;
  char name[NAME_SIZE];
  char partida[CITIES_SIZE];
  char chegada[CITIES_SIZE];
  short int day;
}
PASSANGER_BINARY_FILE;

void addSpacesTextStruct(PASSANGER_TEXT_FILE * ptr) {
  addWhiteSpacesToString(ptr -> bi, BI_SIZE); // ou (*ptr).bi
  addWhiteSpacesToString(ptr -> name, NAME_SIZE);
  addWhiteSpacesToString(ptr -> partida, CITIES_SIZE);
  addWhiteSpacesToString(ptr -> chegada, CITIES_SIZE);
  addWhiteSpacesToString(ptr -> day, DAY_SIZE);
}

void addSpacesBinaryStruct(PASSANGER_BINARY_FILE * ptr) {
  addWhiteSpacesToString(ptr -> name, NAME_SIZE); // ou (*ptr).name
  addWhiteSpacesToString(ptr -> partida, CITIES_SIZE);
  addWhiteSpacesToString(ptr -> chegada, CITIES_SIZE);
}

/*
Estas duas estruturas servem apenas para limpar por completo outras estruturas
static const PASSANGER_TEXT_FILE EmptyTextCitizen;
static const PASSANGER_BINARY_FILE EmptyBinaryCitizen;
*/

PASSANGER_BINARY_FILE exampleBinary = {
  16380,
  "Tiago",
  "Lisboa",
  "Milão",
  10
};

int readBinary(PASSANGER_BINARY_FILE * ptr) {
  FILE * fp;

  fp = fopen("file.data", "rb");
  if (fp == NULL) {
    printf("Error opening binary file\n");
    exit(1);
  }

  while (fread( & ptr, sizeof(ptr), 1, fp) == TRUE) {
    printf("bi: %d ", ptr -> bi);
    printf("name: %s ", ptr -> name);
    printf("partida: %s ", ptr -> partida);
    printf("chegada: %s ", ptr -> chegada);
    printf("day: %d \n\n", ptr -> day);
  }

  fclose(fp);

  return 0;
}

int readText(PASSANGER_TEXT_FILE * ptr) {

  FILE * fp;

  fp = fopen("file1.txt", "r");
  if (fp == NULL) {
    printf("Error opening text file\n");
    exit(1);
  }

  //fazer com fscanf

  fclose(fp);

  return 0;
}


int writeText(PASSANGER_TEXT_FILE * ptr) {

  FILE * fp;

  fp = fopen("file.txt", "w+");

  fprintf(fp, "%s   %s   %s   %s   %s  ", ptr -> bi, ptr -> name, ptr -> partida, ptr -> chegada, ptr -> day);


  fclose(fp);

  printf("\nFile was written\n");

  return 0;
}

/*

int writeBinary(PASSANGER_BINARY_FILE * ptr){
    FILE *fp;

    fp = fopen("file.data", "wb");
    if(fp == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }

    while( fwrite(&exampleBinary, sizeof(exampleBinary), 1, fp) == TRUE )
    {
        printf("bi: %d \n", ptr -> bi);
        printf("name: %s \n", ptr -> name);
        printf("partida: %s \n", ptr -> partida);
        printf("chegada: %s \n\n", ptr -> chegada);
        printf("day: %d \n\n", ptr -> day);
    }

    fclose(fp);

    return 0;
}
*/

/*

5: https://stackoverflow.com/questions/28506570/can-i-use-fscanf-with-binary-files-in-the-c-language#28506842

Esta opção deve escrever os dados existentes num ficheiro de texto cujo name é
perguntado ao utilizador. 

Os dados devem ser escritos no formato indicado em cima
para a opção de leitura. 

O ficheiro deve ser fechado no final da opção. O ficheiro deve
ser igual ao ficheiro de texto lido, evidentemente…

escreve texto
escreve binario

1 e 2.

le texto
le binario


3 
mostrar voos de 1 só day pediso na linha de comandos

4
mostrar só voos de day 1 a 9 ou 3 a 12 ou 25 a 4.
-fazer array tos valores que queremos e imprimir apenas esses.
=========== ver este ainda melhor ================

ir a meu trabalho deste ano e fazer parte de correr funções como argumentos na linha de comandos. gest -b fich1

*/

void showMenu() {

  printf("\nCompanhia de Aviação “Ja Fui”\n");
  printf("Programa de reservas\n\n\n");

  printf("0 - Sair do programa\n");
  printf("1 - Ler ficheiro de texto\n");
  printf("2 - Ler ficheiro binário\n");
  printf("3 - Listar passageiros de um voo\n");
  printf("4 - Número de passageiros de um período de days\n");
  printf("5 - Escrita em ficheiro\n");
  printf("6 - Análise económica\n");
  printf("7 - Passageiros em duas escalas\n");
  printf("8 - Reserva simples de um voo\n\n");

}

void choices() {
  char choice;
  int choiceSucess = 0;

  while (choiceSucess == 0) {
    showMenu();

    choice = getchar();
    switch (choice) {
    case '0':
      printf("\nEscolheu sair do programa\n\n");
      exit(1);
      break;
    case '1':
      //readText();
      break;
    case '2':
      readBinary(&exampleBinary);
      break;
    case '3':
      break;
    case '4':
      break;
    case '5':
      //writeText();
      break;
    case '6':
      break;
    case '7':
      break;
    case '8':
      break;
    }
  }

}

int main() {


PASSANGER_BINARY_FILE exampleBinary = {10, " ", " ", " ", 20};
printf("\n\n\nsize: %ld\n\n\n", strlen(exampleBinary.name));

addSpacesBinaryStruct(&exampleBinary);

printf("\n\n\nsize: %ld\n\n\n", strlen(exampleBinary.chegada));

/*
1. ver o problema em que a função addSpacesBinaryStruct não está a dar o numero certo

2. fazer ponto 5 do trabalho

3. fazer a parte inicial que vai do 10 aos 13
*/
}