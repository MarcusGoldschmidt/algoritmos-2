#include <stdio.h>
#include <stdlib.h>

typedef struct TNo{
	int info;
	struct TNo *prox;
}TNo;

TNo * iniciar();
int vazia(TNo *lista);
TNo * insereNode(TNo *lista, int info);
TNo * insereFinal(TNo *lista, int info);
void imprimeLista(TNo *lista);

int main() {
	TNo *lista;
	char auxLogico;
	int auxInt;
	
	lista = iniciar();
	
	do{
		printf("Inserir: ");
		scanf(" %d", &auxInt);
		lista = insereFinal(lista, auxInt);
		printf("continuar(S/n):");
		scanf(" %s", &auxLogico);
	}while(auxLogico != 'n');
	
	printf("-------------\n");
	
	imprimeLista(lista);
	
    return 0;
}

TNo * iniciar(){
	return NULL;
}
int vazia(TNo *lista){
	if(lista == NULL){
		return 1;
	}
	return 0;
}

TNo * insereNode(TNo *lista, int info){
	TNo *novoElemento;
	
	novoElemento = (TNo *) malloc(sizeof(TNo));
	novoElemento->info = info;
	
	if(novoElemento != NULL){
		novoElemento->prox = lista;
		lista = novoElemento;
	}
	
	return novoElemento;
}

TNo * insereFinal(TNo *lista, int info){
	TNo *novoElemento;
	TNo *aux;
	
	aux = lista;
	
	novoElemento = (TNo *) malloc(sizeof(TNo));
	novoElemento->info = info;
	
	if(vazia(lista) == 1){
		// Cria um novo elemento
		lista = novoElemento;
	}else{
		// Procurando ultimo da lista
		while(aux->prox != NULL){
			aux = aux->prox;
		}
		aux->prox = novoElemento;
	}
	
	return lista;
}

void imprimeLista(TNo *lista){
	TNo *aux;
	
	aux = lista;
	
	while(aux != NULL){
		printf("%d\n", aux->info);
		aux = aux->prox;
	}
}
