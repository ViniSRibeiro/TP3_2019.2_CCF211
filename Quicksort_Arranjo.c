#include "Arranjo/TAD_Biblioteca.h"
#include "ListaEncadeada/TAD_Biblioteca.h"

void ordenaForBib(int Esq, int Dir, TBiblioteca_Arranjo *listaDeBiblioteca);
void ordenaForText(int Esq, int Dir, Ttexto_Arranjo *listaDeTexto);
void particaoForBib(int Esq, int Dir, int *i, int *j,TBiblioteca_Arranjo *listaDeBiblioteca);
void particaoForText(int Esq, int Dir, int *i, int *j, Ttexto_Arranjo *listaDeTexto);
void quicksortForBib(TBiblioteca_Arranjo *listaDeBiblioteca, int tamBib);
void quicksortForText(Ttexto_Arranjo *listaDeTexto, int n);

void quicksortForBib(TBiblioteca_Arranjo *listaDeBiblioteca, int tamBib)
{
    ordenaForBib(0,tamBib-1,listaDeBiblioteca);
}

void ordenaForBib(int Esq, int Dir, TBiblioteca_Arranjo *listaDeBiblioteca)
{
    int i,j;
    particaoForBib(Esq, Dir, &i,&j,listaDeBiblioteca);
    if(Esq < j) ordenaForBib(Esq, j, listaDeBiblioteca);
    if(i < Dir) ordenaForBib(i, Dir, listaDeBiblioteca);
}

void particaoForBib(int Esq, int Dir, int *i, int *j,TBiblioteca_Arranjo *listaDeBiblioteca)
{   
    Ttexto_Arranjo aux, pivo;
    *i = Esq; *j = Dir;
    pivo = listaDeBiblioteca->biblioteca[(*i + *j)/2];
    do{
        while(pivo.TextoUltimo > listaDeBiblioteca->biblioteca[*i].TextoUltimo) (*i)++;
        while(pivo.TextoUltimo < listaDeBiblioteca->biblioteca[*j].TextoUltimo) (*j)--;

        if(*i <= *j)
        {
            aux = listaDeBiblioteca->biblioteca[*i];
            listaDeBiblioteca->biblioteca[*i] = listaDeBiblioteca->biblioteca[*j];
            listaDeBiblioteca->biblioteca[*j] = aux;
            (*i)++; (*j)--;
        }
    } while(*i <= *j);
}

void particaoForText(int Esq, int Dir, int *i, int *j, Ttexto_Arranjo *listaDeTexto){
    TPalavra_Arranjo aux,pivo;
    *i = Esq; *j = Dir;
    pivo = listaDeTexto->vetorPalavra[(*i + *j)/2]; /* obtem o pivo x */
    do
    {
        while (pivo.caractere[0].letra > listaDeTexto->vetorPalavra[*i].caractere[0].letra) (*i)++;
        while (pivo.caractere[0].letra < listaDeTexto->vetorPalavra[*j].caractere[0].letra) (*j)--;

        if (*i <= *j)
        {
            aux = listaDeTexto->vetorPalavra[*i]; 
            listaDeTexto->vetorPalavra[*i] = listaDeTexto->vetorPalavra[*j]; 
            listaDeTexto->vetorPalavra[*j] = aux;
            (*i)++; (*j)--;
        }
    } while (*i <= *j);
}


void quicksortForText(Ttexto_Arranjo *listaDeTexto, int tamText)
{
    ordenaForText(0, tamText-1, listaDeTexto);
}

void ordenaForText(int Esq, int Dir, Ttexto_Arranjo *listaDeTexto)
{
    int i,j;
    particaoForText(Esq, Dir, &i, &j, listaDeTexto);
    if (Esq < j) ordenaForText(Esq, j, listaDeTexto);
    if (i < Dir) ordenaForText(i, Dir, listaDeTexto);
}

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