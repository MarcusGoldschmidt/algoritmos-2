#include <stdlib.h>
#include <stdio.h>

int funcaoR(unsigned long long int valor);

int main()
{	
	for(int i = 0; i <= 50; i++){printf("%d => %d\n", i,funcaoR(i));}
	
	return 0;
}

int funcaoR(unsigned long long int valor){	
	if(valor == 0){
		return 0;
	}
	
	if(valor == 1){
		return 1;
	}
	
	return funcaoR(valor - 1) + funcaoR(valor - 2);
}

