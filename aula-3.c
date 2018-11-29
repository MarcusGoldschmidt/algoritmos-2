#include <stdio.h>
#include <stdlib.h>

typedef struct TEsdutante {
	char nome[50];
	char curso[50];
	int anoIngresso;
	int qtdeDiscAprovados;
	float *notasDiscAprovadas;
}	TEsdutante;

int main() {
	
	TEsdutante *e;
	int qnt = 5;
	
	// Aloca 5 estudantes
	e = (TEsdutante *) malloc(sizeof(TEsdutante) * qnt);
	
	// Alcando notas
	for(int i = 0; i < qnt; i++) {
		e[i].qtdeDiscAprovados = 5;
		e[i].notasDiscAprovadas = (float *) malloc(sizeof(float) * e[i].qtdeDiscAprovados);
	}
	
	// Retirando espaço na memória interna
	for(int i; i < qnt; i++) {
		free(e[i].notasDiscAprovadas);
	}
	
	// Retirando memória de Alunos
	for(int i = 0; i < qnt; i++) {
		free(e);
	}
	
	free(e);
	
	return 0;
}
