#include <stdio.h>

int main () {
	float media, mediaAux;
	
	for(int i = 0; i < 3; i++){	
		scanf("%f", &mediaAux);
		media = media + mediaAux;
	}
	
	media = media / 3;
	
	printf("Média de %f \n",media);
}
