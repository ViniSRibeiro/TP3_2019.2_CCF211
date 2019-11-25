//
// Created by vinicius on 25/11/2019.
//

#ifndef TP3_2019_2_CCF211_TAD_BIBLIOTECA_H
#define TP3_2019_2_CCF211_TAD_BIBLIOTECA_H

#endif //TP3_2019_2_CCF211_TAD_BIBLIOTECA_H
#define size_biblioteca 100

#include "TAD_Texto.h"

typedef int Apontadorbiblioteca;

typedef struct{
    Ttexto biblioteca[size_biblioteca];
    Apontadorbiblioteca BibPrimeiro, BibUltimo;
}TBiblioteca;

void FBibVazia(TBiblioteca* PBiblioteca);
int BibEhVazia(TBiblioteca* PBiblioteca);
int InsereTexto(TBiblioteca* PBiblioteca, Ttexto* PTexto);
int RetiraTexto(TBiblioteca* PBiblioteca, Ttexto* PTexto);
