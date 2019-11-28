#include "TAD_Biblioteca.h"

void FBVazia_LEncadeada(TBiblioteca_LEncadeada *pBiblioteca){
    pBiblioteca->pPrimeiroBiblioteca = (Apontador) malloc(sizeof(TCelulaBiblioteca));
    pBiblioteca->pUltimoBiblioteca = pBiblioteca->pPrimeiroBiblioteca;
    pBiblioteca->pPrimeiroBiblioteca->pProxBiblioteca = NULL;  
}
int BibliotecaEhVazia_LEncadeada(TBiblioteca_LEncadeada *pBiblioteca){
    return(pBiblioteca->pPrimeiroBiblioteca == pBiblioteca->pUltimoBiblioteca);
}
void InsereTexto_LEncadeada(TBiblioteca_LEncadeada *pBiblioteca, Ttexto_LEncadeada *texto){
    pBiblioteca->pUltimoBiblioteca->pProxBiblioteca = (Apontador)malloc(sizeof(TCelulaBiblioteca));
    pBiblioteca->pUltimoBiblioteca = pBiblioteca->pUltimoBiblioteca->pProxBiblioteca;
    pBiblioteca->pUltimoBiblioteca->texto = *texto;

}
void RetiraTexto_LEncadeada(TBiblioteca_LEncadeada *pBiblioteca, Ttexto_LEncadeada *texto, Ttexto_LEncadeada texto2){
    TCelulaBiblioteca *pAux = pBiblioteca;
    //if(BibliotecaEhVazia_LEncadeada(pBiblioteca)) return 0;
    while (pAux->pProxBiblioteca != NULL && pAux->pProxBiblioteca->texto != texto2)
    {
        /* Voo* listaProcuraVoo(ListaDeVoos *l, int vid){
                Celula* aux = l->inicio;
                while(aux->prox != NULL && getVid(aux->prox->voo) != vid)
                aux = aux->prox;
                if(aux->prox != NULL)
                    return aux->prox->voo;
                else
                    return NULL;
}*/
    }
    
    
   // *texto = pBiblioteca->pPrimeiroBilioteca->pProxBiblioteca
}
void ImprimeBiblioteca_LEncadeada(TBiblioteca_LEncadeada *pBiblioteca){
    TBiblioteca_LEncadeada *pAux = pBiblioteca->pPrimeiroBiblioteca;
    while (pAux->pPrimeiroBiblioteca->pProxBiblioteca!= NULL)
    {
        ImprimeTexto_LEncadeada(&pAux->pPrimeiroBiblioteca->texto);
        pAux = pAux->pPrimeiroBiblioteca->pProxBiblioteca;
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