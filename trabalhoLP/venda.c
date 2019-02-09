#include <stdio.h>
#include <stdlib.h>
#include "venda.h"
	
TVenda opcoesQuantidade(TVenda venda, char opcao){
	
	if(opcao != 'e'){
		printf("Quantidade::> ");
	}
	
	if(opcao == '1'){
		scanf(" %d", &venda.quantA);
	}else if(opcao == '2'){
		scanf(" %d", &venda.quantB);	
	}else if(opcao == '3'){
		scanf(" %d", &venda.quantC);
	}else if(opcao == '4'){
		scanf(" %d", &venda.quantD);
	}else if(opcao == '5'){
		scanf(" %d", &venda.quantE);
	}
	
	return venda;
}

TVenda realizarVenda(){
	
	TVenda venda;
	char opcao;
	
	venda.valorTotal = 0;
	venda.quantA = 0;
	venda.quantB = 0;
	venda.quantC = 0;
	venda.quantD = 0;
	venda.quantE = 0;
			
	do{
		printf("ADICIONAR A[1]\nADICIONAR B[2]\nADICIONAR C[3]\nADICIONAR D[4]\nADICIONAR A[5]\nCANCELAR VENDA[0]\n::>");
		scanf(" %s", &opcao);
		venda = opcoesQuantidade(venda, opcao);		
	}while(opcao != '0');
	
	// TODO:adicionar preços
	venda.valorTotal += venda.quantA * 1;
	venda.valorTotal += venda.quantB * 1;
	venda.valorTotal += venda.quantC * 1;
	venda.valorTotal += venda.quantD * 1;
	venda.valorTotal += venda.quantE * 1;
	
	return venda;
}
