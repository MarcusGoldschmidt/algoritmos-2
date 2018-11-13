#include <stdio.h>

int main()
{	
	int a[10];
	
	for(int i = 0; i < 10; i++){
		a[i] = i * 5;
		printf("%d = %d\n",i,a[i]);
	}
	
	return 0;
}

