#include "TAD_Texto.h"

void FazTextoVazia(Ttexto *pTexto){
    pTexto->TextoPrimeiro = InicioArranjo;
    pTexto->TextoUltimo = pTexto->TextoPrimeiro;
}

int TextoVazia(Ttexto *pTexto){
    return(pTexto->TextoUltimo == pTexto->TextoPrimeiro);
}

void InserePalavra(Ttexto *pTexto, TPalavra palavra){
    pTexto->vetorPalavra[pTexto->TextoUltimo] = palavra;
    pTexto->TextoUltimo +=1;
}

void RetiraPalavra(Ttexto *pTexto, int Posicao, TPalavra *pPalavra){
    int cont;
    *pPalavra = pTexto->vetorPalavra[Posicao];
    pTexto->TextoUltimo--;
    for(cont = Posicao + 1; cont <= pTexto->TextoUltimo; cont++){
        pTexto->vetorPalavra[cont - 1] = pTexto->vetorPalavra[cont];
    }
}
void ImprimeTexto(Ttexto *pTexto){
    for(int i = pTexto->TextoPrimeiro; i < pTexto->TextoUltimo; i++){
        ImprimePalavra(&pTexto->vetorPalavra[i]);
    }
    printf("\n");
}
void TamanhoTexto(Ttexto *pTexto){
  printf("Tamanho Texto %d\n",pTexto->TextoUltimo );
}