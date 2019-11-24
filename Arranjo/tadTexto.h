#include "tadPalavra.h"

typedef int ApontadorTexto;

typedef struct{
  Palavra vetorPalavra[TAMMAX];
  ApontadorTexto TextoPrimeiro,TextoUltimo;
}Ttexto;

void FazTextoVazia(Ttexto *pTexto);
int TextoVazia(Ttexto *pTexto);
void InserePalavra(Ttexto *pTexto, Palavra palavra);
void RetiraPalavra(Ttexto *pTexto,int posicao, Palavra *pPalavra);
void ImprimeTexto(Ttexto *pTexto);
void TamanhoTexto(Ttexto *pTexto);
