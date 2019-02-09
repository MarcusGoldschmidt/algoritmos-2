#ifndef __VENDA_H_
#define __VENDA_H_

	typedef struct TVenda{
		int quantA;
		int quantB;
		int quantC;
		int quantD;
		int quantE;
		float valorTotal;
	}TVenda;
	
	TVenda opcoesQuantidade(TVenda venda, char opcao);

	TVenda realizarVenda();
	
#endif
