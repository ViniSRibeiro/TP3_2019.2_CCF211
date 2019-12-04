all:
	gcc -o teste main.c  Selecao_ListaEncadeada.c Selecao_ListaEncadeada.h QuickSort_LEncadeada.c QuickSort_LEncadeada.h Selecao_Arranjo.c Selecao_Arranjo.h Quicksort_Arranjo.c Quicksort_Arranjo.h Arranjo/TAD_Palavra.c Arranjo/TAD_Palavra.h Arranjo/TAD_Texto.c Arranjo/TAD_Texto.h Arranjo/TAD_Biblioteca.c Arranjo/TAD_Biblioteca.h ListaEncadeada/TAD_Palavra.c ListaEncadeada/TAD_Palavra.h ListaEncadeada/TAD_Texto.c ListaEncadeada/TAD_Texto.h ListaEncadeada/TAD_Biblioteca.c ListaEncadeada/TAD_Biblioteca.h

run: teste
	./teste
