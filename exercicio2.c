/**

* Exercicio 2

* Nome: Marcus Goldschmidt Oliveira

* RGA: 201811310020

**/
#include <stdio.h>
#include <stdlib.h>

int main()
{
	
	int x, fx, gx, hx, resultado;
	
	for(x = 1; x <=10; x++){
		// H(x)
		hx = (x * x) - 16;
		
		// F(x)
		if(hx >= 0){
			fx = hx;
		}else{
			fx = 1;
		}
		
		// G(x)
		if(fx == 0){
			gx = (x * x) + 16;
		}else if(fx > 0){
			gx = 0;
		}
		
		resultado = fx + gx;
	
		printf(" X | Valor\n %d | %d\n",x,resultado);
		
	}
	
	
	return 0;
}

