/* 
 * MARCUS GOLDSCHMIDT OLIVEIRA
 * RGA: 201811310020
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double raizQ(double x, double xLinha, double e);

int main()
{
	
	double x, xLinha, e;
	
	printf(" X: ");
	scanf(" %lf", &x);
	
	printf(" XLinha: ");
	scanf(" %lf", &xLinha);
	
	printf(" e: ");
	scanf(" %lf", &e);
	
	printf(" %lf", raizQ(x, xLinha, e));
	
	return 0;
}

double raizQ(double x, double xLinha, double e){
	
	if(((abs(xLinha * xLinha) - x)) <= e){
		return xLinha;
	}
	
	return raizQ(x, ((xLinha *xLinha) + x) / (2 * xLinha), e);
}
