#include <stdio.h>
#include <stdlib.h>

int mod(int x,int y);

int main()
{
	
	int x, y;
	
	printf("x: ");
	scanf(" %d", &x);
	
	printf("y: ");
	scanf(" %d", &y);
	
	printf("Resultado: %d", mod(x,y));
	
	return 0;
}

int mod(int x,int y){
	if(x == y){
		return 0;
	}
	
	if(x < y){
		return x;
	}
	
	// Não precisa de if aqui
	return mod(x - y, y);
}

