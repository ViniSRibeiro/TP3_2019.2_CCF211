//
// Created by vinicius on 26/11/2019.
//

#include "TAD_Palavra.h"
#include <stdio.h>
void FPVazia_LEncadeada(TPalavra_LEncadeada *pPalavra){
    pPalavra->pPrimeiro = (Tcelula*) malloc(sizeof(Tcelula));
    pPalavra->pUltimo = pPalavra->pPrimeiro;
    pPalavra->pPrimeiro->pProx = NULL;
}

int PalavraEhVazia_LEncadeada(TPalavra_LEncadeada *pPalavra){
    return (pPalavra->pPrimeiro == pPalavra->pUltimo);
}

void InsereLetra_LEncadeada(TPalavra_LEncadeada *pPalavra, TCaractereEncadeada caractere){
    pPalavra->pUltimo->pProx = (Tcelula*) malloc(sizeof(Tcelula));
    pPalavra->pUltimo = pPalavra->pUltimo->pProx;
    pPalavra->pUltimo->caractere = caractere;
    pPalavra->pUltimo->pProx = NULL;
}

void RetiraLetra_LEncadeada(TPalavra_LEncadeada *pPalavra, TCaractereEncadeada Caractere, TCaractereEncadeada *pCaractere){
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

void ImprimePalavra_LEncadeada (TPalavra_LEncadeada *palavra){

    for (Tcelula* i = palavra->pPrimeiro->pProx; i != NULL ; i = i->pProx) {
        printf("%c",i->caractere.letra);
    }
    printf(" ");
}