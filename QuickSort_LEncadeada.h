//
// Created by vinicius on 02/12/2019.
//

#ifndef TP3_2019_2_CCF211_QUICKSORT_LENCADEADA_H
#define TP3_2019_2_CCF211_QUICKSORT_LENCADEADA_H

#endif //TP3_2019_2_CCF211_QUICKSORT_LENCADEADA_H
#include "ListaEncadeada/TAD_Biblioteca.h"
int Distancia_Texto_LEncadeada(TcelulaTexto* pCelulaA,TcelulaTexto* pCelulaB);
void TrocaItens_Texto_QuickSort(TcelulaTexto* pCelulaA,TcelulaTexto* pCelulaB);
int Distancia_Bib_LEncadeada(TCelulaBiblioteca* pCelulaBibA, TCelulaBiblioteca* pCelulaBibB);
void TrocaItens_Bib_QuickSort(TCelulaBiblioteca* pCelulaBibA, TCelulaBiblioteca* pCelulaBibB);
void QuickSort_Texto_LEncadeada(Ttexto_LEncadeada* pTexto);
void Ordena_Texto_LEncadeada(TcelulaTexto* pEsq, TcelulaTexto* pDir, Ttexto_LEncadeada* pTexto);
void Particao_texto_LEncadeada(TcelulaTexto* pEsq, TcelulaTexto*pDir, TcelulaTexto*pI, TcelulaTexto* pJ, Ttexto_LEncadeada* pTexto);
