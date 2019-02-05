#include <stdio.h>
#include <string.h>

typedef struct Taluno{
    int RGA;
    int faltas;
    float percentual;
    char freq[16];
}Taluno;

int main(){
    
    int num;
    Taluno alunos[40];
    
    printf(" Digite o numero de matrículas: ");
    scanf("%d",&num);
    for(int i = 0; i<num; i++){
        alunos[i].faltas = 0;
        alunos[i].percentual = 0;
    }
    for(int i= 0;i<num;i++){
        
        printf("Insira o RGA do aluno: \n");
        scanf(" %d",&alunos[i].RGA);
        
        printf("Preencha os campos a seguir com [P]Presente ou [F]Falta.\n");
        
            for(int j=0; j<16;j++){
                printf(" \nPresença na aula [%d]: ",j + 1);
                scanf(" %s",&alunos[i].freq[j]);
                if(alunos[i].freq[j] == 'F'){
                    alunos[i].faltas++;
                    alunos[i].percentual =  ((16 - alunos[i].faltas)/16 )*100;
				}
            }
        
        printf("%d\n",alunos[i].faltas );
        
    }
    
     for(int i= 0;i<num;i++){
         printf("RGA: %d\n %f de faltas\n",alunos[i].RGA, alunos[i].percentual);
     }
    
    
}
