#include "TAD_Biblioteca.h"
#include <stdio.h>
#include <stdlib.h>
//gcc -o teste main.c TAD_Texto.c TAD_Texto.h TAD_Biblioteca.h TAD_Biblioteca.c TAD_Palavra.c TAD_Palavra.h
//main.c principal

int main(){
    TCaractere letrinha;
    TPalavra_Arranjo palavrinha;
    int op = -1,n;

    Ttexto_Arranjo texto;
    int opcao = -1;
    while (op != 0)
    {
      printf("********************[MENU PALAVRA]********************\n");
      printf("* 1) - Inicializar palavra                           *\n");
      printf("* 2) - Inserir palavra                               *\n");
      printf("* 3) - Imprimir palavra                              *\n");
      printf("* 4) - Remover letra                                 *\n");
      printf("* 5) - Tamanho da palavra                            *\n");
      printf("* 0) - Sair                                          *\n");
      printf("******************************************************\n");
        scanf("%d",&op);

        if(op == 1){
            FazPalavraVazia_Arranjo(&palavrinha);
        }
        else if(op == 2){
            printf("Insira o tamanho que deseja ter a palavra: ");
            scanf("%d",&n);
            srand(time(NULL));
            for(int i = 0; i < n; i++){
                letrinha.letra = (rand() % (122 + 1 - 97)) + 97;
                InsereLetra_Arranjo(&palavrinha, letrinha);
            }
        }
        else if(op == 3){
            ImprimePalavra_Arranjo(&palavrinha);
        }
        else if(op == 4){
            printf("Insira a posicao que deseja remover: ");
            scanf("%d",&n);
            RetiraLetra_Arranjo(&palavrinha, n, &letrinha);
            printf("A letra removida foi '%c'.\n",letrinha.letra);
        }
        else if(op == 5){
            TamanhoPalavra(&palavrinha);
        }
    }
/*
    ///////////////////////////////////////////////////////////////////////////

    while (opcao!=0) {
      printf("************************[MENU TEXTO]******************\n");
      printf("* 1) - Inicializar texto                             *\n");
      printf("* 2) - Inserir palvra Texto                          *\n");
      printf("* 3) - Imprimir texto                                *\n");
      printf("* 4) - Remover palvra no texto                       *\n");
      printf("* 5) - Tamanho da do texto                           *\n");
      printf("* 0) - Sair                                          *\n");
      printf("******************************************************\n");
      scanf("%d",&opcao);
      if (opcao == 1) {
        FazTextoVazia(&texto);//inicializa Texto
      }else if(opcao == 2){
        InserePalavra(&texto,palavrinha);
      }else if(opcao == 3){
        ImprimePalavra(&palavrinha);
        ImprimeTexto(&texto);
      }else if(opcao == 4){

      }else if (opcao == 5) {
        TamanhoTexto(&texto);
      }
    }*/
    }
