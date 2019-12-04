//
// Created by vinicius on 02/12/2019.
//

#include "QuickSort_LEncadeada.h"
#include <stdio.h>
int movimentacoesBib, movimentacoesText, comparacoesBib, comparacoesText;

int Distancia_Texto_LEncadeada(TcelulaTexto* pCelulaA,TcelulaTexto* pCelulaB){
    int cont = 0;
    TcelulaTexto* i;
    for (i = pCelulaA; i !=pCelulaB ; i = i->pProxTexto) {
        cont ++;
    }
    if (i == NULL && i !=pCelulaB){ //Nao achou andando para frente, precisa retroceder agora
        cont = 0;
        for (i = pCelulaA; i !=pCelulaB ; i = i->pAntTexto){
            cont --;
        }
    }
    return cont;
}
int Distancia_Bib_LEncadeada(TCelulaBiblioteca* pCelulaBibA, TCelulaBiblioteca* pCelulaBibB){
    int cont = 0;
    TCelulaBiblioteca * i;
    for (i = pCelulaBibA; i !=pCelulaBibB ; i = i->pProxBiblioteca) {
        cont ++;
    }
    if (i == NULL && i != pCelulaBibB){ //Nao achou andando para frente, precisa retroceder agora
        cont = 0;
        for (i = pCelulaBibA; i !=pCelulaBibB ; i = i->pAntBiblioteca){
            cont --;
        }
    }
    return cont;
}
void TrocaItens_Texto_QuickSort(TcelulaTexto* pCelulaA,TcelulaTexto* pCelulaB){
    TcelulaTexto pTemp;
    pTemp = *pCelulaA;
    *pCelulaA = *pCelulaB;
    *pCelulaB = pTemp;
}

void TrocaItens_Bib_QuickSort(TCelulaBiblioteca* pCelulaBibA, TCelulaBiblioteca* pCelulaBibB){
    TCelulaBiblioteca pTemp;
    pTemp.texto = pCelulaBibA->texto;
    pCelulaBibA->texto = pCelulaBibB->texto;
    pCelulaBibB->texto = pTemp.texto;
}
void Ordena_Texto_LEncadeada(TcelulaTexto* pEsq, TcelulaTexto* pDir, Ttexto_LEncadeada* pTexto){
    printf("Iniciou o Ordena!\n");
    TcelulaTexto i, j;

    Particao_texto_LEncadeada(pEsq,pDir,&i,&j,pTexto);
    comparacoesText++;
    if(pEsq!= pTexto->pPrimeiroTexto && pEsq != NULL && (Distancia_Texto_LEncadeada(pEsq,&j)>0)){ //caso a esquerda nao esteja apontando para Nulo nem para a celula cabeça e a distancia entre ele e o J seja maior que 0
        Ordena_Texto_LEncadeada(pEsq,&j,pTexto);
    }
    comparacoesText++;
    if(pDir != pTexto->pPrimeiroTexto && pDir != NULL && (Distancia_Texto_LEncadeada(&i,pDir)>0)){
        Ordena_Texto_LEncadeada(&i,pDir,pTexto);
    }
}
void QuickSort_Texto_LEncadeada(Ttexto_LEncadeada* pTexto){
    printf("Iniciou o QuickSort!\n");
    clock_t tF, tI = clock();
    double tempo;
    comparacoesText = 0; movimentacoesText = 0;
    tF = clock();
    Ordena_Texto_LEncadeada(pTexto->pPrimeiroTexto->pProxTexto, pTexto->pUltimoTexto, pTexto);
    tempo = (tF - tI) * 1000.0 / CLOCKS_PER_SEC;
    printf("Algoritmo Quick Sort:\n");
    printf("\tComparacoes: %d\n", comparacoesText);
    printf("\tMovimentacoes: %d\n", movimentacoesText);
    printf("\tTempo Total Gasto: %lf s\n", tempo/1000);

}



