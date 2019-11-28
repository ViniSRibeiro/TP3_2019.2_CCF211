#ifndef TP3_2019_2_CCF211_TAD_PALAVRA_H
#define TP3_2019_2_CCF211_TAD_PALAVRA_H

#endif //TP3_2019_2_CCF211_TAD_PALAVRA_H

#include "TAD_Palavra.h"

typedef struct CelulaTexto{
  TPalavra palavra;
  struct CelulaTexto *pProxTexto;
}TcelulaTexto;//CELULA

typedef struct{
  TcelulaTexto* pPrimeiroTexto;
  TcelulaTexto* pUltimoTexto;
}Ttexto;//TAD LISTA

void FTVazia(Ttexto *pTexto);
int TextoEhVazia(Ttexto *pTexto);
void InserePalavra(Ttexto *pTexto, TPalavra palavra);
void RetiraPalavra(Ttexto *pTexto, TPalavra palavra,TPalavra *pPalavra);
void ImprimeTexto(Ttexto *pTexto);
int Tamanho(Ttexto *pTexto);
