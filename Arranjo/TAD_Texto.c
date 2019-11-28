#include "TAD_Texto.h"

void FazTextoVazia(Ttexto_Arranjo *pTexto){
    pTexto->TextoPrimeiro = InicioArranjo;
    pTexto->TextoUltimo = pTexto->TextoPrimeiro;
}

int TextoVazia(Ttexto_Arranjo *pTexto){
    return(pTexto->TextoUltimo == pTexto->TextoPrimeiro);
}

void InserePalavra(Ttexto_Arranjo *pTexto, TPalavra_Arranjo palavra){
    pTexto->vetorPalavra[pTexto->TextoUltimo] = palavra;
    pTexto->TextoUltimo +=1;
}

void RetiraPalavra(Ttexto_Arranjo *pTexto, int Posicao, TPalavra_Arranjo *pPalavra){
    int cont;
    *pPalavra = pTexto->vetorPalavra[Posicao];
    pTexto->TextoUltimo--;
    for(cont = Posicao + 1; cont <= pTexto->TextoUltimo; cont++){
        pTexto->vetorPalavra[cont - 1] = pTexto->vetorPalavra[cont];
    }
}
void ImprimeTexto(Ttexto_Arranjo *pTexto){
    for(int i = pTexto->TextoPrimeiro; i < pTexto->TextoUltimo; i++){
        ImprimePalavra_Arranjo(&pTexto->vetorPalavra[i]);
    }
    printf("\n");
}
void TamanhoTexto(Ttexto_Arranjo *pTexto){
  printf("Tamanho Texto %d\n",pTexto->TextoUltimo );
}
