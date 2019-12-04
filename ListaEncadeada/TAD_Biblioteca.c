#include "TAD_Biblioteca.h"

void FBVazia_LEncadeada(TBiblioteca_LEncadeada *pBiblioteca){
    pBiblioteca->pPrimeiroBiblioteca = (TCelulaBiblioteca*) malloc(sizeof(TCelulaBiblioteca));
    pBiblioteca->pPrimeiroBiblioteca->indice =-1;
    pBiblioteca->pUltimoBiblioteca = pBiblioteca->pPrimeiroBiblioteca;
    pBiblioteca->pPrimeiroBiblioteca->pProxBiblioteca = NULL;
    pBiblioteca->pPrimeiroBiblioteca->pAntBiblioteca = NULL;
}
int BibliotecaEhVazia_LEncadeada(TBiblioteca_LEncadeada *pBiblioteca){
    return(pBiblioteca->pPrimeiroBiblioteca == pBiblioteca->pUltimoBiblioteca);
}
void InsereTexto_LEncadeada(TBiblioteca_LEncadeada *pBiblioteca, Ttexto_LEncadeada texto){
    pBiblioteca->pUltimoBiblioteca->pProxBiblioteca = (TCelulaBiblioteca*)malloc(sizeof(TCelulaBiblioteca));
    pBiblioteca->pUltimoBiblioteca->pProxBiblioteca->indice = pBiblioteca->pUltimoBiblioteca->indice +1;
    pBiblioteca->pUltimoBiblioteca->pProxBiblioteca->pAntBiblioteca = pBiblioteca->pUltimoBiblioteca;
    pBiblioteca->pUltimoBiblioteca = pBiblioteca->pUltimoBiblioteca->pProxBiblioteca;
    pBiblioteca->pUltimoBiblioteca->texto = texto;

}
TCelulaBiblioteca* RetiraTexto_LEncadeada(TBiblioteca_LEncadeada *pBiblioteca, int n){
    TCelulaBiblioteca *pAux = pBiblioteca->pPrimeiroBiblioteca;
    TCelulaBiblioteca *texto;
    int cont = 0;
    while (pAux->pProxBiblioteca != NULL &&  cont < n)
    {
        pAux = pAux->pProxBiblioteca;
        cont++;
    }
    if(cont == n){
        texto = pAux->pProxBiblioteca;
        pAux->pProxBiblioteca = pAux->pProxBiblioteca->pProxBiblioteca;
    }
    
    return texto;
   // *texto = pBiblioteca->pPrimeiroBilioteca->pProxBiblioteca
}
void ImprimeBiblioteca_LEncadeada(TBiblioteca_LEncadeada *pBiblioteca){
    int n =1;
    for (TCelulaBiblioteca* i = pBiblioteca->pPrimeiroBiblioteca->pProxBiblioteca; i !=NULL; i = i->pProxBiblioteca) {
        printf("Texto %d\n",n);
        ImprimeTexto_LEncadeada(&i->texto);
        printf("Indice: %d\n",i->indice);
        printf("Tamanho: %d\n",i->texto.tam_texto);
        printf("\n");
        n++;
    }
}
int TamanhoBiblioteca_LEncadeada(TBiblioteca_LEncadeada *pBiblioteca){
    int count = 0;
    for (TCelulaBiblioteca* i = pBiblioteca->pPrimeiroBiblioteca->pProxBiblioteca; i !=NULL; i = i->pProxBiblioteca) {
        count += 1;
    }
    return count;
}