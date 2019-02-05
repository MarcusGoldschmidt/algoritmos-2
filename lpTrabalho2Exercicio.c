#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{	
	char entrada[255],saida[255];	
	int chave;
	int aux = 0;
	
	// Entrada
	printf("Digite o texto: ");
	scanf(" %[^\n]s", entrada);
	printf("Digite a chave: ");
	scanf(" %d", &chave);
	
	for(int i = 0; i < strlen(entrada);i++){
		if(entrada[i] != ' '){
			saida[aux] = (int) entrada[i] - chave;
			aux++;
		}
	}
	
	printf("Saida: %s",saida);
	
	return 0;
}
