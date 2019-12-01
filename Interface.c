//
// Created by vinicius on 28/11/2019.
//

#include "Arranjo/TAD_Biblioteca.h"
#include "ListaEncadeada/TAD_Biblioteca.h"
#include <stdio.h>
#include <stdlib.h>

TCaractereArranjo Letra_Aleatoria_Arranjo(){
    TCaractereArranjo Letra;
    Letra.letra = 97 + (char)(rand()%26);
    return Letra;
}

TCaractereEncadeada Letra_Aleatoria_Encadeada(){
    TCaractereEncadeada Letra;
    Letra.letra = 97 + (char)(rand()%26);
    return Letra;
}

int main(){
    TPalavra_Arranjo Palavra_Arranjo;
    Ttexto_Arranjo texto_Arranjo;
    TBiblioteca_Arranjo Biblioteca_Arranjo;

    TPalavra_LEncadeada Palavra_LEncadeada;
    Ttexto_LEncadeada texto_LEncadeada;
    TBiblioteca_LEncadeada Biblioteca_LEncadeada;
    int opcao,tipo_dados,tam_biblioteca, min_size_texto,max_size_texto;
    printf(" --------------------------------------------------------- \n");
    printf("|                       UFV - CAF                         |\n");
    printf("|                         TP 3                            |\n");
    printf("|            Roniel Nunes           -  3464               |\n");
    printf("|            Vinicius Ribeiro       -  2670               |\n");
    printf("|            Isabella Ramos         -  3474               |\n"); 
    printf(" --------------------------------------------------------- \n");
    FBibVazia(&Biblioteca_Arranjo);
    FBVazia_LEncadeada(&Biblioteca_LEncadeada);

    do{
        printf(" --------------------------------------------------------- \n");
        printf("|                       OPERACOES                         |\n");
        printf("|                                                         |\n");
        printf("|  1 - Gerar Biblioteca                                   |\n");
        printf("|  2 - Imprimir texto                                     |\n");
        printf("|  3 - Ordenar com Seleçao                                |\n");
        printf("|  4 - Ordenar com QuickSort                              |\n");
        printf("|  5 - Sair                                               |\n");
        printf(" --------------------------------------------------------- \n");

        printf("Entre com uma opcao: ");
        scanf("%d", &opcao);
        if(opcao == 5) break;
        printf(" --------------------------------------------------------- \n");
        printf("|                       QUAL O TIPO DE DADOS?             |\n");
        printf("|                                                         |\n");
        printf("|  1 - Arranjo                                            |\n");
        printf("|  2 - Lista Encadeada                                    |\n");
        printf(" --------------------------------------------------------- \n");
        printf("Entre com uma opcao para o tipo: ");
        scanf("%d", &tipo_dados);

        while (tipo_dados <1 || tipo_dados>2) {
            printf("Tipo Invalido!!!");
            printf("Entre com uma opcao para o tipo: ");
            scanf("%d", &tipo_dados);
        }
        switch (opcao){
            case 1:
                printf("Qual o tamanho da biblioteca ( quantos textos possui): ");
                scanf("%d",&tam_biblioteca);
                printf("\n");
                printf("digite o tamanho minimo de um texto nessa biblioteca: ");
                scanf("%d",&min_size_texto);
                printf("\n");
                printf("digite o tamanho maximo de um texto nessa biblioteca: ");
                scanf("%d",&max_size_texto);
                printf("\n");
                if(tipo_dados ==1){

                    for (int i = 0; i < tam_biblioteca ; ++i) { //gera N textos aleatorios
                        FazTextoVazia(&texto_Arranjo);
                        for (int k = min_size_texto; k <rand()%(max_size_texto-min_size_texto+1) ; ++k) { //tamanho dos textos gerados aleatoriamente
                            FazPalavraVazia_Arranjo(&Palavra_Arranjo);
                            /*
                             * o for interno roda K vezes, que eh a quantidade de palavras que o txto tera
                             */
                            for (int j = 0; j < rand()%50 ; ++j) { //roda um numero aleatorio de vezes para gerar de 0 a 50 letras, ja que o numero de letras nao ta especificado
                                InsereLetra_Arranjo(&Palavra_Arranjo,Letra_Aleatoria_Arranjo()); //insere as letras geradas aleatorias na palavra
                            }
                            InserePalavra(&texto_Arranjo,Palavra_Arranjo); //insere a palavra gerada no texto;
                        }
                        InsereTexto(&Biblioteca_Arranjo,texto_Arranjo);
                    }
                }else{
                    for (int i = 0; i <tam_biblioteca ; ++i) {
                        FTVazia_LEncadeada(&texto_LEncadeada);
                        for (int j = min_size_texto; j < rand()%(max_size_texto-min_size_texto+1) ; ++j) {
                            FPVazia_LEncadeada(&Palavra_LEncadeada);
                            for (int k = 0; k < rand()%50 ; ++k) {
                                InsereLetra_LEncadeada(&Palavra_LEncadeada,Letra_Aleatoria_Encadeada());
                            }
                            InserePalavra_LEncadeada(&texto_LEncadeada,Palavra_LEncadeada);
                        }
                        InsereTexto_LEncadeada(&Biblioteca_LEncadeada,texto_LEncadeada);
                    }
                }
                printf("Biblioteca criada!\n");
                break;
            case 2:
                printf("Imprimindo os textos dispostos na Biblioteca: \n");
                if(tipo_dados == 1){
                    ImprimeBib(&Biblioteca_Arranjo);
                    printf(" --------------------------------------------------------- \n");
                }else{
                    ImprimeBiblioteca_LEncadeada(&Biblioteca_LEncadeada);
                    printf(" --------------------------------------------------------- \n");
                }
                break;
        }
    }while(opcao<5);

    return 0;
}
