#include "TAD_Palavra.h"

/*
//teste feito com o tad palavra
int main() {
  int opcao = -1;
  TPalavra_LEncadeada palavra;
  TCaractere letra;
  while (opcao!=0) {
    printf("***********************[MENU PALAVRA]*****************\n");
    printf("* 1) - Inicializar palavra                           *\n");
    printf("* 2) - Inserir caractere                             *\n");
    printf("* 3) - Imprimir palavra                              *\n");
    printf("* 4) - Remover caractere                             *\n");
    printf("* 5) - Tamanho da palavra                            *\n");
    printf("* 0) - Sair                                          *\n");
    printf("******************************************************\n");
    scanf("%d",&opcao);
    if (opcao == 1) {

      FPVazia_LEncadeada(&palavra);

    }else if(opcao == 2){
        srand(time(NULL));
        int n = (rand()% (20 + 1 - 1)) + 1;
        srand(time(NULL));
        for(int i = 0; i < n; i++){
            letra.letra = (rand() % (122 + 1 - 97)) + 97;
            InsereLetra_LEncadeada(&palavra, letra);
         }
        printf("o tamanho gerado de palavra é %d\n", n);

    }else if(opcao == 3){

      ImprimePalavra_LEncadeada(&palavra);

    }else if(opcao == 4){
      TCaractere caractere1,caractere2;
      printf("Digite qual caractere deseja remover:\n");
      scanf("%c",&caractere1.letra);
      RetiraLetra_LEncadeada(&palavra,caractere1,&caractere2);
    }else if (opcao == 5) {

    }
  }

  return 0;
}

*/
// teste feito com o tad texto

int main() {
  int opcao = -1;
  TPalavra_LEncadeada palavra;
  TCaractere letra;
  
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

    }else if(opcao == 2){

    }else if(opcao == 3){


    }else if(opcao == 4){

    }else if (opcao == 5) {

    }
  }

  return 0;
}


//teste feito com o tad biblioteca