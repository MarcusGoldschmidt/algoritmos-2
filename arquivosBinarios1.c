#include <stdio.h>
#include <stdlib.h>

int main()
{
	int x = 1024;
	int read;
	FILE *arquivo;
	
	// Abrindo arquivo
	arquivo = fopen("binario.dat", "wb+");
	fwrite(&x, sizeof(int), 1, arquivo);
	fclose(arquivo);
	
	// Reabrindo o arquivo
	arquivo = fopen("binario.dat", "rb+");
	
	fread(&read, sizeof(int), 1,arquivo);
	printf("Numero: %d", read);
	
	fclose(arquivo);
	
	return 0;
}

