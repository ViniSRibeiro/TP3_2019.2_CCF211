#include "tadPalavra.h"

void FazPalavraVazia(Palavra *palavra){
    palavra->Primeiro = InicioArranjo;
    palavra->Ultimo = palavra->Primeiro;
}

int PalavraVazia(Palavra *palavra){
    return(palavra->Ultimo == palavra->Primeiro);
}

void InsereLetra(Palavra *palavra, Caractere caractere){
   // if(palavra ->Ultimo == TAMMAX) return 0; //vetor cheio
    palavra->caractere[palavra->Ultimo].letra = caractere.letra;
    //strcpy(palavra->caractere[palavra->Ultimo].letra,caractere.letra);
    palavra->Ultimo +=1;
    //return 1;
}

void RetiraLetra(Palavra *palavra,int Posicao, Caractere *caractere){
    int cont;
  //  if(PalavraVazia(palavra) || Posicao >= palavra->Ultimo || Posicao < 0) return 0;

    *caractere = palavra->caractere[Posicao];
    palavra->Ultimo--;
    for(cont = Posicao + 1; cont <= palavra->Ultimo; cont++){
        palavra->caractere[cont - 1] = palavra->caractere[cont];
    }
  //  return 1;
}
void ImprimePalavra (Palavra *palavra){
    for(int i = palavra->Primeiro; i < palavra->Ultimo; i++){
        printf("%c", palavra->caractere[i].letra);
    }
    printf("\n");
}
