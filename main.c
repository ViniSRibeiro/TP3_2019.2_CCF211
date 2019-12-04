//
// Created by vinicius on 28/11/2019.
//




#include "Quicksort_Arranjo.h"
#include "QuickSort_LEncadeada.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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
    
    TCaractereArranjo Letra_Arranjo;
    TPalavra_Arranjo Palavra_Arranjo;
    Ttexto_Arranjo texto_Arranjo;
    TBiblioteca_Arranjo Biblioteca_Arranjo;
    
    TCaractereEncadeada Letra_LEncadeada;
    TPalavra_LEncadeada Palavra_LEncadeada;
    Ttexto_LEncadeada texto_LEncadeada;
    TBiblioteca_LEncadeada Biblioteca_LEncadeada;
    time_t t;
    srand(t);
    int opcao,tipo_dados,tam_biblioteca, min_size_texto,max_size_texto, texto_ou_bib;


    printf(" --------------------------------------------------------- \n");
    printf("|                       UFV - CAF                         |\n");
    printf("|                         TP 3                            |\n");
    printf("|            Roniel Nunes           -  3464               |\n");
    printf("|            Vinicius Ribeiro       -  2670               |\n");
    printf("|            Isabella Ramos         -  3474               |\n"); 
    printf(" --------------------------------------------------------- \n");

    FBVazia_LEncadeada(&Biblioteca_LEncadeada);

    do{
        printf(" --------------------------------------------------------- \n");
        printf("|                       OPERACOES                         |\n");
        printf("|                                                         |\n");
        printf("|  1 - Gerar Biblioteca                                   |\n");
        printf("|  2 - Imprimir texto                                     |\n");
        printf("|  3 - Ordenar com Selecao                                |\n");
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
                FBibVazia(&Biblioteca_Arranjo,tam_biblioteca );



                printf("digite o tamanho minimo de um texto nessa biblioteca: ");
                scanf("%d",&min_size_texto);
                printf("\n");

                printf("digite o tamanho maximo de um texto nessa biblioteca: ");
                scanf("%d",&max_size_texto);
                printf("\n");

                    for (int i = 0; i < tam_biblioteca; i++)
                    {
                        int nTextos = 1 + rand()%(max_size_texto-min_size_texto + 1);

                        FazTextoVazia(&texto_Arranjo, nTextos);
                        FTVazia_LEncadeada(&texto_LEncadeada);
                    

                        for (int i = 0; i < nTextos; i++) //formação de texto
                        { 
                        FPVazia_LEncadeada(&Palavra_LEncadeada);
                        FazPalavraVazia_Arranjo(&Palavra_Arranjo);
                            
                            int nPalavra = 1 + rand()%20;

                            for (int i = 0; i < nPalavra; i++)
                            {
                            char letra = 97 + (char)(rand()%26);
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
            case 3:
                printf(" --------------------------------------------------------- \n");
                printf("|                       O QUE DESEJA ORDENAR?             |\n");
                printf("|                                                         |\n");
                printf("|  1 - Palavras no texto                                  |\n");
                printf("|  2 - Textos na Biblioteca                               |\n");
                printf(" --------------------------------------------------------- \n");
                printf("Entre com uma opcao: ");
                scanf("%d", &texto_ou_bib);
                if(texto_ou_bib == 1){
                    if(tipo_dados == 1){ //ordenar arranjo, ordenar as palavras dentro do texto
                        for (int i = 0; i <Biblioteca_Arranjo.BibUltimo ; ++i) {
                            selectionForText(&Biblioteca_Arranjo.biblioteca[i],Biblioteca_Arranjo.BibUltimo);
                        }
                        printf("Ordenaçao concluida!\n");
                    }else{
                        for (TCelulaBiblioteca *i = Biblioteca_LEncadeada.pPrimeiroBiblioteca->pProxBiblioteca; i != Biblioteca_LEncadeada.pUltimoBiblioteca->pProxBiblioteca ; i = i->pProxBiblioteca) {
                            Ttexto_LEncadeada *j = &i->texto;
                                SelectSort_Texto(j);


                        }
                        printf("Ordenaçao concluida!\n");
                    }
                }else{
                    if(tipo_dados == 1){
                        for (int i = 0; i <Biblioteca_Arranjo.BibUltimo ; ++i) {
                            selectionForBib(&Biblioteca_Arranjo,Biblioteca_Arranjo.BibUltimo);
                        }
                        printf("Ordenaçao concluida!\n");
                    }else{
                            SelectSort_Bib(&Biblioteca_LEncadeada);
                            printf("Ordenaçao concluida!\n");

                    }
                }

                break;
            case 4:
                printf(" --------------------------------------------------------- \n");
                printf("|                       O QUE DESEJA ORDENAR?             |\n");
                printf("|                                                         |\n");
                printf("|  1 - Palavras no texto                                  |\n");
                printf("|  2 - Textos na Biblioteca                               |\n");
                printf(" --------------------------------------------------------- \n");
                printf("Entre com uma opcao: ");
                scanf("%d", &texto_ou_bib);
                if(texto_ou_bib == 1){
                    if(tipo_dados == 1){
                        for (int i = 0; i <Biblioteca_Arranjo.BibUltimo ; ++i) {
                            quicksortForText(&Biblioteca_Arranjo.biblioteca[i],Biblioteca_Arranjo.BibUltimo);
                        }
                        printf("Ordenaçao concluida!\n");
                    }else{
                        for (TCelulaBiblioteca *i = Biblioteca_LEncadeada.pPrimeiroBiblioteca->pProxBiblioteca; i != Biblioteca_LEncadeada.pUltimoBiblioteca ; i = i->pProxBiblioteca) {

                                QuickSort_Texto_LEncadeada(&i->texto);

                        }
                        printf("Ordenaçao concluida!\n");
                    }
                }else{
                    if(tipo_dados == 1){
                        for (int i = 0; i <Biblioteca_Arranjo.BibUltimo ; ++i) {
                            quicksortForBib(&Biblioteca_Arranjo,Biblioteca_Arranjo.BibUltimo);
                        }
                        printf("Ordenaçao concluida!\n");
                    }else{
                            printf("Vai iniciar o Quicksort de lista encadeada na biblioteca!\n");
                            QuickSort_Bib_LEncadeada(&Biblioteca_LEncadeada);

                            printf("Ordenaçao concluida!\n");


                    }
                }
                break;
        }
    }while(opcao<5);

    return 0;
}
