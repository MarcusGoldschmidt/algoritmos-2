#ifndef __RELATORIO_H_
#define __RELATORIO_H_
#include "venda.h"

	typedef struct TRelatorioVenda{
		int quantidade;
		TVenda *venda;
	}TRelatorioVenda;
	
	void storeRelatorio(TVenda venda);
	
	TRelatorioVenda indexRelatorio();

#endif
