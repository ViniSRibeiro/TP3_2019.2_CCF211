#ifndef TP3_2019_2_CCF211_TAD_PALAVRA_H
#define TP3_2019_2_CCF211_TAD_PALAVRA_H

#endif //TP3_2019_2_CCF211_TAD_PALAVRA_H

#include "TAD_Palavra.h"

typedef struct CelulaTexto{
  TPalavra_LEncadeada palavra;
  struct CelulaTexto *pProxTexto,*pAntTexto;
    int indice;
}TcelulaTexto;//CELULA

typedef struct{
  TcelulaTexto* pPrimeiroTexto;
  TcelulaTexto* pUltimoTexto;
  int tam_texto;
}Ttexto_LEncadeada;//TAD LISTA

void FTVazia_LEncadeada(Ttexto_LEncadeada *pTexto);
int TextoEhVazia_LEncadeada(Ttexto_LEncadeada *pTexto);
void InserePalavra_LEncadeada(Ttexto_LEncadeada *pTexto, TPalavra_LEncadeada palavra);
void RetiraPalavra_LEncadeada(Ttexto_LEncadeada *pTexto, TPalavra_LEncadeada palavra, TPalavra_LEncadeada *pPalavra);
void ImprimeTexto_LEncadeada(Ttexto_LEncadeada *pTexto);
int Tamanho_LEncadeada(Ttexto_LEncadeada *pTexto);
