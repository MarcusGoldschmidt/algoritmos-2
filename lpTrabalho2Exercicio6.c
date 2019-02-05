#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(){
	int i, x = 0, y = 0;
	int Q, X, Y, Z, W, V;
	char tipo;
	int matriz[500][500];
	
	scanf(" %d", &Q);
	
	while (Q > 100000){
		scanf(" %d", &Q);
	}
	
	for (i=0; i<Q; i++){
		
		scanf(" %c", &tipo);
		
		if (tipo == 'U'){
			scanf(" %d", &X);
			scanf(" %d", &Y);
			scanf(" %d", &Z);
			scanf(" %d", &W);
			scanf(" %d", &V);
			
			if ((X >= 1) && (X <= Z) && (Z <= 500) && (Y >= 1) && (Y <= W) && (W <= 500) && (abs(V)<=5000)){	

				for (x = X; x < (Z + 1); x++){
					for (y = Y; y < (W + 1); y++){
						matriz[x][y] += V;
					}
				}
			}
		}
		else if (tipo == 'A'){
			scanf(" %d", &X);
			scanf(" %d", &Y);
			if ((X>=1) && (X<=500) && (Y>=1) && (Y<=500)){
				printf("\n%d\n",matriz[X][Y]);
			}
		}
	}
}
