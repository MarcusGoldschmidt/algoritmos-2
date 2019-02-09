#include <stdio.h>
#include <stdlib.h>
#include "relatorios.h"
#include "venda.h"


TRelatorioVenda relatorio;
	
void storeRelatorio(TVenda venda){
	if(!relatorio.venda){
		// Primeira venda do dia
		relatorio.quantidade = 1;
		relatorio.venda = (TVenda *) malloc(sizeof(TVenda));
		
		// Salvando venda
		relatorio.venda[0] = venda;
	}else{
		relatorio.quantidade++;
		
		// Realocando memória
		relatorio.venda = (TVenda *) realloc(relatorio.venda, sizeof(TVenda) * relatorio.quantidade);
		
		relatorio.venda[relatorio.quantidade - 1] = venda;
		
		printf("Relatório Salvo!\n");
	}
}

TRelatorioVenda indexRelatorio(){
	return relatorio;
}
