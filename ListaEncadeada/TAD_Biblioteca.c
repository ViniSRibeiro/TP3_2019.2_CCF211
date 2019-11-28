#include "TAD_Biblioteca.h"

void FBVazia(TBiblioteca *pBiblioteca){
    pBiblioteca->pPrimeiroBilioteca = (Apontador) malloc(sizeof(TCelulaBiblioteca));
    pBiblioteca->pUltimoBiblioteca = pBiblioteca->pPrimeiroBilioteca;
    pBiblioteca->pPrimeiroBilioteca->pProxBiblioteca = NULL;  
}
int BibliotecaEhVazia(TBiblioteca *pBiblioteca){
    return(pBiblioteca->pPrimeiroBilioteca == pBiblioteca->pUltimoBiblioteca);
}
void InsereTexto(TBiblioteca *pBiblioteca, Ttexto *texto){
    pBiblioteca->pUltimoBiblioteca->pProxBiblioteca = (Apontador)malloc(sizeof(TCelulaBiblioteca));
    pBiblioteca->pUltimoBiblioteca = pBiblioteca->pUltimoBiblioteca->pProxBiblioteca;
    pBiblioteca->pUltimoBiblioteca->texto = *texto;

}
void RetiraTexto(TBiblioteca *pBiblioteca, Ttexto *texto, Ttexto texto2){
    TCelulaBiblioteca *pAux;
    if(BibliotecaEhVazia(pBiblioteca)) return 0;
    while (pAux->pProxBiblioteca != NULL)
    {
        /* code */
    }
    
    
   // *texto = pBiblioteca->pPrimeiroBilioteca->pProxBiblioteca
}
void ImprimeBiblioteca(TBiblioteca *pBiblioteca){
    TCelulaBiblioteca *pAux = pBiblioteca;
    while (pAux->pProxBiblioteca!= NULL)
    {
        ImprimeTexto(&pAux->pProxBiblioteca->texto);
        pAux = pAux->pProxBiblioteca;
    }
}
int TamanhoBiblioteca(TBiblioteca *pBiblioteca){
    int count = 0;
    TCelulaBiblioteca *pAux = pBiblioteca;
    while (pAux->pProxBiblioteca!= NULL)
    {
        count++;
    }

    return count;
}