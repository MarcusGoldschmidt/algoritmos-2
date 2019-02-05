/*
 * NOME: Marcus Goldschmidt Oliveira
 * RGA: 201811310020
 * Exercicio: (2)
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double calculoSerie(double x, double aux);

int main()
{
	double entrada;
	double arctg;
	double aux = 1;
	double soma;
	int sinal = 1;
	
	do{
		printf("X: ");
		scanf(" %lf", &entrada);
		
		do{
			soma = calculoSerie(entrada,aux);
			if(soma >= 0.0001){
			
				arctg += (sinal * soma);
				
				sinal *= -1;
				
				aux += 3;
			}
		}while(soma >= 0.0001);
		
		printf("Valor: %lf\n", arctg);
	
	}while(entrada < 0);
	
	return 0;
}

double calculoSerie(double x, double aux){	
	return pow(x, aux) / 3;
}
