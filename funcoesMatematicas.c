#include <stdio.h>
#include <math.h>
#include <stdlib.h>
// Biblioteca de strings
#include <string.h>

// Adiciona config para depuração
// -lm -ggdb

float volumeEsfera(float raio) {
	return (4/3) * M_PI * raio;
}

int main() {
	float x, x_rad, y, raio;
	
	printf("Digite valor de x \n");
	scanf("%f", &x);
	
	x_rad = M_PI * x /180;
	y = 2.5 * cos(fabs(x_rad/2));
	
	printf("y: %.3f | x: %.3f \n", y, x);
	
	// Volume
	printf("Digite valor do raio \n");
	scanf("%f", &raio);
	printf("V = %f", volumeEsfera(raio));
	
	return 0;
}
