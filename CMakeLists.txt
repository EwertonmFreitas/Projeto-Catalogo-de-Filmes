cmake_minimum_required(VERSION 3.31)
project(Filmes_Catalogo C)

set(CMAKE_C_STANDARD 11)

add_executable(Filmes_Catalogo main.c
        filmes.h
        filmes.c)
