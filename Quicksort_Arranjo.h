//
// Created by vinir on 02/12/2019.
//

#ifndef TP3_2019_2_CCF211_QUICKSORT_ARRANJO_H
#define TP3_2019_2_CCF211_QUICKSORT_ARRANJO_H

#endif //TP3_2019_2_CCF211_QUICKSORT_ARRANJO_H

#include "ListaEncadeada/TAD_Biblioteca.h"
#include "Arranjo/TAD_Biblioteca.h"

void ordenaForBib(int Esq, int Dir, TBiblioteca_Arranjo *listaDeBiblioteca);
void ordenaForText(int Esq, int Dir, Ttexto_Arranjo *listaDeTexto);
void particaoForBib(int Esq, int Dir, int *i, int *j,TBiblioteca_Arranjo *listaDeBiblioteca);
void particaoForText(int Esq, int Dir, int *i, int *j, Ttexto_Arranjo *listaDeTexto);
void quicksortForBib(TBiblioteca_Arranjo *listaDeBiblioteca, int tamBib);
void quicksortForText(Ttexto_Arranjo *listaDeTexto, int n);