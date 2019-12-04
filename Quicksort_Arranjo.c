
#include "Quicksort_Arranjo.h"
int movimentacoesBib, movimentacoesText, comparacoesBib, comparacoesText;



void quicksortForBib(TBiblioteca_Arranjo *listaDeBiblioteca, int tamBib)
{
    clock_t tF, tI = clock();
    double tempo;
    movimentacoesBib = 0; comparacoesBib = 0;
    tF = clock();
    ordenaForBib(0,tamBib-1,listaDeBiblioteca);
    tempo = (tF - tI) * 1000.0 / CLOCKS_PER_SEC;
    printf("Algoritmo Quick Sort:\n");
    printf("\tComparacoes: %d\n", comparacoesBib);
    printf("\tMovimentacoes: %d\n", movimentacoesBib);
    printf("\tTempo Total Gasto: %lf s\n", tempo/1000);
}

void ordenaForBib(int Esq, int Dir, TBiblioteca_Arranjo *listaDeBiblioteca)
{
    int i,j;
    particaoForBib(Esq, Dir, &i,&j,listaDeBiblioteca);
    comparacoesBib++;
    if(Esq < j) ordenaForBib(Esq, j, listaDeBiblioteca);
    comparacoesBib++;
    if(i < Dir) ordenaForBib(i, Dir, listaDeBiblioteca);
}

void particaoForBib(int Esq, int Dir, int *i, int *j,TBiblioteca_Arranjo *listaDeBiblioteca)
{
    Ttexto_Arranjo aux, pivo;
    *i = Esq; *j = Dir;
    pivo = listaDeBiblioteca->biblioteca[(*i + *j)/2];
    do{
        comparacoesBib++;
        while(pivo.TextoUltimo > listaDeBiblioteca->biblioteca[*i].TextoUltimo){
            comparacoesBib++;
            (*i)++;
        }
        while(pivo.TextoUltimo < listaDeBiblioteca->biblioteca[*j].TextoUltimo){
            comparacoesBib++;
            (*j)--;
        }

        if(*i <= *j)
        {
            aux = listaDeBiblioteca->biblioteca[*i];
            listaDeBiblioteca->biblioteca[*i] = listaDeBiblioteca->biblioteca[*j];
            listaDeBiblioteca->biblioteca[*j] = aux;
            movimentacoesBib += 3;
            (*i)++; (*j)--;
        }
    } while(*i <= *j);
}

void particaoForText(int Esq, int Dir, int *i, int *j, Ttexto_Arranjo *listaDeTexto){
    TPalavra_Arranjo aux,pivo;
    *i = Esq; *j = Dir;
    pivo = listaDeTexto->vetorPalavra[(*i + *j)/2]; /* obtem o pivo x */
    do
    {   comparacoesText++;
        while (pivo.caractere[0].letra > listaDeTexto->vetorPalavra[*i].caractere[0].letra){
             (*i)++;
             comparacoesText++;
        }
        comparacoesText++;
        while (pivo.caractere[0].letra < listaDeTexto->vetorPalavra[*j].caractere[0].letra){
            (*j)--;
            comparacoesText++;
        }
        if (*i <= *j)
        {
            aux = listaDeTexto->vetorPalavra[*i];
            listaDeTexto->vetorPalavra[*i] = listaDeTexto->vetorPalavra[*j];
            listaDeTexto->vetorPalavra[*j] = aux;
            movimentacoesText +=3;
            (*i)++; (*j)--;
        }
    } while (*i <= *j);
}


void quicksortForText(Ttexto_Arranjo *listaDeTexto, int tamText)
{
    clock_t tF, tI = clock();
    double tempo;
    comparacoesText = 0; movimentacoesText = 0;
    tF = clock();
    ordenaForText(0, tamText-1, listaDeTexto);
    tempo = (tF - tI) * 1000.0 / CLOCKS_PER_SEC;
    printf("Algoritmo Quick Sort:\n");
    printf("\tComparacoes: %d\n", comparacoesText);
    printf("\tMovimentacoes: %d\n", movimentacoesText);
    printf("\tTempo Total Gasto: %lf s\n", tempo/1000);
}

void ordenaForText(int Esq, int Dir, Ttexto_Arranjo *listaDeTexto)
{
    int i,j;
    particaoForText(Esq, Dir, &i, &j, listaDeTexto);
    comparacoesText++;
    if (Esq < j) ordenaForText(Esq, j, listaDeTexto);
    comparacoesText++;
    if (i < Dir) ordenaForText(i, Dir, listaDeTexto);
}
/*

int main(){

    TCaractereArranjo Letra_Arranjo;
    TPalavra_Arranjo Palavra_Arranjo;
    Ttexto_Arranjo texto_Arranjo;
    TBiblioteca_Arranjo Biblioteca_Arranjo;
    int n;
    FBibVazia(&Biblioteca_Arranjo);
    srand(time(NULL));
       for (int i = 0; i < 10; i++)
        {
            FazTextoVazia(&texto_Arranjo);
            int nTextos = 1 + rand()%10;
            for (int i = 0; i < nTextos; i++) //formação de texto
            {
                FazPalavraVazia_Arranjo(&Palavra_Arranjo);
                int nPalavra = 1 + rand()%20;
                for (int i = 0; i < nPalavra; i++)
                {
                    char letra =97 + (char)(rand()%26);
                    Letra_Arranjo.letra = letra;
                    InsereLetra_Arranjo(&Palavra_Arranjo,Letra_Arranjo);
                }
                InserePalavra(&texto_Arranjo,Palavra_Arranjo);
            }
            InsereTexto(&Biblioteca_Arranjo,texto_Arranjo);
        }
    n = TamanhoBib(&Biblioteca_Arranjo);

    ImprimeBib(&Biblioteca_Arranjo);
    quicksortForBib(&Biblioteca_Arranjo,n);

    printf("\n");

    ImprimeBib(&Biblioteca_Arranjo);


}
*/
