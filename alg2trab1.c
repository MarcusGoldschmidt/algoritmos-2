/**

* Nome: Marcus Goldschmidt Oliveira

* RGA: 201811310020

**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Tdisciplina {
	char nome[50];
	float nota;
	int cargaHoraria;
	int semestre;
} Tdisciplina;

typedef struct Tficha {
	char nome[50];
	char rga[50];
	int qntDisciplinas;
	int materiasReprovadas;
	int materiasReprovadasUltimoSemestre;
	float rendimentoEscolar;
	int semestreAtual;
	Tdisciplina *disciplina;
} Tficha;

int main()
{
	int ganhador;
	int numFichas;
	float denominador, numerador;
	Tficha *ficha;
	
	printf("Numero de fichas: ");
	scanf(" %d", &numFichas);
	
	//Alocando memória de todas as fichas
	ficha = (Tficha *) malloc(sizeof(Tficha) * numFichas);

	for(int i = 0; i < numFichas; i++){
		
		printf("----------------\n");
		
		// Entrada de nome
		printf("Nome: ");
		scanf(" %[^\n]s", ficha[i].nome );

		// Entrada de RGA
		printf("RGA: ");
		scanf(" %[^\n]s", ficha[i].rga );
		
		// Toda ficha começa com 0 reprovações por deafault
		ficha[i].materiasReprovadas = 0;
		// Toda ficha começa com semestre = 1
		ficha[i].semestreAtual = 1;
		// materias reprovadas no ultimo semestre
		ficha[i].materiasReprovadasUltimoSemestre = 0;
		

		// Entrada de enumero de disciplinas
		printf("Numero de disciplinas: ");
		scanf(" %d", &ficha[i].qntDisciplinas);
		
		// Alocando memória para disciplina
		ficha[i].disciplina = (Tdisciplina *) malloc(sizeof(Tdisciplina) * ficha[i].qntDisciplinas);
		
		// Entradas das disciplinas
		for(int j = 0; j < ficha[i].qntDisciplinas; j++){
			
			printf("---------------------\n");
			
			// Entrada de nome
			printf("Nome: ");
			scanf(" %[^\n]s", ficha[i].disciplina[j].nome);
			
			// Entrada de Semestre
			printf("Semestre: ");
			scanf(" %d", &ficha[i].disciplina[j].semestre);

			// Entrada de carga Horária
			printf("Carga Horária: ");
			scanf(" %d", &ficha[i].disciplina[j].cargaHoraria);
			
			// Entrada de nota
			printf("Nota: ");
			scanf(" %f", &ficha[i].disciplina[j].nota);
			
			// Troca o valor do semestre
			if(ficha[i].disciplina[j].semestre > ficha[i].semestreAtual){
				ficha[i].semestreAtual = ficha[i].disciplina[j].semestre;
			}
			
			// Materias reprovadas ++ se nota < 5
			if(ficha[i].disciplina[j].nota < 5){
				++ficha[i].materiasReprovadas;
			}
		}
		
		//TODO: Materias reprovadas no ultimo semestre
		for(int j = 0; j < ficha[i].qntDisciplinas; j++){
			if(ficha[i].disciplina[j].nota < 5 && ficha[i].disciplina[j].semestre == ficha[i].semestreAtual){
				++ficha[i].materiasReprovadasUltimoSemestre;
			}
		}
		
		//TODO: Calculo do CRE
		numerador = 0;
		denominador = 0;
		for(int j = 0; j < ficha[i].qntDisciplinas; j++){
			numerador += (ficha[i].disciplina[j].nota * (float) ficha[i].disciplina[j].cargaHoraria);
			denominador += ficha[i].disciplina[j].cargaHoraria;
			printf("%f => %d\n",ficha[i].disciplina[j].nota,ficha[i].disciplina[j].cargaHoraria);
		}
		
		ficha[i].rendimentoEscolar = (numerador / denominador);
	}
	
	// Busca para saber o ganhador
	ganhador = 0;
	for(int i = 0; i < numFichas - 1; i++){
		if(ficha[i].rendimentoEscolar < ficha[i + 1].rendimentoEscolar && ficha[i].materiasReprovadas < ficha[i + 1].materiasReprovadas){
			ganhador = i + 1;
		}
	}
	
	// Imprimindo o ganhador
	
	printf("--------------------\n");
	
	printf("Nome: %s\n",ficha[ganhador].nome);
	printf("RGA: %s\n",ficha[ganhador].rga);
	printf("Rendimento: %f\n",ficha[ganhador].rendimentoEscolar);
	printf("Semestre atual: %d\n",ficha[ganhador].semestreAtual);
	printf("Disciplinas cursadas: %d\n",ficha[ganhador].qntDisciplinas);
	printf("Reprovadas: %d\n",ficha[ganhador].materiasReprovadas);
	printf("Reprovada ultimo semestre: %d\n",ficha[ganhador].materiasReprovadasUltimoSemestre);
	
	// Liberando os espaços da memória
	for(int i = 0; i < numFichas; i++){
		free(ficha[i].disciplina);
	}
	free(ficha);
	
	return 0;
}
