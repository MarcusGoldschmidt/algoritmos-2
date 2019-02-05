#include <stdlib.h>
#include <stdio.h>

int funcaoR(int valor);

int main()
{
	printf(" %d\n", funcaoR(5));
	
	return 0;
}

int funcaoR(int valor){
	if(valor == 1){
		return 2;
	}else{
		return 10 * funcaoR(valor - 1) + 2;
	}
}

