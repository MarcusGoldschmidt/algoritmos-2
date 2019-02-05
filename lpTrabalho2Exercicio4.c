#include <stdlib.h>
#include <stdio.h>

int main()
{	
	int matriz[5][5];
	int **matrizFinal;
	int aux = 0;
	
	// Entradas
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 5; j++){
			
			matriz[i][j] = rand() % 10;
			
			printf(" %d ",matriz[i][j]);
			//scanf(" %d", &matriz[i][j]);
			if(matriz[i][j] != 0){
				aux++;
			}
		}
		printf("\n");
	}
	
	printf("AUX SIZE: %d\n", aux);
	// Matriz do valores não nulos
	matrizFinal = malloc(sizeof(int *) * aux);
	
	for(int i = 0; i < aux; i++){
		matrizFinal[i] = (int *) malloc(sizeof(int) * 3);
	}
	
	// Pesquisas
	aux = 0;
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 5; j++){
			if(matriz[i][j] != 0){
				matrizFinal[aux][0] = matriz[i][j];
				matrizFinal[aux][1] = i;
				matrizFinal[aux][2] = j;
				
				aux++;
			}
		}
	}
	
	printf("== MATRIZ FINAL ==\n");
	
	for(int i = 0; i < aux; i++){
		printf("%d | %d | %d \n",matrizFinal[i][0],matrizFinal[i][1],matrizFinal[i][2]);
	}
	
	return 0;
}
