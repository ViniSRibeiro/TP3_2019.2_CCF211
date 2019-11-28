//
// Created by vinicius on 26/11/2019.
//

#ifndef TP3_2019_2_CCF211_TAD_PALAVRA_H
#define TP3_2019_2_CCF211_TAD_PALAVRA_H

#endif //TP3_2019_2_CCF211_TAD_PALAVRA_H

#define TAMMAX 100
#define InicioArranjo 0
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct{
    char letra;
}TCaractere;


typedef struct Celula{
    TCaractere caractere;
    struct Celula *pProx;
}Tcelula;

typedef struct {
    Tcelula* pPrimeiro;
    Tcelula* pUltimo;
}TPalavra;

void FPVazia(TPalavra *pPalavra);
int PalavraEhVazia(TPalavra *pPalavra);
void InsereLetra(TPalavra *pPalavra, TCaractere caractere);
void RetiraLetra(TPalavra *pPalavra, TCaractere Caractere,TCaractere *pCaractere);
void ImprimePalavra (TPalavra *pPalavra);
void TamanhoPalavra(TPalavra *pPalavra);
