#include <stdio.h>

int main()
{	
	int a = 10;
	float b = 3.2;
	double c = 7.2231251;
	char nome[50] = "Carlos";
	
	// Alguns tipos de saida de dados
	printf("a = %d\nb = %f\nc = %lf\nNome = %s\n",a,b,c,nome);
	// imprime caractere pela tabela ASCII
	printf("%c \n",65);
	
	// Entrada de dados inteiro
	scanf(" %d",&a);
	printf("Numero inteiro a = %d \n",a);
	
	// Entrada de dados float
	scanf(" %f",&b);
	printf("Numero float b = %f \n",b);
	
	// Entrada de dados double
	scanf(" %lf",&c);
	printf("Numero Double c = %lf \n",c);

	// Entrada de dados String
	// %[^\n]s Para ler Streings com espaços
	scanf(" %[^\n]s",nome);
	printf("Numero String nome = %s \n",nome);
	
	return 0;
}
