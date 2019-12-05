//
// Created by vinicius on 02/12/2019.
//

#include "QuickSort_LEncadeada.h"
#include <stdio.h>
int movimentacoesBib, movimentacoesText, comparacoesBib, comparacoesText;

int Distancia_Texto_LEncadeada(TcelulaTexto* pCelulaA,TcelulaTexto* pCelulaB){
    int cont = 0;
    TcelulaTexto* i;
    for (i = pCelulaA; i !=pCelulaB ; i = i->pProxTexto) {
        cont ++;
    }
    if (i == NULL && i !=pCelulaB){ //Nao achou andando para frente, precisa retroceder agora
        cont = 0;
        for (i = pCelulaA; i !=pCelulaB ; i = i->pAntTexto){
            cont --;
        }
    }
    return cont;
}

int Distancia_Bib_LEncadeada(TCelulaBiblioteca* pCelulaBibA, TCelulaBiblioteca* pCelulaBibB){
    int cont = 0;
    TCelulaBiblioteca * i;
    for (i = pCelulaBibA; i !=pCelulaBibB ; i = i->pProxBiblioteca) {
        cont ++;
    }
    if (i == NULL && i != pCelulaBibB){ //Nao achou andando para frente, precisa retroceder agora
        cont = 0;
        for (i = pCelulaBibA; i !=pCelulaBibB ; i = i->pAntBiblioteca){
            cont --;
        }
    }
    return cont;
}

void TrocaItens_Texto_QuickSort(TcelulaTexto* pCelulaA,TcelulaTexto* pCelulaB){
    TcelulaTexto pTemp;
    pTemp = *pCelulaA;
    *pCelulaA = *pCelulaB;
    *pCelulaB = pTemp;
}

void TrocaItens_Bib_QuickSort(TCelulaBiblioteca* pCelulaBibA, TCelulaBiblioteca* pCelulaBibB){
    TCelulaBiblioteca pTemp;
    pTemp.texto = pCelulaBibA->texto;
    pCelulaBibA->texto = pCelulaBibB->texto;
    pCelulaBibB->texto = pTemp.texto;
}

void QuickSort_Texto_LEncadeada(Ttexto_LEncadeada* pTex ){
    printf("Iniciou o QuickSort!\n");
    clock_t tF, tI = clock();
    double tempo;
    comparacoesText = 0; movimentacoesText = 0;
    tF = clock();
    Ordena_Texto_LEncadeada(0, pTex->pUltimoTexto->indice, pTex);
    tempo = (tF - tI) * 1000.0 / CLOCKS_PER_SEC;
    printf("Algoritmo Quick Sort:\n");
    printf("\tComparacoes: %d\n", comparacoesText);
    printf("\tMovimentacoes: %d\n", movimentacoesText);
    printf("\tTempo Total Gasto: %lf s\n", tempo/1000);

}

void Ordena_Texto_LEncadeada(int Esq, int Dir, Ttexto_LEncadeada* pTexto){
    printf("Iniciou o Ordena!\n");
    int i, j;

    Particao_texto_LEncadeada(Esq, Dir, &i, &j, pTexto);
    comparacoesText++;
    if (Esq < j ){
        Ordena_Texto_LEncadeada(Esq, j, pTexto);

    }
    comparacoesText++;
    if (i < Dir){
        Ordena_Texto_LEncadeada(i, Dir, pTexto);

    }
}


