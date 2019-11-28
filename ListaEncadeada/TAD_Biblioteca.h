#ifndef TP3_2019_2_CCF211_TAD_PALAVRA_H
#define TP3_2019_2_CCF211_TAD_PALAVRA_H

#endif //TP3_2019_2_CCF211_TAD_PALAVRA_H

#include "TAD_Texto.h"

typedef struct CelulaBiblioteca{
  Ttexto texto;
  struct CelulaBiblioteca *pProxBiblioteca;
}TCelulaBiblioteca;

typedef struct{
  TCelulaBiblioteca* pPrimeiroBilioteca;
  TCelulaBiblioteca* pUltimoBiblioteca;
}TBiblioteca;//TAD LISTA

void FBVazia(TBiblioteca *pBiblioteca);
int BibliotecaEhVazia(TBiblioteca *pBiblioteca);
void InsereTexto(TBiblioteca *pBiblioteca, TCelulaBiblioteca *texto);
void RetiraTexto(TBiblioteca *pBiblioteca, TCelulaBiblioteca *texto);
void ImprimeBiblioteca(TBiblioteca *pBiblioteca);
int TamanhoBiblioteca(Ttexto *pBiblioteca);
