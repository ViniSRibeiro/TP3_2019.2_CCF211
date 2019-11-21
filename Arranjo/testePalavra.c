#include "tadPalavra.h"

int main(){
    Caractere letrinha;
    Palavra palavrinha;
    strcpy(letrinha.letra,"i");
    FazPalavraVazia(&palavrinha);
    InsereLetra(&palavrinha,letrinha);
    strcpy(letrinha.letra,"s");
    InsereLetra(&palavrinha,letrinha);
    strcpy(letrinha.letra,"a");
    InsereLetra(&palavrinha,letrinha);
    InsereLetra(&palavrinha,letrinha);
    ImprimePalavra(&palavrinha);
    RetiraLetra(&palavrinha,3,&letrinha);
    ImprimePalavra(&palavrinha);
     
}