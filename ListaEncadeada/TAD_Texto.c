#include "TAD_Texto.h"

void FTVazia_LEncadeada(Ttexto_LEncadeada *pTexto){
  pTexto->pPrimeiroTexto = (TcelulaTexto*) malloc(sizeof(TcelulaTexto));
  pTexto->pPrimeiroTexto->indice = -1;
  pTexto->pUltimoTexto = pTexto->pPrimeiroTexto;
  pTexto->pPrimeiroTexto->pProxTexto = NULL;
  pTexto->pPrimeiroTexto->pAntTexto = NULL;
  pTexto->tam_texto = 0;
}

int TextoEhVazia_LEncadeada(Ttexto_LEncadeada *pTexto){
  return (pTexto->pPrimeiroTexto == pTexto->pUltimoTexto);
}
void InserePalavra_LEncadeada(Ttexto_LEncadeada *pTexto, TPalavra_LEncadeada palavra){
  pTexto->pUltimoTexto->pProxTexto = (TcelulaTexto*) malloc(sizeof(TcelulaTexto));
  pTexto->pUltimoTexto->pProxTexto->indice = pTexto->pUltimoTexto->indice+1;
  pTexto->pUltimoTexto->pProxTexto->pAntTexto = pTexto->pUltimoTexto; // a nova celula criada recebe o endereço da anterior para a lista duplamente encadeada
  pTexto->pUltimoTexto = pTexto->pUltimoTexto->pProxTexto;
  pTexto->pUltimoTexto->palavra = palavra;
  pTexto->pUltimoTexto->pProxTexto = NULL;
  pTexto->tam_texto ++;
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
  for (TcelulaTexto* i = pTexto->pPrimeiroTexto->pProxTexto; i !=NULL; i = i->pProxTexto) {
    ImprimePalavra_LEncadeada(&i->palavra);

  }
}

int Tamanho_LEncadeada(Ttexto_LEncadeada *pTexto){
  int count = 0;
  for (TcelulaTexto* i = pTexto->pPrimeiroTexto->pProxTexto; i !=NULL; i = i->pProxTexto) {
    count += 1;
  }
  return count;
}


