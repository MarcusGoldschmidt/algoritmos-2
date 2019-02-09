#include <stdio.h>
#include <stdlib.h>

int binToDec(char number[5]){
	int aux = 1;
	int numeroFinal = 0;
	
	for(int i = 4; i >= 0; i--){
		
		if(number[i] == '1'){
			numeroFinal += aux;
		}
		
		aux *= 2;
	}
	
	return numeroFinal;
}


