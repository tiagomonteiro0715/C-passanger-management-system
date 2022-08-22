#include <stdio.h>


/*
A companhia aérea “Já Fui” tem nove voos diários na Europa a partir de Lisboa
(com e sem escala). 

Neste trabalho não vão interessar os voos de regresso. 

Os nove voos estão mostrados na figura em baixo. 

Cada avião pode transportar 20 passageiros.

O mês em questão tem 30 dias e a gestão dos passageiros consiste em fazer reservas de voos,
propor datas alternativas aos clientes e mudanças de escala se forem possíveis.
*/


//criar duas structs, uma para cada tipo de ficheiro - criar listas de structs

//https://stackoverflow.com/questions/17598572/read-and-write-to-binary-files-in-c#17598785
void menu(){

    printf("\nCompanhia de Aviação “Ja Fui”\n");
    printf("Programa de reservas\n\n\n");

    printf("0 - Sair do programa\n");
    printf("1 - Ler ficheiro de texto\n");
    printf("2 - Ler ficheiro binário\n");
    printf("3 - Listar passageiros de um voo\n");
    printf("4 - Número de passageiros de um período de dias\n");
    printf("5 - Escrita em ficheiro\n");
    printf("6 - Análise económica\n");
    printf("7 - Passageiros em duas escalas\n");
    printf("8 - Reserva simples de um voo\n\n");


}
int main(){

    menu();

}