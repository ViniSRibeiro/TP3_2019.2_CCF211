//#include "Interface.c"
#include "Arranjo/TAD_Biblioteca.h"
#include "ListaEncadeada/TAD_Biblioteca.h"

void selectionForBib(TBiblioteca_Arranjo *listaDeBiblioteca, int n){

}

void selectionForText(Ttexto_Arranjo *listaDeTexto, int n)
{
    int vMenor;
    TPalavra_Arranjo vAux;
    TCaractereArranjo carac;
    for(int i = 0; i < n -1; i++) // Percorre todo o vetor até TAM-1, pois a ultima posição não precisa testar pois ja estara ordenada;
    {
        vMenor = i; // Menor valor recebe a posição que está passando;

        for (int j = i + 1; j < n; j++) // Percorre o vetor da posição vAux+1 até o final;
        {   
            if (listaDeTexto->vetorPalavra[j].caractere[0].letra < listaDeTexto->vetorPalavra[vMenor].caractere[0].letra) // Testa se a posição que está passando é menor que o menor valor;
            {
                vMenor = j; // vMenor recebe a posição do menor valor;
            }
        }

        vAux = listaDeTexto->vetorPalavra[vMenor];
        listaDeTexto->vetorPalavra[vMenor] = listaDeTexto->vetorPalavra[i];
        listaDeTexto->vetorPalavra[i] = vAux;
    }
}

int main(){
    TCaractereArranjo Letra_Arranjo;
    TPalavra_Arranjo Palavra_Arranjo;
    Ttexto_Arranjo texto_Arranjo;
    int n;
    srand(time(NULL));
    FazTextoVazia(&texto_Arranjo);
    int nTextos = rand()%10;
    for (int i = 0; i < nTextos; i++) //formação de texto
    { 
        FazPalavraVazia_Arranjo(&Palavra_Arranjo);
                                
        int nPalavra = (int)(rand()%30);

        for (int i = 0; i < nPalavra; i++)
        {
            char letra = 97 + (char)(rand()%26);
            Letra_Arranjo.letra = letra;
            InsereLetra_Arranjo(&Palavra_Arranjo,Letra_Arranjo);
        }

        InserePalavra(&texto_Arranjo,Palavra_Arranjo);
    }  
    n = TamanhoTexto(&texto_Arranjo);
    //printf("tam vetor: %d",n);
    ImprimeTexto(&texto_Arranjo);

    selectionForText(&texto_Arranjo,n);

    printf("\n");

    ImprimeTexto(&texto_Arranjo);


}