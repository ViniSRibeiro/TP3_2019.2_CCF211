#include "TAD_Palavra.h"

typedef int ApontadorTexto;

typedef struct{
  TPalavra vetorPalavra[TAMMAX];
  ApontadorTexto TextoPrimeiro,TextoUltimo;
}Ttexto;

void FazTextoVazia(Ttexto *pTexto);
int TextoVazia(Ttexto *pTexto);
void InserePalavra(Ttexto *pTexto, TPalavra palavra);
void RetiraPalavra(Ttexto *pTexto, int posicao, TPalavra *pPalavra);
void ImprimeTexto(Ttexto *pTexto);
void TamanhoTexto(Ttexto *pTexto);
