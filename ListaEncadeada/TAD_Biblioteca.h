#ifndef TP3_2019_2_CCF211_TAD_PALAVRA_H
#define TP3_2019_2_CCF211_TAD_PALAVRA_H

#endif //TP3_2019_2_CCF211_TAD_PALAVRA_H

#include "TAD_Texto.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct CelulaBilioteca* Apontador;
typedef struct CelulaBiblioteca{
  Ttexto texto;
  struct CelulaBiblioteca *pProxBiblioteca;
}TCelulaBiblioteca;

typedef struct{
  TCelulaBiblioteca* pPrimeiroBilioteca;
  TCelulaBiblioteca* pUltimoBiblioteca;
}TBiblioteca;

void FBVazia(TBiblioteca *pBiblioteca);
int BibliotecaEhVazia(TBiblioteca *pBiblioteca);
void InsereTexto(TBiblioteca *pBiblioteca, Ttexto *texto);
void RetiraTexto(TBiblioteca *pBiblioteca, Ttexto *texto, Ttexto);
void ImprimeBiblioteca(TBiblioteca *pBiblioteca);
int TamanhoBiblioteca(TBiblioteca *pBiblioteca);
