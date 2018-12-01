/**

* Exercicio 3

* Nome: Marcus Goldschmidt Oliveira

* RGA: 201811310020

**/

#include <stdlib.h>
#include <stdio.h>

typedef struct TData{
	int dia;
	int mes;
}TData;

typedef struct TTrabalho {
	int id;
	float notaProvisoria;
	float notaFinal;
	TData data;
}TTrabalho;

int main()
{	
	
	TTrabalho *trabalho;
	
	// Alocando memória
	trabalho = malloc(sizeof(TTrabalho) * 10);
	
	for(int i = 0; i < 10; i++){
		printf("ID: ");
		scanf(" %d",&trabalho[i].id);
		printf("Nota Provisoria: ");
		scanf(" %f",&trabalho[i].notaProvisoria);
		printf("Dia da entrega: ");
		scanf(" %d",&trabalho[i].data.dia);
		printf("Mês da entrega: ");
		scanf(" %d",&trabalho[i].data.mes);
		
		// Calculo da nota
		if(trabalho[i].data.dia <= 20 && trabalho[i].data.mes <= 4){
			// Até 20/04, NF = NP + 10 pts
			trabalho[i].notaFinal = trabalho[i].notaProvisoria +10;
		} else if (trabalho[i].data.dia <= 2 && trabalho[i].data.mes <= 5){
			// Até 02/05, NF = NP
			trabalho[i].notaFinal = trabalho[i].notaProvisoria;
		} else if (trabalho[i].data.dia <= 30 && trabalho[i].data.mes <= 5){
			// Até 30/05, NF = NP / 2
			trabalho[i].notaFinal = trabalho[i].notaProvisoria / 2;
		} else {
			// Até 30/06, NF = 0
			trabalho[i].notaFinal = 0;
		}
		
		printf("Nota Final: %.2f\n",trabalho[i].notaFinal);
	}
	
	return 0;
}