void Particao_texto_LEncadeada(int pEsq, int pDir, int *pI, int* pJ, Ttexto_LEncadeada * pTex){
    printf("Iniciou a Partiçao!\n");
    TPalavra_LEncadeada  Pivo;
    TcelulaTexto *auxI, *auxJ,*AuxPercorrer;

    auxI = pTex->pPrimeiroTexto;
    while(auxI->indice != pEsq && auxI->pProxTexto !=NULL){
        auxI = auxI->pProxTexto;
    }
    auxJ = pTex->pUltimoTexto;
    while (auxJ->indice != pDir && auxJ->pAntTexto != NULL){
        auxJ = auxJ->pAntTexto;
    }
    int tamanho_particao = (auxI->indice + auxJ->indice);
    AuxPercorrer = auxI;
    while (AuxPercorrer->indice != tamanho_particao/2 && AuxPercorrer->pProxTexto != NULL){
        AuxPercorrer = AuxPercorrer->pProxTexto;
    }
    Pivo = AuxPercorrer->palavra;
    //Pivo decidido

    while (auxI->indice <= auxJ->indice){
        comparacoesText++;
        while (Pivo.pPrimeiro->pProx->caractere.letra > auxI->palavra.pPrimeiro->pProx->caractere.letra ){
            comparacoesText++;
            auxI = auxI->pProxTexto;

        }
        while (Pivo.pPrimeiro->pProx->caractere.letra < auxJ->palavra.pPrimeiro->pProx->caractere.letra ){
            comparacoesText++;
            auxJ = auxJ->pAntTexto;
        }
        if(auxI->indice<= auxJ->indice){
            TrocaItens_Texto_QuickSort(auxI,auxJ);
            movimentacoesText += 3;
            auxI = auxI->pProxTexto;
            auxJ = auxJ->pAntTexto;
            printf("Itens trocados!\n");
        }

    }
    *pI = auxI->indice;
    *pJ =auxJ->indice;
}

void QuickSort_Bib_LEncadeada(TBiblioteca_LEncadeada* pBib){
    clock_t tF, tI = clock();
    double tempo;
    comparacoesText = 0; movimentacoesText = 0;
    tF = clock();

    Ordena_Bib_LEncadeda(0, pBib->pUltimoBiblioteca->pAntBiblioteca->indice, pBib);
    tempo = (tF - tI) * 1000.0 / CLOCKS_PER_SEC;
    printf("Algoritmo Quick Sort:\n");
    printf("\tComparacoes: %d\n", comparacoesBib);
    printf("\tMovimentacoes: %d\n", movimentacoesBib);
    printf("\tTempo Total Gasto: %lf s\n", tempo/1000);
}

void Ordena_Bib_LEncadeda(int Esq, int Dir, TBiblioteca_LEncadeada* pBib){

    int i, j;

    Particao_Bib_LEncadeada(Esq, Dir, &i, &j, pBib);
    comparacoesBib++;
    if (Esq < j ){
        Ordena_Bib_LEncadeda(Esq, j, pBib);
        //printf("A distancia entre pEsq e j eh %d\n ",Distancia_Bib_LEncadeada(pEsq,&j));
    }
    comparacoesBib++;
    if (i < Dir){
        Ordena_Bib_LEncadeda(i, Dir, pBib);
        //printf("A distancia entre i e pDir eh %d\n ",Distancia_Bib_LEncadeada(&i,pDir));
    }
}

void Particao_Bib_LEncadeada(int pEsq, int pDir, int *pI, int* pJ, TBiblioteca_LEncadeada* pBib){

    Ttexto_LEncadeada  Pivo;
    TCelulaBiblioteca *auxI, *auxJ,*AuxPercorrer;

    auxI = pBib->pPrimeiroBiblioteca;
    while(auxI->indice != pEsq && auxI->pProxBiblioteca !=NULL){
        auxI = auxI->pProxBiblioteca;
    }
    auxJ = pBib->pUltimoBiblioteca;
    while (auxJ->indice != pDir && auxJ->pAntBiblioteca != NULL){
        auxJ = auxJ->pAntBiblioteca;
    }
    int tamanho_particao = (auxI->indice + auxJ->indice);
    AuxPercorrer = auxI;
    while (AuxPercorrer->indice != tamanho_particao/2 && AuxPercorrer->pProxBiblioteca != NULL){
        AuxPercorrer = AuxPercorrer->pProxBiblioteca;
    }
    Pivo = AuxPercorrer->texto;
    //Pivo decidido

    while (auxI->indice <= auxJ->indice){
        comparacoesBib++;
        while (Pivo.tam_texto > auxI->texto.tam_texto ){
            comparacoesBib++;
            auxI = auxI->pProxBiblioteca;

        }
        while (Pivo.tam_texto < auxJ->texto.tam_texto ){
            comparacoesBib++;
            auxJ = auxJ->pAntBiblioteca;
        }
        if(auxI->indice<= auxJ->indice){
            TrocaItens_Bib_QuickSort(auxI,auxJ);
            movimentacoesBib += 3;
            auxI = auxI->pProxBiblioteca;
            auxJ = auxJ->pAntBiblioteca;

        }

    }
    *pI = auxI->indice;
    *pJ =auxJ->indice;

    return;
}