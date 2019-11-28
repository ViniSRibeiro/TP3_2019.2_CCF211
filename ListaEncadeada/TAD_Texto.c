#include "TAD_texto.h"
#include "TAD_Texto.h"

void FTVazia_LEncadeada(Ttexto_LEncadeada *pTexto){
  pTexto->pPrimeiroTexto = (TcelulaTexto*) malloc(sizeof(TcelulaTexto));
  pTexto->pUltimoTexto = pTexto->pPrimeiroTexto;
  pTexto->pPrimeiroTexto->pProxTexto = NULL;
}

int TextoEhVazia_LEncadeada(Ttexto_LEncadeada *pTexto){
  return (pTexto->pPrimeiroTexto == pTexto->pUltimoTexto);
}
void InserePalavra_LEncadeada(Ttexto_LEncadeada *pTexto, TPalavra_LEncadeada palavra){
  pTexto->pUltimoTexto->pProxTexto = (TcelulaTexto*) malloc(sizeof(TcelulaTexto));
  pTexto->pUltimoTexto = pTexto->pUltimoTexto->pProxTexto;
  pTexto->pUltimoTexto->palavra = palavra;
  pTexto->pUltimoTexto->pProxTexto = NULL;
}

void RetiraPalavra_LEncadeada(Ttexto_LEncadeada *pTexto, TPalavra_LEncadeada palavra,TPalavra_LEncadeada *pPalavra){
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

void ImprimeTexto_LEncadeada(Ttexto_LEncadeada *pTexto){
  for (TcelulaTexto* i = pTexto->pPrimeiroTexto; i !=NULL; i = i->pProxTexto) {
    ImprimePalavra_LEncadeada(&pTexto->pPrimeiroTexto->palavra);
  }
}

int Tamanho_LEncadeada(Ttexto_LEncadeada *pTexto){
  int count = 0;
  for (TcelulaTexto* i = pTexto->pPrimeiroTexto; i !=NULL; i = i->pProxTexto) {
    count += 1;
  }
  return count;
}
