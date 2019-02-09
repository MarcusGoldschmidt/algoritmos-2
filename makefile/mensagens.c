#include <stdio.h>
#include <stdlib.h>

void limpaTela(){
	system("clear");
	printf("##########################################\n");
	printf("                UFMT   -   IC             \n");
	printf("##########################################\n\n");
}

void exibeMsg(TMensagem t){
	
	switch (t)	{
		case MSG__NOME : printf("Entre com o nome");
		break;
		case MSG__ENDERECO : printf("Entre com o endereço");
		break;
		case MSG__SALARIO : printf("Entre com o salario");
		break;
	}
}

