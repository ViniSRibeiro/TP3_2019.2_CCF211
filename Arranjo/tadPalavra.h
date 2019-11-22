// inicializa, insereLetra, removeLetra, imprime e tamanho.
#define TAMMAX 100
#define InicioArranjo 0
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct 
{
    char letra;
}Caractere;

typedef struct Lista
{
    Caractere caractere[TAMMAX];
    int Primeiro,Ultimo;
}Palavra;

void FazPalavraVazia(Palavra *palavra);
int PalavraVazia(Palavra *palavra);
void InsereLetra(Palavra *palavra, Caractere caractere);
void RetiraLetra(Palavra *palavra,int posicao, Caractere *caractere);
void ImprimePalavra (Palavra *palavra);

/*
void FLVazia(TLista* pLista);
int LEhVazia(TLista* pLista);
int LInsere(TLista* pLista, TItem x);
int LRetira(TLista* pLista, Apontador p, TItem *pX);
void LImprime(TLista* pLista);
*/