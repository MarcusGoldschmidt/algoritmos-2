#include <stdlib.h>
#include <stdio.h>

int funcaoR(int valor, int elevado);

int main()
{
	printf("%d\n", funcaoR(2, 5));
	
	return 0;
}

int funcaoR(int valor, int elevado){	
	if(elevado == 1){
		return valor;
	}
	
	return valor * funcaoR(valor, elevado - 1);
	
}

