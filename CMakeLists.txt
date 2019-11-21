cmake_minimum_required(VERSION 3.15)
project(TP3_2019_2_CCF211)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(Arranjo)

add_executable(TP3_2019_2_CCF211
        Arranjo/tadPalavra.c
        Arranjo/tadPalavra.h
        Arranjo/testePalavra.c
        README.md)
