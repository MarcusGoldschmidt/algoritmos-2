
#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 5

typedef struct TBolsista{
	int codigo;
	char nome[30];
	int tipo;
	char email[30];
}TBolsista;

int main()
{
	FILE *arquivo;
	TBolsista bolsista[TAMANHO], index[TAMANHO];
	
	printf("====== ENTRADA ======\n");
	
	// Entrando com os dados
	for(int i = 0; i < TAMANHO; i++){
		bolsista[i].codigo = i;
		printf("Nome: ");
		scanf(" %s", bolsista[i].nome);
		printf("Tipo: ");
		scanf(" %d", &bolsista[i].tipo);
		printf("Email: ");
		scanf(" %s", bolsista[i].email);
		printf("----------------------\n");
	}
	
	// Quardando os dados
	arquivo = fopen("bolsista.cad", "wb");
	fwrite(bolsista, sizeof(TBolsista), TAMANHO, arquivo);
	fclose(arquivo);
	
	printf("====== LENDO ARQUIVO ======\n");
	
	// Lendo o arquivo
	arquivo = fopen("bolsista.cad", "r");
	fread(index, sizeof(TBolsista), TAMANHO, arquivo);
	
	for(int i = 0; i < TAMANHO; i++){
		printf("Codigo: %d\n", bolsista[i].codigo);
		printf("Nome: %s\n", bolsista[i].nome);
		printf("Tipo: %d\n", bolsista[i].tipo);
		printf("Email: %s\n", bolsista[i].email);
		printf("--------------\n");
	}
	
	fclose(arquivo);
	
	return 0;
}

