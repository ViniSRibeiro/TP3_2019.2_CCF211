#include "TAD_Palavra.h"

void FazPalavraVazia(TPalavra *palavra){
    palavra->Primeiro = InicioArranjo;
    palavra->Ultimo = palavra->Primeiro;
}

int PalavraVazia(TPalavra *palavra){
    return(palavra->Ultimo == palavra->Primeiro);
}

void InsereLetra(TPalavra *palavra, TCaractere caractere){
     //if(palavra ->Ultimo == TAMMAX){
     //    printf("Vetor cheio\n");
      //   exit ;} //vetor cheio
    palavra->caractere[palavra->Ultimo].letra = caractere.letra;
    palavra->Ultimo +=1;
    //return 1;
}

void RetiraLetra(TPalavra *palavra, int Posicao, TCaractere *caractere){
    int cont;
  //if(PalavraEhVazia(palavra) || Posicao >= palavra->Ultimo || Posicao < 0) exit;

    *caractere = palavra->caractere[Posicao];
    palavra->Ultimo--;
    for(cont = Posicao + 1; cont <= palavra->Ultimo; cont++){
        palavra->caractere[cont - 1] = palavra->caractere[cont];
    }
  //  return 1;
}

void TamanhoPalavra(TPalavra *palavra){
  printf("Tamanho palavra: %d\n",palavra->Ultimo);
}

void ImprimePalavra (TPalavra *palavra){
    for(int i = palavra->Primeiro; i < palavra->Ultimo; i++){
        printf("%c", palavra->caractere[i].letra);
    }
    printf("\n");
}