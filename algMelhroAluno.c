#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	
	int *idade, entrada;
	float media;
	
	printf("Entradas: ");
	scanf(" %d", &entrada);
	
	idade = (int *) malloc(sizeof(int) * entrada);
	
	for(int i = 0;i < entrada;i++){
		printf("valor[%d]: ",i);
		scanf(" %d", &idade[i]);
		media =+ idade[i];
	}	
	
	media = media / entradas;
	
	printf("Média de: %.2f", media);
	
	return 0;
}

