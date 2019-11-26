//
// Created by vinicius on 26/11/2019.
//

#include "TAD_Palavra.h"
#include <stdio.h>
void FPVazia(TPalavra *pPalavra){
    pPalavra->pPrimeiro = (Tcelula*) malloc(sizeof(Tcelula));
    pPalavra->pUltimo = pPalavra->pPrimeiro;
    pPalavra->pPrimeiro->pProx = NULL;
}

int PalavraEhVazia(TPalavra *pPalavra){
    return (pPalavra->pPrimeiro == pPalavra->pUltimo);
}

void InsereLetra(TPalavra *pPalavra, TCaractere caractere){
    pPalavra->pUltimo->pProx = (Tcelula*) malloc(sizeof(Tcelula));
    pPalavra->pUltimo = pPalavra->pUltimo->pProx;
    pPalavra->pUltimo->caractere = caractere;
    pPalavra->pUltimo->pProx = NULL;
}

void RetiraLetra(TPalavra *pPalavra, TCaractere Caractere,TCaractere *pCaractere){
    Tcelula* pAux;
    for (Tcelula* i = pPalavra->pPrimeiro; i != NULL ; i = i->pProx) {
        if(i->caractere.letra == Caractere.letra){
            *pCaractere = i->caractere;
            pAux = i;
            i = i->pProx;
            free(pAux);
        }
    }
}

void ImprimePalavra (TPalavra *pPalavra){
    for (Tcelula* i = pPalavra->pPrimeiro; i != NULL ; i = i->pProx) {
        printf("%c",i->caractere.letra);
    }
    printf("\n");
}