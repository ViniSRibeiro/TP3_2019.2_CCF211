// inicializa, insereLetra, removeLetra, imprime e tamanho.
#define TAMMAX 100


#define InicioArranjo 0
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char letra;
}TCaractereArranjo;

typedef struct {
    TCaractereArranjo caractere[TAMMAX];
    int Primeiro,Ultimo;
}TPalavra_Arranjo;




void FazPalavraVazia_Arranjo(TPalavra_Arranjo *palavra);
int PalavraEhVazia_Arranjo(TPalavra_Arranjo *palavra);
void InsereLetra_Arranjo(TPalavra_Arranjo *palavra, TCaractereArranjo caractere);
void RetiraLetra_Arranjo(TPalavra_Arranjo *palavra, int posicao, TCaractereArranjo *caractere);
void ImprimePalavra_Arranjo (TPalavra_Arranjo *palavra);
void TamanhoPalavra(TPalavra_Arranjo *Palavra);
