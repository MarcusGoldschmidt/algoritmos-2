#include <stdio.h>
#include <stdlib.h>

// Dentro da mesma pasta
#include "mensagens.h"

int main()
{
	char numero[5];
	
	printf("Numero: ");
	scanf(" %s", numero);
	
	printf(" %d\n", binToDec(numero));
	
	return 0;
}

