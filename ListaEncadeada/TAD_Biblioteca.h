#ifndef TP3_2019_2_CCF211_TAD_PALAVRA_H
#define TP3_2019_2_CCF211_TAD_PALAVRA_H

#endif //TP3_2019_2_CCF211_TAD_PALAVRA_H

#include "TAD_Texto.h"

#include <stdio.h>
#include <stdlib.h>

typedef struct CelulaBilioteca* Apontador;
typedef struct CelulaBiblioteca{
  Ttexto_LEncadeada texto;
  struct CelulaBiblioteca *pProxBiblioteca;
    struct CelulaBiblioteca *pAntBiblioteca;
    int indice;
}TCelulaBiblioteca;

typedef struct{
  TCelulaBiblioteca *pPrimeiroBiblioteca;
  TCelulaBiblioteca *pUltimoBiblioteca;
}TBiblioteca_LEncadeada;

void FBVazia_LEncadeada(TBiblioteca_LEncadeada *pBiblioteca);
int BibliotecaEhVazia_LEncadeada(TBiblioteca_LEncadeada *pBiblioteca);
void InsereTexto_LEncadeada(TBiblioteca_LEncadeada *pBiblioteca, Ttexto_LEncadeada texto);
TCelulaBiblioteca* RetiraTexto_LEncadeada(TBiblioteca_LEncadeada *pBiblioteca,int n);
void ImprimeBiblioteca_LEncadeada(TBiblioteca_LEncadeada *pBiblioteca);
int TamanhoBiblioteca_LEncadeada(TBiblioteca_LEncadeada *pBiblioteca);
