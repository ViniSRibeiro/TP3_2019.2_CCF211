//
// Created by vinicius on 25/11/2019.
//

#include "TAD_Biblioteca.h"
#include <stdio.h>


void FBibVazia(TBiblioteca* PBiblioteca){
    PBiblioteca->BibPrimeiro = InicioArranjo;
    PBiblioteca->BibUltimo = PBiblioteca->BibPrimeiro;
}

int BibEhVazia(TBiblioteca* PBiblioteca){
  if(PBiblioteca->BibPrimeiro == PBiblioteca->BibUltimo){ return 0;}
    return 1; // caso nao esteja vazia
}

int InsereTexto(TBiblioteca* PBiblioteca, Ttexto PTexto){
    if(PBiblioteca->BibUltimo > size_biblioteca){ return 0;} //biblioteca cheia, impossivel colocar mais
    PBiblioteca->biblioteca[PBiblioteca->BibUltimo] = PTexto;
    PBiblioteca->BibUltimo++;
    return 1;
}
int RetiraTexto(TBiblioteca* PBiblioteca, Ttexto* PTexto){
    if(BibEhVazia(PBiblioteca)){ return 0;} //biblioteca ja vazia, impossivel adicionar mais
    for (int i = 0; i < size_biblioteca ; ++i) {
        if (PBiblioteca->biblioteca[i].TextoUltimo == PTexto->TextoUltimo){ //compara por tamanho do texto com o texto a ser removido
            for (int j = i; j < size_biblioteca; ++j) {
                PBiblioteca->biblioteca[j] = PBiblioteca->biblioteca[j+1]; //copia o resto do vetor 1 posiçao atras
            }
            PBiblioteca->BibUltimo --; //atualiza o tamanho da biblioteca
        }
    }
}