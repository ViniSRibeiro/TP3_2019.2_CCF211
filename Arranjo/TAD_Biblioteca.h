//
// Created by vinicius on 25/11/2019.
//

#ifndef TP3_2019_2_CCF211_TAD_BIBLIOTECA_H
#define TP3_2019_2_CCF211_TAD_BIBLIOTECA_H

#endif //TP3_2019_2_CCF211_TAD_BIBLIOTECA_H


#include "TAD_Texto.h"

typedef int Apontadorbiblioteca;

typedef struct{
    Ttexto_Arranjo *biblioteca;
    Apontadorbiblioteca BibPrimeiro, BibUltimo;
    int tam_max;
}TBiblioteca_Arranjo;

void FBibVazia(TBiblioteca_Arranjo *PBiblioteca, int tamanho);
int BibEhVazia(TBiblioteca_Arranjo* PBiblioteca);
int InsereTexto(TBiblioteca_Arranjo* PBiblioteca, Ttexto_Arranjo PTexto);
void RetiraTexto(TBiblioteca_Arranjo* PBiblioteca,int Posicao, Ttexto_Arranjo* PTexto);
int ImprimeBib(TBiblioteca_Arranjo* PBiblioteca);
int TamanhoBib(TBiblioteca_Arranjo *PBiblioteca);
