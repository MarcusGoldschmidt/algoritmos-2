#include <stdio.h>

typedef struct Taluno {
	float altura, pesso;
	char sexo;
} Taluno;

int main () {	
	Taluno usuario;
	
	printf("F | M\n");
	scanf("%c",&usuario.sexo);
	
	printf("Digite sua altura \n");
	scanf("%f",&usuario.altura);
	
	if (usuario.sexo == 'm' || usuario.sexo == 'M') {
		usuario.pesso = (72.6 * usuario.altura) - 58;
	}else {
		usuario.pesso = (62.1 * usuario.altura) - 44.7;
	}
	
	printf("IMC de %f \n", usuario.pesso);
}
