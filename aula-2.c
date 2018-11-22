#include <stdio.h>

int main () {
	int x , y, *p;
	y = 0;
	
	p = &y;
	x = *p;
	x = 4;
	(*p)++;
	--x;
	(*p) += x;
	
	// Print de Ponteiros
	printf("%X | %d \n",&x, x);
	printf("%X | %d \n",&y, y);
	printf("%X | %d \n",&p, *p);
}
