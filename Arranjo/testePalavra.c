#include "tadPalavra.h"
#include <stdio.h>
#include <stdlib.h>


int main(){
    Caractere letrinha;
    Palavra palavrinha;
    int op = -1,n;
    while (op != 0)
    {
        printf("------ MENU -------\n");
        printf("1 - Inicializar palavra\n");
        printf("2 - Inserir palavra\n");
        printf("3 - Imprimir palavra\n");
        printf("4 - Remover letra\n");
        printf("0 - Sair\n");
        printf("-------------------\n");
        scanf("%d",&op);

        if(op == 1){
            FazPalavraVazia(&palavrinha);
        }
        else if(op == 2){
            printf("Insira o tamanho que deseja ter a palavra: ");
            scanf("%d",&n);
            srand(time(NULL));
            for(int i = 0; i < n; i++){
                letrinha.letra = (rand() % (122 + 1 - 97)) + 97;
                InsereLetra(&palavrinha,letrinha); 
            }
        }
        else if(op == 3){
            ImprimePalavra(&palavrinha);
        }
        else if(op == 4){
            printf("Insira a posicao que deseja remover: ");
            scanf("%d",&n);
            RetiraLetra(&palavrinha,n,&letrinha);
            printf("A letra removida foi '%c'.\n",letrinha);
        }
    }

}