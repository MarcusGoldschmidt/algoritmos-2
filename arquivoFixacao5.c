/*
 * ALUNO: MARCUS GOLDSCHMIDT OLIVIERA
 * RGA: 201811310020
 * 
 * Obs: arquivo de registro no ./ referente ao .c
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TFuncionario{
	char status;
	char nome[50];
	char cargo[50];
	float salario;
	int cargaHorario;
}TFuncionario;

void melhoresSalarios(FILE *cadastro, int salarioMinimo,char fileName[50]);

void atualizaCadastro(FILE *cadastro);

int main()
{
	FILE *cadastro;
	int aux = 0;
	
	cadastro = fopen("./cadastro.txt", "r");
	
	// Falha ao abrir o arquivo
	if(cadastro == NULL){
		printf("Falha ao abrir o arquivo.\n");
		return (-1);
	}
	
	printf("Teto Salarial: ");
	scanf(" %d", &aux);
	
	melhoresSalarios(cadastro, aux, "./melhoresSalarios.txt");
	
	atualizaCadastro(cadastro);
	
	fclose(cadastro);
	
	return 0;
}

// Criacao do arquivo
void melhoresSalarios(FILE *cadastro, int salarioMinimo,char fileName[50]){
	
	FILE *melhoresSalarios;
	TFuncionario *funcionario;
	char auxChar[50];
	int aux = 0;
	
	// Numero de funcionários
	while( fgets(auxChar, 50, cadastro) != NULL){
		aux++;
	}
	aux /= 5;

	// Voltando para o inicio doa arquivo
	rewind(cadastro);
	
	printf("Funcionarios: %d\n", aux);
	
	// Iniciando estrutura dos funcionarios
	funcionario = (TFuncionario *) malloc(sizeof(TFuncionario) * aux);
	
	// Passando dados do arquivo para a struct
	for(int i = 0; i < aux; i++){
		// Status
		fgets(auxChar, 3, cadastro);		
		funcionario[i].status = auxChar[0];
		//printf("%c\n",funcionario[i].status);		
		// Nome
		fgets(funcionario[i].nome, 50, cadastro);
		//printf("%s",funcionario[i].nome);	
		// Cargo
		fgets(funcionario[i].cargo, 50, cadastro);	
		//printf("%s",funcionario[i].cargo);	
		// Salario
		fgets(auxChar, 50, cadastro);
		//fscanf(cadastro, "%f", &funcionario[i].salario);
		funcionario[i].salario = strtod(auxChar,NULL);
		//printf("%.2f\n",funcionario[i].salario);
		// NumSalarioMin
				
		fgets(auxChar, 50, cadastro);
		//fscanf(cadastro, "%d", &funcionario[i].numSalarioMin);
		funcionario[i].cargaHorario = strtod(auxChar,NULL);
		//printf("%d\n",funcionario[i].cargaHorario);
			
		
		//printf("===================\n");
	}
		
	// Salvando Dados
	for(int i = 0; i < aux; i++){
		// Salario atual									salario base
		if(funcionario[i].salario > salarioMinimo){
			//funcionario[i].status[0] = 'D';
			//funcionario[i].status[1] = 0;
			funcionario[i].status = 'D';
		}
	}
	
	printf("Criando arquivo: %s \n", fileName);
	melhoresSalarios = fopen(fileName, "wb+");
	
	// Falha ao abrir o arquivo
	if(melhoresSalarios == NULL){
		printf("Falha ao abrir o arquivo.\n");
	}else{	
		// Salvando Dados no arquivo
		for(int i = 0; i < aux; i++){
			// Status
			fprintf(melhoresSalarios, "%c\n", funcionario[i].status );
			// nome
			fputs(funcionario[i].nome, melhoresSalarios);
			// Profissão
			fputs(funcionario[i].cargo, melhoresSalarios);
			// Salario
			sprintf(auxChar, "%.3f\n", funcionario[i].salario);
			fputs(auxChar, melhoresSalarios);
			// NumSalarioMin
			sprintf(auxChar, "%d\n", funcionario[i].cargaHorario);
			fputs(auxChar, melhoresSalarios);
		}
		fclose(melhoresSalarios);		
	}
}

void atualizaCadastro(FILE *cadastro){
	FILE *atualizaCadastro;
	TFuncionario *funcionario;
	char auxChar[50];
	int aux = 0;
	
	// Voltando ponteiro para o estado inicial
	rewind(cadastro);
	// Numero de funcionários
	while( fgets(auxChar, 50, cadastro) != NULL){
		aux++;
	}
	aux /= 5;
	
	printf("%d\n", aux);

	// Voltando para o inicio doa arquivo
	rewind(cadastro);
	
	// Iniciando funcionarios
	funcionario = (TFuncionario *) malloc(sizeof(TFuncionario) * aux);
	
	// Passando dados do arquivo para a struct
	for(int i = 0; i < aux; i++){
		fgets(auxChar, 3, cadastro);		
		funcionario[i].status = auxChar[0];;
		fgets(funcionario[i].nome, 50, cadastro);
		fgets(funcionario[i].cargo, 50, cadastro);
		fgets(auxChar, 50, cadastro);
		funcionario[i].salario = strtod(auxChar,NULL);
		fgets(auxChar, 50, cadastro);
		funcionario[i].cargaHorario = strtod(auxChar,NULL);
	}
	
	// Abrindo arquivo
	atualizaCadastro = fopen("./atualizaCadastro.txt", "w");
	
	if(atualizaCadastro == NULL){
		printf("Erro ao abrir o arquivo");
	} else {
		printf("Criado arquivo: ./atualizaCadastro.txt\n");
		
		// Escrever no arquivo
		for(int i = 0; i < aux; i++){
			if(funcionario[i].status == 'A'){
				// Status
				fprintf(atualizaCadastro, "%c\n", funcionario[i].status );
				// nome
				fputs(funcionario[i].nome, atualizaCadastro);
				// Profissão
				fputs(funcionario[i].cargo, atualizaCadastro);
				// Salario
				sprintf(auxChar, "%.3f\n", funcionario[i].salario);
				fputs(auxChar, atualizaCadastro);
				// NumSalarioMin
				sprintf(auxChar, "%d\n", funcionario[i].cargaHorario);
				fputs(auxChar, atualizaCadastro);
			}
		}
		fclose(atualizaCadastro);
	}
}
