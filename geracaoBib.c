#include "ListaEncadeada/TAD_Biblioteca.h"
#include "Arranjo/TAD_Biblioteca.h"

void geracaoAleatoriaPalavras(TPalavra_LEncadeada *PalavraEncadeada, TPalavra_Arranjo *PalavraArranjo){
  TCaractereEncadeada LetraEncadeada;
  TCaractereArranjo LetraArranjo;
  int nPalavra = rand()%20;

  for (int i = 0; i < nPalavra; i++)
      {
        char caractere = 97 + (char)(rand()%26);
        LetraEncadeada.letra = LetraArranjo.letra = caractere;
        InsereLetra_LEncadeada(&PalavraEncadeada,LetraEncadeada);
        InsereLetra_Arranjo(&PalavraArranjo,LetraArranjo);
      }

}

void geracaoAleatoriaTextos(Ttexto_LEncadeada *textosE,Ttexto_Arranjo *textosA,int tamMaxTextos, int tamMinTextos){
  FazTextoVazia(&textosA);
  FTVazia_LEncadeada(&textosE);
  TPalavra_LEncadeada PalavraEncadeada;
  TPalavra_Arranjo PalavraArranjo;

  int nTextos = rand()%(tamMaxTextos-tamMinTextos+1);
  for (int i = 0; i < nTextos; i++) //formação de texto
  { 
    FPVazia_LEncadeada(&PalavraEncadeada);
    FazPalavraVazia_Arranjo(&PalavraArranjo);
        
    geracaoAleatoriaPalavras(&PalavraEncadeada,&PalavraArranjo);  //formação de palavras
        
    InserePalavra_LEncadeada(&textosE,PalavraEncadeada);
    InserePalavra(&textosA,PalavraArranjo);
  }
    
}

void geracaoAleatoriaBib(TBiblioteca_LEncadeada *BibliotecaEncadeada,TBiblioteca_Arranjo *BibliotecaArranjo,int tamBiblioteca, int tamMaxTextos, int tamMinTextos){
  Ttexto_Arranjo textosA;
  Ttexto_LEncadeada textosE;


  for (int i = 0; i < tamBiblioteca; i++)
  { 
    geracaoAleatoriaTextos(&textosE,&textosA,tamMaxTextos,tamMinTextos);

    InsereTexto_LEncadeada(&BibliotecaEncadeada,textosE);
    InsereTexto(&BibliotecaArranjo,textosA);
  }

}

int main(){
  TBiblioteca_LEncadeada BibliotecaEncadeada;
  TBiblioteca_Arranjo BibliotecaArranjo;
  int tamBib,tamMaxText,tamMinText;

  printf("Tamanho da bib: ");
  scanf("%d",&tamBib);
  printf("Tam max text: ");
  scanf("%d",&tamMaxText);
  printf("Tam min text: ");
  scanf("%d", &tamMinText);

  FBVazia_LEncadeada(&BibliotecaEncadeada);
  FBibVazia(&BibliotecaArranjo);

  geracaoAleatoriaBib(&BibliotecaEncadeada,&BibliotecaArranjo,tamBib,tamMaxText,tamMinText);
  
  printf("Biblioteca por encadeada\n");
  ImprimeBiblioteca_LEncadeada(&BibliotecaEncadeada);

  printf("Biblioteca por arranjo\n");
  ImprimeBib(&BibliotecaArranjo);

}
  
