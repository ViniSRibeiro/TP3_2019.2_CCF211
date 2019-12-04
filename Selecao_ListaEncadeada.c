//
// Created by vinicius on 28/11/2019.
//

#include "Selecao_ListaEncadeada.h"
#include <stdio.h>
void TrocaItens_Texto(TcelulaTexto* pCelulaA,TcelulaTexto* pCelulaB){ //TODO conferir o assign de ponteiros aqui
    TcelulaTexto pTemp;
    pTemp.palavra = pCelulaA->palavra;
    pCelulaA->palavra = pCelulaB->palavra;
    pCelulaB->palavra = pTemp.palavra;
}


void TrocaItens_Bib(TCelulaBiblioteca *pCelulaBibA, TCelulaBiblioteca *pCelulaBibB){
    TCelulaBiblioteca pTemp;
    pTemp.texto = pCelulaBibA->texto;
    pCelulaBibA->texto = pCelulaBibB->texto;
    pCelulaBibB->texto = pTemp.texto;

}

void SelectSort_Texto(Ttexto_LEncadeada* pTexto){
    TcelulaTexto pMin, *i , *j,*pPont;
   // int teste_ext=0,teste_int=0;
   // printf("Entrou no seleçao!\n");
    for(i = pTexto->pPrimeiroTexto->pProxTexto;i !=pTexto->pUltimoTexto->pProxTexto;i = i->pProxTexto){
      //  teste_ext++;
        pMin = *i;
        pPont = i;
        for(j=i->pProxTexto; j != pTexto->pUltimoTexto->pProxTexto ;j = j->pProxTexto){

         //   teste_int++;
            if(j->palavra.pPrimeiro->pProx->caractere.letra < pMin.palavra.pPrimeiro->pProx->caractere.letra ){ //compara a primeira letra valida, fora da celula cabeça
             //   printf("J eh %c e pMin eh %c \n",j->palavra.pPrimeiro->pProx->caractere.letra,pMin.palavra.pPrimeiro->caractere.letra);
                pMin = *j;
                pPont = j;

            }
     //       printf("For interno rodou %d vezes\n",teste_int+1);
        }
      //  teste_int = 0;

     //   printf("i eh %c e pMin eh %c\n",i->palavra.pPrimeiro->pProx->caractere.letra,pMin.palavra.pPrimeiro->caractere.letra);
        TrocaItens_Texto(pPont,i);

     //   printf("i eh %c e pMin eh %c, trocou!\n",i->palavra.pPrimeiro->pProx->caractere.letra,pMin.palavra.pPrimeiro->caractere.letra);

      //  printf("For Externo rodou %d vezes\n", teste_ext+1);
    }


}
void SelectSort_Bib(TBiblioteca_LEncadeada* pBib){
    TCelulaBiblioteca  pMin, *i , *j,*pPont;

    for (i = pBib->pPrimeiroBiblioteca->pProxBiblioteca ; i != pBib->pUltimoBiblioteca->pProxBiblioteca; i = i->pProxBiblioteca){

        pMin = *i;
        pPont = i;

        for (j = i->pProxBiblioteca; j!=pBib->pUltimoBiblioteca->pProxBiblioteca;j = j->pProxBiblioteca ){

            if(j->texto.tam_texto < pMin.texto.tam_texto){

                pMin = *j;
                pPont = j;
            }


        }


        TrocaItens_Bib(pPont,i);





    }
}