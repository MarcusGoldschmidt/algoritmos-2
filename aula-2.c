#include <stdio.h>

int main () {
	
	int count = 0;
	
	float chico = 1.2;
	float ze = 1.1;
	
	do{
		chico += 0.02;
		ze += 0.03;
		
		count++;
	}while(chico > ze);
	
	printf("COUNT: %d", count);
	
}
