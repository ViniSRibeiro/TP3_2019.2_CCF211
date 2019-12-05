//
// Created by vinicius on 02/12/2019.
//

#ifndef TP3_2019_2_CCF211_QUICKSORT_LENCADEADA_H
#define TP3_2019_2_CCF211_QUICKSORT_LENCADEADA_H

#endif //TP3_2019_2_CCF211_QUICKSORT_LENCADEADA_H
#include "Selecao_ListaEncadeada.h"
int Distancia_Texto_LEncadeada(TcelulaTexto* pCelulaA,TcelulaTexto* pCelulaB);
void TrocaItens_Texto_QuickSort(TcelulaTexto* pCelulaA,TcelulaTexto* pCelulaB);
int Distancia_Bib_LEncadeada(TCelulaBiblioteca* pCelulaBibA, TCelulaBiblioteca* pCelulaBibB);
void TrocaItens_Bib_QuickSort(TCelulaBiblioteca* pCelulaBibA, TCelulaBiblioteca* pCelulaBibB);
void QuickSort_Texto_LEncadeada(Ttexto_LEncadeada * pTex);
void Ordena_Texto_LEncadeada(int Esq, int Dir, Ttexto_LEncadeada * pTexto);
void Particao_texto_LEncadeada(int pEsq, int pDir, int *pI, int* pJ, Ttexto_LEncadeada * pTex);
void QuickSort_Bib_LEncadeada(TBiblioteca_LEncadeada* pBib);
void Ordena_Bib_LEncadeda(int Esq, int Dir, TBiblioteca_LEncadeada* pBib);
void Particao_Bib_LEncadeada(int pEsq, int pDir, int *pI, int* pJ, TBiblioteca_LEncadeada* pBib);
