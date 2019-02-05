#include <stdio.h>
#include <stdlib.h>

typedef struct TPosicao{
	int valor;
	int i;
	int j;
}TPosicao;

int main()
{
	
	int matriz[4][5];
	TPosicao auxMax, auxMin;
	
	for(int i = 0; i < 4; i++){		
		for(int j = 0; j < 5; j++){
			matriz[i][j] = rand() % 10;
		}
	}
	
	auxMax.valor = matriz[1][1];
	auxMax.i = 1;
	auxMax.j = 1;
	auxMin.valor = matriz[1][1];
	auxMin.i = 1;
	auxMin.j = 1;
	
	for(int i = 0; i < 4; i++){		
		for(int j = 0; j < 5; j++){
			if(matriz[i][j] > auxMax.valor){
				auxMax.valor = matriz[i][j];
				auxMax.i = i;
				auxMax.j = j;
			}else if(matriz[i][j] < auxMin.valor){
				auxMin.valor = matriz[i][j];
				auxMin.i = i;
				auxMin.j = j;
			}
		}
	}
	
	printf("Max: %d (%d,%d)\n",auxMax.valor, auxMax.i, auxMax.j);
	printf("Min: %d (%d,%d)\n",auxMin.valor, auxMin.i, auxMin.j);
	
	return 0;
}

