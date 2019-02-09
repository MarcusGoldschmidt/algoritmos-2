#include <stdio.h>
#include <stdlib.h>

int repeticoes(int *vetor, int lenght, int numeros[9]);
void printRepeticoes(int *vetor, int lenght);
void verificaRepeticoes(int *vetor,int lenght,int *countNumber);

int main()
{
	
	int *vetor, aux;
		
	printf("Tamanho do vetor: ");
	scanf(" %d", &aux);
	
	vetor = (int *) malloc(sizeof(int) * aux);
	
	for(int i = 0; i < aux; i++){
		printf("Valor em [%d]: ", i + 1);
		scanf(" %d", &vetor[i]);
	}
	
	printRepeticoes(vetor, aux);
	
	return 0;
}

void printRepeticoes(int *vetor, int lenght) {
	int countNumber[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	
	verificaRepeticoes(vetor, lenght, countNumber);
	
	for (int i = 0; i < 10; i++)
		if (countNumber[i] != 0)
			printf("#%d - %d\n", i, countNumber[i]);
}

void verificaRepeticoes(int *vetor,int lenght,int *countNumber) {
	if(!lenght) return;
	
	countNumber[vetor[lenght-1]]++;
	verificaRepeticoes(vetor, lenght-1, countNumber);
}
