//
// Created by vinicius on 26/11/2019.
//

#ifndef TP3_2019_2_CCF211_TAD_PALAVRA_H
#define TP3_2019_2_CCF211_TAD_PALAVRA_H

#endif //TP3_2019_2_CCF211_TAD_PALAVRA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct{
    char letra;
}TCaractereEncadeada;

typedef struct Celula{
    TCaractereEncadeada caractere;
    struct Celula *pProx;
}Tcelula;

typedef struct {
    Tcelula* pPrimeiro;
    Tcelula* pUltimo;
}TPalavra_LEncadeada;

void FPVazia_LEncadeada(TPalavra_LEncadeada *pPalavra);
int PalavraEhVazia_LEncadeada(TPalavra_LEncadeada *pPalavra);
void InsereLetra_LEncadeada(TPalavra_LEncadeada *pPalavra, TCaractereEncadeada caractere);
void RetiraLetra_LEncadeada(TPalavra_LEncadeada *pPalavra, TCaractereEncadeada Caractere, TCaractereEncadeada *pCaractere);
void ImprimePalavra_LEncadeada (TPalavra_LEncadeada *pPalavra);
void TamanhoPalavra_LEncadeada(TPalavra_LEncadeada *pPalavra);
