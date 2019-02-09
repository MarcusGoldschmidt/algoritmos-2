#include <stdio.h>
#include <stdlib.h>

int Ackerman(int m,int n);

int main()
{
	int m, n;
	
	printf("m: ");
	scanf(" %d", &m);
	
	printf("n: ");
	scanf(" %d", &n);
	
	printf("Resultado: %d", Ackerman(m,n));
	
	return 0;
}

int Ackerman(int m,int n){
	if(m == 0){
		return n + 1;
	}
	
	if((m > 0) && (n =0)){
		return Ackerman(n - 1, 1);
	}
	
	if((m > 0) && (n > 0)){
		return Ackerman(m - 1, Ackerman(m, n -1));
	}	
}
