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
}TCelulaBiblioteca;

typedef struct{
  TCelulaBiblioteca* pPrimeiroBilioteca;
  TCelulaBiblioteca* pUltimoBiblioteca;
}TBiblioteca_LEncadeada;

void FBVazia_LEncadeada(TBiblioteca_LEncadeada *pBiblioteca);
int BibliotecaEhVazia_LEncadeada(TBiblioteca_LEncadeada *pBiblioteca);
void InsereTexto_LEncadeada(TBiblioteca_LEncadeada *pBiblioteca, Ttexto_LEncadeada *texto);
void RetiraTexto_LEncadeada(TBiblioteca_LEncadeada *pBiblioteca, Ttexto_LEncadeada *texto, Ttexto_LEncadeada);
void ImprimeBiblioteca_LEncadeada(TBiblioteca_LEncadeada *pBiblioteca);
int TamanhoBiblioteca_LEncadeada(TBiblioteca_LEncadeada *pBiblioteca);
