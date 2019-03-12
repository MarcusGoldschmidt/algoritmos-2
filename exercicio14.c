/* 
 * MARCUS GOLDSCHMIDT OLIVEIRA
 * RGA: 201811310020
*/
#include <stdio.h>
#include <stdlib.h>

int repeticoes(int *vetor, int number,int lenght);

int main()
{
	
	int *vetor;
	int aux;
	int repete;
	
	printf("Tamanho do vetor: ");
	scanf(" %d", &aux);
	
	printf("Numero a repetir: ");
	scanf(" %d", &repete);
	
	vetor = (int *) malloc(sizeof(int) * aux);
	
	for(int i = 0; i < aux; i++){
		printf("Valor em [%d]: ", i + 1);
		scanf(" %d", &vetor[i]);
	}
	
	printf("%d", repeticoes(vetor,repete, aux));
	
	return 0;
}

int repeticoes(int *vetor, int number,int lenght){
	if(lenght == -1){
		return 0;
	}
	
	if(vetor[lenght - 1] == number){
		return 1 + repeticoes(vetor, number, lenght - 1);
	}	
	
	return 0 + repeticoes(vetor, number, lenght - 1);
}
