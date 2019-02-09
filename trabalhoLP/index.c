#include <stdio.h>
#include <stdlib.h>

//Importações de funções
#include "tela.h"
#include "venda.h"
#include "relatorios.h"

int main()
{
	int aux;
	
	do{
		limpaTela();
		
		// Entrada de opções
		aux = exibeOpcoes();
	
		if(aux == 1){
			// Faz a venda e guarda o relatório
			limpaTela();
			storeRelatorio(realizarVenda());
		}else if(aux == 2){
			limpaTela();
			imprimeRelatorio(indexRelatorio());
		}
		
	}while(aux != 3);
	
	printf("Saindo...\n");
	
	return 0;
}
