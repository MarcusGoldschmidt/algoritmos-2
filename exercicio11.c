#include <stdio.h>
#include <stdlib.h>

double somatoriaV(double *vetor, int tamanhoVetor);

int main()
{
	double *vetor;
	int aux;
	
	printf(" Tamanho do vetor: ");
	scanf(" %d", &aux);
	
	vetor = (double *) malloc(sizeof(double) * aux);
	
	for(int i = 1; i <= aux; i++){
		printf("Valor em [%d]: ", i);
		scanf(" %lf", &vetor[i]);
	}
	
	printf(" %lf", somatoriaV(vetor, aux));
	
	return 0;
}

double somatoriaV(double *vetor, int tamanhoVetor){
	
	if(tamanhoVetor == 0){
		return vetor[0];
	}
	
	return vetor[tamanhoVetor] + somatoriaV(vetor,tamanhoVetor - 1);
	
}
