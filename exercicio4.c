/**

* Exercicio 4

* Nome: Marcus Goldschmidt Oliveira

* RGA: 201811310020

**/
#include <stdio.h>
#include <stdlib.h>

typedef struct Tmoedas {
	int um;
	int cinco;
	int vinteCinco;
	int cem;
}Tmoedas;

int main()
{
		
	float valorCompra;
	float valorPago;
	Tmoedas moedas = {0,0,0,0};
	float troco;
	
	printf("Valor Total (Decimal): ");
	scanf(" %f", &valorCompra);
	
	printf("Valor pago (Decimal): ");
	scanf(" %f", &valorPago);
	
	troco = valorPago - valorCompra;
	// troco para centavos
	troco *= 100;
	
	if(troco >= 100){
		moedas.cem = troco / 100;
		troco = (int) troco % 100;
	}
	
	if(troco >= 25){
		moedas.vinteCinco = troco / 25;
		troco = (int) troco % 25;
	}
	
	if(troco >= 5){
		moedas.cinco = troco / 5;
		troco = (int) troco % 5;
	}
	
	if(troco >= 1){
		moedas.um = troco / 1;
		troco = (int) troco % 1;
	}
	
	printf("Troco\n");
	printf("1,00$ => %d\n", moedas.cem);
	printf("0,25$ => %d\n", moedas.vinteCinco);
	printf("0,05$ => %d\n", moedas.cinco);
	printf("0,01$ => %d\n", moedas.um);
	
	return 0;
}

