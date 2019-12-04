//#include "Interface.c"
#include "Selecao_Arranjo.h"

void selectionForBib(TBiblioteca_Arranjo *listaDeBiblioteca, int tamBib){
    clock_t tF, tI = clock();
    double tempo;
    int movimentacoes = 0, comparacoes = 0;
    Ttexto_Arranjo vAux;
    int vMenor;

    for (int i = 0; i < tamBib - 1; i++)
    {
        vMenor = i;
        for (int j = i + 1; j < tamBib; j++)
        {   int tamJ,tamMenor;
            tamJ = listaDeBiblioteca->biblioteca[j].TextoUltimo;
            comparacoes++;
            tamMenor = listaDeBiblioteca->biblioteca[vMenor].TextoUltimo;
            if(tamJ < tamMenor){
                vMenor = j;
            }
        }
        
        vAux = listaDeBiblioteca->biblioteca[vMenor];
        listaDeBiblioteca->biblioteca[vMenor] = listaDeBiblioteca->biblioteca[i];
        listaDeBiblioteca->biblioteca[i] = vAux;
        movimentacoes+=3;
    }

    tF = clock();
    tempo = (tF - tI) * 1000.0 / CLOCKS_PER_SEC;
    printf("Algoritmo Selecao:\n");
    printf("\tComparacoes: %d\n", comparacoes);
    printf("\tMovimentacoes: %d\n", movimentacoes);
    printf("\tTempo Total Gasto: %lf s\n", tempo/1000);
    
}

void selectionForText(Ttexto_Arranjo *listaDeTexto, int tamText)
{
    clock_t tF, tI = clock();
    double tempo;
    int movimentacoes = 0, comparacoes = 0;
    int vMenor;
    TPalavra_Arranjo vAux;
    for(int i = 0; i < tamText -1; i++) 
    {
        vMenor = i; // Menor valor recebe a posição que está passando;

        for (int j = i + 1; j < tamText; j++) // Percorre o vetor da posição vAux+1 até o final;
        {   
            comparacoes++;
            if (listaDeTexto->vetorPalavra[j].caractere[0].letra < listaDeTexto->vetorPalavra[vMenor].caractere[0].letra) // Testa se a posição que está passando é menor que o menor valor;
            {
                vMenor = j; // vMenor recebe a posição do menor valor;  
            }
        }

        vAux = listaDeTexto->vetorPalavra[vMenor];
        listaDeTexto->vetorPalavra[vMenor] = listaDeTexto->vetorPalavra[i];
        listaDeTexto->vetorPalavra[i] = vAux;
        movimentacoes+=3;
    }

    tF = clock();
    tempo = (tF - tI) * 1000.0 / CLOCKS_PER_SEC;
    printf("Selection sort:\n");
    printf("\tComparacoes: %d\n", comparacoes);
    printf("\tMovimentacoes: %d\n", movimentacoes);
    printf("\tTempo Total Gasto: %lf s\n", tempo/1000);
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
                int nPalavra = rand()%20;
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

    selectionForBib(&Biblioteca_Arranjo,n);

    printf("\n");

    ImprimeBib(&Biblioteca_Arranjo);

}
*/