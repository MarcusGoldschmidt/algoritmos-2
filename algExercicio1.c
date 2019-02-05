/*
 * NOME: Marcus Goldschmidt Oliveira
 * RGA: 201811310020
 * Exercicio: (1)
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct TPar{
	int x, y;
}TPar;

double yCalLinha(TPar *ponto,int lenght);
double xCalLinha(TPar *ponto,int lenght);
double calculoB(TPar *ponto,int lenght);
double ajustamnetoDaReta(TPar *ponto, double XLinha, double YLinha, int lenght);

int main()
{
	char validador = 'Y';
	TPar *ponto;
	int aux = 0;
	double xLinha, yLinha;
	double a,b,R;
	
	ponto = (TPar *) malloc(sizeof(TPar));
	
	// Inserção do valores
	while(validador != 'n'){
		
		printf("Ponto %d x: ", aux);
		scanf(" %d",&ponto[aux].x);
		
		printf("Ponto %d y: ", aux);
		scanf(" %d",&ponto[aux].y);
		
		ponto = (TPar *) realloc(ponto, sizeof(TPar) * (aux + 1));
		
		printf("Deseja inserir mais um conjunto?(Y/n)");
		scanf(" %c",&validador);
		aux++;
	}
	
	xLinha = xCalLinha(ponto, aux);
	yLinha = yCalLinha(ponto, aux);
	
	b = calculoB(ponto,aux);
	
	a = yLinha - b *xLinha;
	
	R = ajustamnetoDaReta(ponto,xLinha, yLinha, aux);
	
	printf("F(x) = %lfx + %lf\n",a,b);
	printf("Intervalo de variação: %lf", R);
	
	return 0;
}

double xCalLinha(TPar *ponto,int lenght){
	double somatoria;
	
	for(int i = 0; i < lenght;i++){
		somatoria += ponto[i].x;
	}
	
	return (1/lenght) * somatoria;
}

double yCalLinha(TPar *ponto,int lenght){
	double somatoria;
	
	for(int i = 0; i < lenght;i++){
		somatoria += ponto[i].y;
	}
	
	return (1/lenght) * somatoria;
}

double calculoB(TPar *ponto,int lenght){
	
	double numerador, denominador;
	
	for(int i = 0; i < lenght;i++){
		numerador += ponto[i].x * ponto[i].y;
		denominador += ponto[i].x * ponto[i].x;
	}
	
	return (numerador / denominador);
	
}

double ajustamnetoDaReta(TPar *ponto, double XLinha, double YLinha, int lenght){
	double numerador, denominador, denominador1, denominador2;
	
	for(int i = 0; i < lenght;i++){
		numerador += (ponto[i].x - XLinha) * (ponto[i].y - YLinha);
		denominador1 += pow((ponto[i].x - XLinha), 2);
		denominador2 += pow((ponto[i].y - YLinha),2);
	}
	
	denominador = sqrt(denominador1 * denominador2);
	
	return (numerador / denominador);
	
}
