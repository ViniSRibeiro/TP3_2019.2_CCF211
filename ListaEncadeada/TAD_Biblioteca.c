#include "TAD_Biblioteca.h"

void FBVazia_LEncadeada(TBiblioteca_LEncadeada *pBiblioteca){
    pBiblioteca->pPrimeiroBilioteca = (Apontador) malloc(sizeof(TCelulaBiblioteca));
    pBiblioteca->pUltimoBiblioteca = pBiblioteca->pPrimeiroBilioteca;
    pBiblioteca->pPrimeiroBilioteca->pProxBiblioteca = NULL;  
}
int BibliotecaEhVazia_LEncadeada(TBiblioteca_LEncadeada *pBiblioteca){
    return(pBiblioteca->pPrimeiroBilioteca == pBiblioteca->pUltimoBiblioteca);
}
void InsereTexto_LEncadeada(TBiblioteca_LEncadeada *pBiblioteca, Ttexto_LEncadeada *texto){
    pBiblioteca->pUltimoBiblioteca->pProxBiblioteca = (Apontador)malloc(sizeof(TCelulaBiblioteca));
    pBiblioteca->pUltimoBiblioteca = pBiblioteca->pUltimoBiblioteca->pProxBiblioteca;
    pBiblioteca->pUltimoBiblioteca->texto = *texto;

}
void RetiraTexto_LEncadeada(TBiblioteca_LEncadeada *pBiblioteca, Ttexto_LEncadeada *texto, Ttexto_LEncadeada texto2){
    TCelulaBiblioteca *pAux;
    if(BibliotecaEhVazia_LEncadeada(pBiblioteca)) return 0;
    while (pAux->pProxBiblioteca != NULL)
    {
        /* code */
    }
    
    
   // *texto = pBiblioteca->pPrimeiroBilioteca->pProxBiblioteca
}
void ImprimeBiblioteca_LEncadeada(TBiblioteca_LEncadeada *pBiblioteca){
    TCelulaBiblioteca *pAux = pBiblioteca;
    while (pAux->pProxBiblioteca!= NULL)
    {
        ImprimeTexto_LEncadeada(&pAux->pProxBiblioteca->texto);
        pAux = pAux->pProxBiblioteca;
    }
}
int TamanhoBiblioteca_LEncadeada(TBiblioteca_LEncadeada *pBiblioteca){
    int count = 0;
    TCelulaBiblioteca *pAux = pBiblioteca;
    while (pAux->pProxBiblioteca!= NULL)
    {
        count++;
    }

    return count;
}