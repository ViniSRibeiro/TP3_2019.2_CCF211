#include "TAD_Palavra.h"

void FazPalavraVazia_Arranjo(TPalavra_Arranjo *palavra){
    palavra->Primeiro = InicioArranjo;
    palavra->Ultimo = palavra->Primeiro;
}

int PalavraEhVazia_Arranjo(TPalavra_Arranjo *palavra){
    return(palavra->Ultimo == palavra->Primeiro);
}

void InsereLetra_Arranjo(TPalavra_Arranjo *palavra, TCaractereArranjo caractere){
     if(palavra ->Ultimo == TAMMAX){
        printf("Vetor cheio\n");
         exit ;} //vetor cheio
    palavra->caractere[palavra->Ultimo].letra = caractere.letra;
    palavra->Ultimo +=1;
    return ;
}

void RetiraLetra_Arranjo(TPalavra_Arranjo *palavra, int posicao, TCaractereArranjo *caractere){
    int cont;
  if(PalavraEhVazia_Arranjo(palavra) || posicao >= palavra->Ultimo || posicao < 0) exit;

    *caractere = palavra->caractere[posicao];
    palavra->Ultimo--;
    for(cont = posicao + 1; cont <= palavra->Ultimo; cont++){
        palavra->caractere[cont - 1] = palavra->caractere[cont];
    }
   return ;
}

void TamanhoPalavra(TPalavra_Arranjo *palavra){
  printf("Tamanho palavra: %d\n",palavra->Ultimo);
}

void ImprimePalavra_Arranjo (TPalavra_Arranjo *palavra){
    for(int i = palavra->Primeiro; i < palavra->Ultimo; i++){
        printf("%c", palavra->caractere[i].letra);
    }
    printf(" ");
}
