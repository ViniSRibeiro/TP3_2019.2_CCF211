//
// Created by vinicius on 25/11/2019.
//

#include "TAD_Biblioteca.h"
#include <stdio.h>


void FBibVazia(TBiblioteca_Arranjo* PBiblioteca){
    PBiblioteca->BibPrimeiro = InicioArranjo;
    PBiblioteca->BibUltimo = PBiblioteca->BibPrimeiro;
}

int BibEhVazia(TBiblioteca_Arranjo* PBiblioteca){
  return(PBiblioteca->BibPrimeiro == PBiblioteca->BibUltimo);
}

int InsereTexto(TBiblioteca_Arranjo* PBiblioteca, Ttexto_Arranjo PTexto){
    if(PBiblioteca->BibUltimo > size_biblioteca){ return 0;} //biblioteca cheia, impossivel colocar mais
    PBiblioteca->biblioteca[PBiblioteca->BibUltimo] = PTexto;
    PBiblioteca->BibUltimo++;
    return 1;
}
void RetiraTexto(TBiblioteca_Arranjo* PBiblioteca,int Posicao, Ttexto_Arranjo* PTexto){
    /*if(BibEhVazia(PBiblioteca)){ return 0;} //biblioteca ja vazia, impossivel adicionar mais
    for (int i = 0; i < size_biblioteca ; ++i) {
        if (PBiblioteca->biblioteca[i].TextoUltimo == PTexto->TextoUltimo){ //compara por tamanho do texto com o texto a ser removido
            for (int j = i; j < size_biblioteca; ++j) {
                PBiblioteca->biblioteca[j] = PBiblioteca->biblioteca[j+1]; //copia o resto do vetor 1 posiçao atras
            }
            PBiblioteca->BibUltimo --; //atualiza o tamanho da biblioteca
        }
    }
    */

    if (BibEhVazia(PBiblioteca) == 1) {
      printf("Texto vazio.\n");
    }else{
      for (int i = Posicao; i < 100; i++) {
        PBiblioteca->biblioteca[i] = PBiblioteca->biblioteca[i + 1];
      }
      PBiblioteca->BibUltimo--;
      printf("Palavra removida com sucesso!\n");
    }
}

int ImprimeBib(TBiblioteca_Arranjo* PBiblioteca){
    int n =1;
    for (int i = PBiblioteca->BibPrimeiro; i <PBiblioteca->BibUltimo ; ++i) {
        printf("Texto %d Tamamnho%d\n",n,TamanhoTexto(&PBiblioteca->biblioteca[i]));
        ImprimeTexto(&PBiblioteca->biblioteca[i]);
        printf("\n");
        n++;
    }
    return 1;
}

int TamanhoBib(TBiblioteca_Arranjo *PBiblioteca){
    return(PBiblioteca->BibUltimo);
}
