#include "tadTexto.h"

void FazTextoVazia(Ttexto *pTexto){
    pTexto->TextoPrimeiro = InicioArranjo;
    pTexto->TextoUltimo = pTexto->TextoPrimeiro;
}

int TextoVazia(Ttexto *pTexto){
    return(pTexto->TextoUltimo == pTexto->TextoPrimeiro);
}

void InserePalavra(Ttexto *pTexto, Palavra palavra){
    pTexto->vetorPalavra[pTexto->TextoUltimo] = palavra;
    pTexto->TextoUltimo +=1;
}

void RetiraPalavra(Ttexto *pTexto,int Posicao, Palavra *pPalavra){
    int cont;
    *pPalavra = pTexto->vetorPalavra[Posicao];
    pTexto->TextoUltimo--;
    for(cont = Posicao + 1; cont <= pTexto->TextoUltimo; cont++){
        pTexto->vetorPalavra[cont - 1] = pTexto->vetorPalavra[cont];
    }
}
void ImprimeTexto(Ttexto *pTexto){
    for(int i = pTexto->TextoPrimeiro; i < pTexto->TextoUltimo; i++){
        printf("%c", pTexto->vetorPalavra[i]);
    }
    printf("\n");
}
