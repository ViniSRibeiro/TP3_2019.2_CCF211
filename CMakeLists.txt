cmake_minimum_required(VERSION 3.15)
project(TP3_2019_2_CCF211 C)

set(CMAKE_C_STANDARD 11)

include_directories(Arranjo)
include_directories(ListaEncadeada)

add_executable(TP3_2019_2_CCF211
        Arranjo/main.c
        Arranjo/TAD_Biblioteca.c
        Arranjo/TAD_Biblioteca.h
        Arranjo/TAD_Palavra.c
        Arranjo/TAD_Palavra.h
        Arranjo/TAD_Texto.c
        Arranjo/TAD_Texto.h
        ListaEncadeada/main.c
        ListaEncadeada/TAD_Biblioteca.c
        ListaEncadeada/TAD_Biblioteca.h
        ListaEncadeada/TAD_Palavra.c
        ListaEncadeada/TAD_Palavra.h
        ListaEncadeada/TAD_Texto.c
        ListaEncadeada/TAD_Texto.h
        Interface.c)
