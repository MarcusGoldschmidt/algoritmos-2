#include <stdio.h>
#include <string.h>
typedef struct Tlivro{
    int code;
    char name[50];
    char autorsname[50];
    char type[20];
    char keyword_1[20];
    char keyword_2[20];
    char keyword_3[20];
}Tlivro;

int main(){
    
    int qtd,aux, humanas, bio, exatas;
    int menu, option,codigo;
    char keyword[20];
    menu = 0;
    printf("Quantidade de livros: ");
    scanf(" %d",&qtd);
    
    Tlivro livro[qtd];
    // Entrada
    
    for(int i=0;i<qtd;i++){
        printf("Código do Livro: ");
        scanf(" %d",&livro[i].code);
        printf("Nome do Livro: ");
        scanf(" %s",livro[i].name);
        printf("Nome do autor da obra: ");
        scanf(" %s",livro[i].autorsname);
        
        do{
            printf("Área [E]Exatas\n[H]Humanas \n[B]Biológicas: ");
            scanf(" %s",livro[i].type);
            if(strcmp(livro[i].type,"E") !=0 )
                exatas++;
            if(strcmp(livro[i].type,"H") != 0 )
                humanas++;
            if(strcmp(livro[i].type,"B") != 0 )
                bio++;
        }while((strcmp(livro[i].type,"E") !=0 )||(strcmp(livro[i].type,"H") != 0 )||(strcmp(livro[i].type,"B") != 0 ));
        
        printf("1º Palavra chave: ");
        scanf(" %s",livro[i].keyword_1);
        printf("2º Palavra chave: ");
        scanf(" %s",livro[i].keyword_2);
        printf("3º Palavra chave: ");
        scanf(" %s",livro[i].keyword_3);
    }
    // Ordenação
    for(int i=1;i<qtd;i++){
        for(int j=i-1; j<qtd;j++){
            if(livro[j].code > livro[j+1].code){
                aux = livro[j+1].code;
                livro[j+1].code = livro[j].code;
                livro[j].code = aux;
            }
        }
    }
    printf("Exagas: %d\nHumanas: %d\nBiologicas: %d\n", exatas, humanas, bio);
    
    
    do{
        printf("[1]Consulta por código\n [2]Consulta por palavra\n [3]Sair.\n");
        scanf(" %d",&option);
        if(option == 1 ){
            printf("Código : ");
            scanf(" %d",&codigo);
                for(int i = 0; i<qtd; i++){
                    if(codigo == livro[i].code){
                        printf("O nome: %s.\n ",livro[i].name);
                        printf("O autor: %s.\n ",livro[i].autorsname);
                        printf("O genero: %s.\n ",livro[i].type);
                    }
                    else if(codigo != livro[i].code)
                        printf("Não foram encontrados\n");
                }
        }
        else if(option == 2 ){
            printf("palavra-chave: \n ");
            scanf(" %s",keyword);
            
            for(int i = 0; i<qtd; i++){
                if((strcmp(keyword,livro[i].keyword_1) == 0) || (strcmp(keyword,livro[i].keyword_2) == 0) || (strcmp(keyword,livro[i].keyword_3) == 0)){ 
                    printf("O nome: %s.\n",livro[i].name);
                    printf("O autor: %s.\n",livro[i].autorsname);
                    printf("O genero: %s.\n",livro[i].type);
                }
                else if((strcmp(keyword,livro[i].keyword_1) != 0) || (strcmp(keyword,livro[i].keyword_2) != 0) || (strcmp(keyword,livro[i].keyword_3) != 0)){
                    printf("Não encontrado\n");
				}
			}
        }else if(option == 3 ){
            menu++;
        }
    }while(menu == 0);
   
   return 0;
}

