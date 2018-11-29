#include <stdio.h>
#include <stdlib.h>

typedef struct TEnumeros {
	int valor;
}	TEnumeros;

int main() {
	
	int *maior,*menor;
	int qnt;
	TEnumeros *entrada;
	
	printf("Valor de N:\n");
	scanf("%d", &qnt);
	printf("-----------\n");
	
	// Declarando vetor dinamicamente
	entrada = (TEnumeros *) malloc(sizeof(TEnumeros) * qnt);
	
	// Entradas
	for(int i = 0; i < qnt; i++) {
		scanf("%d", &entrada[i].valor);
	}
	
	printf("-----------\n");
	
	// Auxiliares
	maior = &entrada[0].valor;
	menor = &entrada[0].valor;
	
	// Busca de valores polarizados
	for(int i = 0; i < qnt; i++){
		if(*maior < entrada[i].valor){
			maior = &entrada[i].valor;
		}
		
		if(*menor > entrada[i].valor){
			menor = &entrada[i].valor;
		}
	}
	
	// Libernado memória
	free(entrada);
	
	printf("Maior: %d\n",*maior);
	printf("Menor: %d\n",*menor);
	
	return 0;
}
