#include "TAD_texto.h"

void FTVazia(Ttexto *pTexto){
  pTexto->pPrimeiroTexto = (TcelulaTexto*) malloc(sizeof(TcelulaTexto));
  pTexto->pUltimoTexto = pTexto->pPrimeiroTexto;
  pTexto->pPrimeiroTexto->pProxTexto = NULL;
}

int TextoEhVazia(Ttexto *pTexto){
  return (pTexto->pPrimeiroTexto == pTexto->pUltimoTexto);
}
void InserePalavra(Ttexto *pTexto, TPalavra palavra){
  pTexto->pUltimoTexto->pProxTexto = (TcelulaTexto*) malloc(sizeof(TcelulaTexto));
  pTexto->pUltimoTexto = pTexto->pUltimoTexto->pProxTexto;
  pTexto->pUltimoTexto->palavra = palavra;
  pTexto->pUltimoTexto->pProxTexto = NULL;
}

void RetiraPalavra(Ttexto *pTexto, TPalavra palavra,TPalavra *pPalavra){
  /*TcelulaTexto* pAuxTexto;
  for (TcelulaTexto* i = pTexto->pPrimeiroTexto; i != NULL; i = i->pProxTexto) {
    if(i->palavra == palavra){
      pPalavra = i->palavra;
      pAuxTexto = i;
      i = i->pProxTexto;
      free(pAuxTexto);
    }
  }*/
}

void ImprimeTexto(Ttexto *pTexto){
  for (TcelulaTexto* i = pTexto->pPrimeiroTexto; i !=NULL; i = i->pProxTexto) {
    ImprimePalavra(&pTexto->pPrimeiroTexto->palavra);
  }
}

int Tamanho(Ttexto *pTexto){
  int count = 0;
  for (TcelulaTexto* i = pTexto->pPrimeiroTexto; i !=NULL; i = i->pProxTexto) {
    count += 1;
  }
  return count;
}
