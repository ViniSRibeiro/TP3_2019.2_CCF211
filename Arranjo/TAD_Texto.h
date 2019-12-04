#include "TAD_Palavra.h"

#define size_texto 100
typedef int ApontadorTexto;

typedef struct{
  TPalavra_Arranjo *vetorPalavra;
  ApontadorTexto TextoPrimeiro,TextoUltimo;
  int tam_palavras;
}Ttexto_Arranjo;

void FazTextoVazia(Ttexto_Arranjo *pTexto, int size);
int TextoVazia(Ttexto_Arranjo *pTexto);
void InserePalavra(Ttexto_Arranjo *pTexto, TPalavra_Arranjo palavra);
void RetiraPalavra(Ttexto_Arranjo *pTexto, int posicao, TPalavra_Arranjo *pPalavra);
void ImprimeTexto(Ttexto_Arranjo *pTexto);
int TamanhoTexto(Ttexto_Arranjo *pTexto);
