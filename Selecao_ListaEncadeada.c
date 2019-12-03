//
// Created by vinicius on 28/11/2019.
//

#include "Selecao_ListaEncadeada.h"
#include <stdio.h>
void TrocaItens_Texto(TcelulaTexto* pCelulaA,TcelulaTexto* pCelulaB){ //TODO conferir o assign de ponteiros aqui
    TcelulaTexto *pTemp;
    pTemp = pCelulaA;
    pCelulaA = pCelulaB;
    pCelulaB = pTemp;
}


void TrocaItens_Bib(TCelulaBiblioteca* pCelulaBibA, TCelulaBiblioteca* pCelulaBibB){
    TCelulaBiblioteca* pTemp;
    pTemp =pCelulaBibA;
    pCelulaBibA = pCelulaBibB;
    pCelulaBibB = pTemp;
}

void SelectSort_Texto(Ttexto_LEncadeada* pTexto){
    TcelulaTexto* pMin, *i , *j;
    for(i = pTexto->pPrimeiroTexto->pProxTexto;i !=NULL;i = i->pProxTexto){
        pMin = i;
        for(j=i->pProxTexto; j != NULL ;j = j->pProxTexto){
            if(j->palavra.pPrimeiro->pProx->caractere.letra < pMin->palavra.pPrimeiro->pProx->caractere.letra ){ //compara a primeira letra valida, fora da celula cabeça
                TrocaItens_Texto(pMin,j);
            }
        }
    }
}
void SelectSort_Bib(TBiblioteca_LEncadeada* pBib){
    TCelulaBiblioteca * pMin, *i , *j;
    for (i = pBib->pPrimeiroBiblioteca ; i!=NULL; i = i->pProxBiblioteca){
        pMin = i;
        for (j =i->pProxBiblioteca; j!=NULL;j = j->pProxBiblioteca ){
            if(j->texto.tam_texto < pMin->texto.tam_texto){
                TrocaItens_Bib(pMin,j);
            }
        }
    }
}