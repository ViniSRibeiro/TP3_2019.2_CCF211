#include "TAD_Texto.h"

void FazTextoVazia(Ttexto_Arranjo *pTexto){
    pTexto->TextoPrimeiro = InicioArranjo;
    pTexto->TextoUltimo = pTexto->TextoPrimeiro;
}

int TextoVazia(Ttexto_Arranjo *pTexto){
    return(pTexto->TextoUltimo == pTexto->TextoPrimeiro);
}

void InserePalavra(Ttexto_Arranjo *pTexto, TPalavra_Arranjo palavra){
    pTexto->vetorPalavra[pTexto->TextoUltimo] = palavra;
    pTexto->TextoUltimo +=1;
}

void RetiraPalavra(Ttexto_Arranjo *pTexto, int Posicao, TPalavra_Arranjo *pPalavra){
    if (TextoVazia(pTexto) == 1) {
      printf("Texto vazio.\n");
    }else{
      for (int i = Posicao; i < size_texto; i++) {
        pTexto->vetorPalavra[i] = pTexto->vetorPalavra[i + 1];
      }
      pTexto->TextoUltimo--;
      printf("Palavra removida com sucesso!\n");
    }
}
void ImprimeTexto(Ttexto_Arranjo *pTexto){
    if (TextoVazia(pTexto) == 1) {
      printf("Texto vazio.\n");
    }else{
      for(int i = pTexto->TextoPrimeiro; i < pTexto->TextoUltimo; i++){
          ImprimePalavra_Arranjo(&pTexto->vetorPalavra[i]);
      }
      printf(" ");
    }
}

int TamanhoTexto(Ttexto_Arranjo *pTexto){
  return(pTexto->TextoUltimo);
}
