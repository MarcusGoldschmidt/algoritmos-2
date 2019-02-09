#include <stdio.h>
#include <stdlib.h>

#include "venda.h"
#include "relatorios.h"

void limpaTela(){
	system("clear");
	printf("##########################################\n");
	printf("                TRABALHO DE LP             \n");
	printf("##########################################\n\n");
}

int exibeOpcoes(){
	int aux;
	
	printf("\n\n\n\n\n");
	printf("VENDA[1] RELATORIOS[2] SAIR[3]\n");
	printf("======================================\n::>");
	
	scanf(" %d", &aux);
	
	return aux;
}

void imprimeRelatorio(TRelatorioVenda relatorio){	
	char wait;
	
	printf("| ID | A | B | C | D | E | VALOR TOTAL |\n");
	for(int i = 0; i < relatorio.quantidade; i++){
		printf("| %d  |", i);
		printf(" %d |", relatorio.venda[i].quantA);
		printf(" %d |", relatorio.venda[i].quantB);
		printf(" %d |", relatorio.venda[i].quantC);
		printf(" %d |", relatorio.venda[i].quantD);
		printf(" %d |", relatorio.venda[i].quantE);
		if(relatorio.venda[i].valorTotal > 0){	
			printf("| %f |", relatorio.venda[i].valorTotal);
		}else{
			printf("  CANCELADA  |");
		}
		printf("\n");
	}
	printf("=================================================\n");
	printf("SAIR[0]\n::>");
	scanf(" %s", &wait);
}