void Particao_texto_LEncadeada(TcelulaTexto* pEsq, TcelulaTexto*pDir, TcelulaTexto*pI, TcelulaTexto* pJ, Ttexto_LEncadeada* pTexto){
    printf("Iniciou a Partiçao!\n");
    TcelulaTexto * Pivo;
    int tamanho_particao = Distancia_Texto_LEncadeada(pEsq,pDir);
     pI = pEsq;
     pJ = pDir;
     Pivo = pEsq;
    for (int i = 0; i < tamanho_particao/2; ++i) {
        Pivo = Pivo->pProxTexto; //o pivo recebe o endereço do item no meio da partiçao
    }
    do{
        comparacoesText++;
        while (Pivo->palavra.pPrimeiro->pProx->caractere.letra > pI->palavra.pPrimeiro->pProx->caractere.letra){
            pI = pI->pProxTexto;
            comparacoesText++;
        } //se a primeira letra valida da palavra do pivo for maior que a primeira letra valida da palavra do pI, pI avança para a proxima celula //TODO verificar essa condiçao
        while (Pivo->palavra.pPrimeiro->pProx->caractere.letra < pJ->palavra.pPrimeiro->pProx->caractere.letra){
            comparacoesText++;
            pJ = pJ->pAntTexto;
        }
        if(Distancia_Texto_LEncadeada(pI,pJ)>=0){
            TrocaItens_Texto_QuickSort(pI,pJ);
            movimentacoesText +=3;
            pI = pI->pProxTexto;
            pJ = pJ->pAntTexto;
        } //Troca o conteudo de I por J
    }while (Distancia_Texto_LEncadeada(pI,pJ)>= 0); //Enquanto a distancia entre I e J for maior ou igual a 0, quando for negativa e pq se cruzaram
}
void Ordena_Bib_LEncadeda(TCelulaBiblioteca* pEsq, TCelulaBiblioteca* pDir, TBiblioteca_LEncadeada* pBib){
    printf("Iniciou o Ordena da lista encadeada!\n");
    TCelulaBiblioteca i, j;

    Particao_Bib_LEncadeada(pEsq,pDir,&i,&j,pBib);
    comparacoesBib++;
    if (pEsq != pBib->pPrimeiroBiblioteca && pEsq != NULL && (Distancia_Bib_LEncadeada(pEsq,&j)>0)){
        Ordena_Bib_LEncadeda(pEsq,&j,pBib);
        printf("A distancia entre pEsq e j eh %d\n ",Distancia_Bib_LEncadeada(pEsq,&j));
    }
    comparacoesBib++;
    if (pDir != pBib->pPrimeiroBiblioteca && pDir != NULL && (Distancia_Bib_LEncadeada(&i,pDir)>0)){
        Ordena_Bib_LEncadeda(&i,pDir,pBib);
        printf("A distancia entre i e pDir eh %d\n ",Distancia_Bib_LEncadeada(&i,pDir));
    }
}
void QuickSort_Bib_LEncadeada(TBiblioteca_LEncadeada* pBib){
    clock_t tF, tI = clock();
    double tempo;
    comparacoesText = 0; movimentacoesText = 0;
    tF = clock();
    printf("Iniciou o QuickSort da lista encadeada!\n");
    Ordena_Bib_LEncadeda(pBib->pPrimeiroBiblioteca->pProxBiblioteca, pBib->pUltimoBiblioteca, pBib);
    tempo = (tF - tI) * 1000.0 / CLOCKS_PER_SEC;
    printf("Algoritmo Quick Sort:\n");
    printf("\tComparacoes: %d\n", comparacoesBib);
    printf("\tMovimentacoes: %d\n", movimentacoesBib);
    printf("\tTempo Total Gasto: %lf s\n", tempo/1000);
}


void Particao_Bib_LEncadeada(TCelulaBiblioteca* pEsq, TCelulaBiblioteca* pDir, TCelulaBiblioteca *pI, TCelulaBiblioteca* pJ, TBiblioteca_LEncadeada* pBib){
    printf("Iniciou a Partiçao da lista encadeada !\n");
    TCelulaBiblioteca* Pivo;

    int tamanho_particao = Distancia_Bib_LEncadeada(pEsq,pDir);

    pI = pEsq;
    pJ = pDir;
    Pivo = pEsq;

    for (int i = 0; i < tamanho_particao/2; ++i) {
        Pivo = Pivo->pProxBiblioteca;

    }
    printf("pivo decidido!\n");

    while (Distancia_Bib_LEncadeada(pI,pJ)> 0){
        comparacoesBib++;
        while (Pivo->texto.tam_texto > pI->texto.tam_texto && pI!= NULL){
            comparacoesBib++;
            pI = pI->pProxBiblioteca;

        }
        while (Pivo->texto.tam_texto < pJ->texto.tam_texto && pJ != NULL){
            comparacoesBib++;
            pJ = pJ->pAntBiblioteca;
        }
        if(Distancia_Bib_LEncadeada(pI,pJ)>= 0){
            TrocaItens_Bib_QuickSort(pI,pJ);
            movimentacoesBib += 3;
            pI = pI->pProxBiblioteca;
            pJ = pJ->pAntBiblioteca;
            printf("Itens trocados!\n");
        }
        printf("A distancia entre pI e pJ eh %d\n",Distancia_Bib_LEncadeada(pI,pJ));
    }

    printf("saiu do while!");
    return;
}