#ifndef __MENSAGEM_H_
#define __MENSAGEM_H_

typedef enum mensagem{MSG_SALARIO = 1, MSG_NOME, MSG_ENDERECO}TMensagem;

void limpaTela();

void exibeMsg(TMensagem);

#endif
