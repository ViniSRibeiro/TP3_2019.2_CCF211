#include "ListaEncadeada/TAD_Biblioteca.h"
#include "Arranjo/TAD_Biblioteca.h"

//gcc -o teste geracaoBib.c Arranjo/TAD_Palavra.c Arranjo/TAD_Palavra.h Arranjo/TAD_Texto.c Arranjo/TAD_Texto.h Arranjo/TAD_Biblioteca.c Arranjo/TAD_Biblioteca.h ListaEncadeada/TAD_Palavra.c ListaEncadeada/TAD_Palavra.h ListaEncadeada/TAD_Texto.c ListaEncadeada/TAD_Texto.h ListaEncadeada/TAD_Biblioteca.c ListaEncadeada/TAD_Biblioteca.h

int geracao(){
  TBiblioteca_LEncadeada Biblioteca_LEncadeada;
  TBiblioteca_Arranjo Biblioteca_Arranjo;
  int tam_biblioteca,min_size_texto,max_size_texto;

  printf("Tamanho da bib: ");
  scanf("%d",&tam_biblioteca);
  printf("Tam max text: ");
  scanf("%d",&min_size_texto);
  printf("Tam min text: ");
  scanf("%d", &max_size_texto);
  
  FBVazia_LEncadeada(&Biblioteca_LEncadeada);
  FBibVazia(&Biblioteca_Arranjo);
  
  Ttexto_Arranjo texto_Arranjo;
  Ttexto_LEncadeada texto_LEncadeada;
  TPalavra_LEncadeada Palavra_LEncadeada;
  TPalavra_Arranjo Palavra_Arranjo;  
  TCaractereEncadeada Letra_LEncadeada;
  TCaractereArranjo Letra_Arranjo;

  for (int i = 0; i < tam_biblioteca; i++)
  { 
    FazTextoVazia(&texto_Arranjo);
    FTVazia_LEncadeada(&texto_LEncadeada);
   
    int nTextos = rand()%(min_size_texto-max_size_texto+1);
    for (int i = 0; i < nTextos; i++) //formação de texto
    { 
      FPVazia_LEncadeada(&Palavra_LEncadeada);
      FazPalavraVazia_Arranjo(&Palavra_Arranjo);
          
        int nPalavra = rand()%20;

        for (int i = 0; i < nPalavra; i++)
        {
          char letra =97 + (char)(rand()%26);
          Letra_Arranjo.letra = letra;
          Letra_LEncadeada.letra = Letra_Arranjo.letra;
          InsereLetra_LEncadeada(&Palavra_LEncadeada,Letra_LEncadeada);
          InsereLetra_Arranjo(&Palavra_Arranjo,Letra_Arranjo);
        }

      InserePalavra_LEncadeada(&texto_LEncadeada,Palavra_LEncadeada);
      InserePalavra(&texto_Arranjo,Palavra_Arranjo);
      }  

      InsereTexto_LEncadeada(&Biblioteca_LEncadeada,texto_LEncadeada);
      InsereTexto(&Biblioteca_Arranjo,texto_Arranjo);
  }
  
  printf("Biblioteca por encadeada\n");
  ImprimeBiblioteca_LEncadeada(&Biblioteca_LEncadeada);
  
  printf("Biblioteca por arranjo\n");
  ImprimeBib(&Biblioteca_Arranjo);

}
  
