#include <stdio.h>
#include <string.h>

int main()
{
	char a[50],b[50];
	
	printf("Primeira Nome: \n");
	scanf(" %[^\n]s",a);
	
	printf("Segundo Nome: \n");
	scanf(" %[^\n]s",b);
	
	printf("---------\n");
	
	if (strcmp(a,b) > 0) {
		printf("%s %s \n", b,a);
	} else if (strcmp(a,b) < 0) {
		printf("%s %s \n", a,b);
	} else {
		printf("São iguais!\n");
	}
	
	int i = 0;
	
	while (i++ < 10) {
		printf("%d\n",i);
	}
	
	return 0;
}

