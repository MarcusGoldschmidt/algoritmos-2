#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TProfissao{
	int codigo;
	char nome[50];
}TProfissao;

void storeProfissao(TProfissao *registro, FILE *write, int count);
void procurarCodigo(int codigo, TProfissao *profissoes, int count, TProfissao *show);
// Auxilaires
int countProfissoes(FILE *read);
void ordernarCodigo(TProfissao *profissao, int count);
void realizarTroca(TProfissao *profissao, int posicao);

TProfissao show(int codigo, FILE *registro);

int main(){
	FILE *file;
	TProfissao *profissoes;
	TProfissao show;
	int count = 0;
	int codigo;
	
	file = fopen("profissoes.dat", "rb");
	count = countProfissoes(file);
	// Alocando memória para o novo registro
	profissoes = (TProfissao *) malloc(sizeof(TProfissao) * count + 1);
	// Lendo registros
	fread(profissoes, sizeof(TProfissao), count, file);
	
	fclose(file);
	
	printf("Codigo: ");
	scanf(" %d", &profissoes[count].codigo);
	
	printf("Nome: ");
	scanf(" %s", profissoes[count].nome);
	
	file = fopen("profissoes.dat", "wb+");
	
	storeProfissao(profissoes, file, count+1);
	
	printf("Procurar por codigo: ");
	scanf(" %d", &codigo);
	
	procurarCodigo(codigo, profissoes, count + 1, &show);
	
	printf("CODIGO: %d\n", show.codigo);
	printf("NOME: %s\n", show.nome);
	
	fclose(file);
	free(profissoes);
	return 0;
}

void procurarCodigo(int codigo, TProfissao *profissoes, int count, TProfissao *show){
	
	for(int i = 0; i < count; i++){
		if(profissoes[i].codigo == codigo){
			show->codigo = profissoes[i].codigo;
			strcpy(show->nome, profissoes[i].nome);
		}
	}
}

int countProfissoes(FILE *registro){
	TProfissao buffer;
	int count = 0;
	
	while(fread(&buffer, sizeof(TProfissao), 1,registro) != 0){
		count++;
	}
	
	// Arquivo volta para o inicio
	fseek(registro, 0,SEEK_SET);
	
	return count;
}

void storeProfissao(TProfissao *registro, FILE *write, int count){
	
	// Ordenando por booble
	ordernarCodigo(registro, count);
	
	// Escrevendo no arquivo
	fwrite(registro, sizeof(TProfissao), count, write);
	fflush(write);
}

void ordernarCodigo(TProfissao *profissao, int tamanhoVetor){
	int validador = 1;
	
	while(validador == 1){
		validador = 0;
		for(int i  = 0; i < tamanhoVetor - 1; i++){
			// Por ordem alfabética
			if(strncmp(profissao[i].nome, profissao[i + 1].nome, 4) > 0){
			
				realizarTroca(profissao, i);
			
				validador = 1;
			}
		}
	}
}

void realizarTroca(TProfissao *profissao, int posicao){
	TProfissao auxTroca;
	
	// auxTroca = profissao[i + 1];
	auxTroca.codigo = profissao[posicao + 1].codigo;
	strcpy(auxTroca.nome, profissao[posicao + 1].nome);
	// profissao[i + 1] = profissao[i];
	profissao[posicao + 1].codigo = profissao[posicao].codigo;
	strcpy(profissao[posicao + 1].nome, profissao[posicao].nome);
	// profissao[i] = auxTroca;
	profissao[posicao].codigo = auxTroca.codigo;
	strcpy(profissao[posicao].nome, auxTroca.nome);
}
