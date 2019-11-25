// inicializa, insereLetra, removeLetra, imprime e tamanho.
#define TAMMAX 100
#define InicioArranjo 0
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
    char letra;
}TCaractere;

typedef struct
{
    TCaractere caractere[TAMMAX];
    int Primeiro,Ultimo;
}TPalavra;

void FazPalavraVazia(TPalavra *palavra);
int PalavraEhVazia(TPalavra *palavra);
void InsereLetra(TPalavra *palavra, TCaractere caractere);
void RetiraLetra(TPalavra *palavra, int posicao, TCaractere *caractere);
void ImprimePalavra (TPalavra *palavra);

/*
void FLVazia(TLista* pLista);
int LEhVazia(TLista* pLista);
int LInsere(TLista* pLista, TItem x);
int LRetira(TLista* pLista, Apontador p, TItem *pX);
void LImprime(TLista* pLista);
*/