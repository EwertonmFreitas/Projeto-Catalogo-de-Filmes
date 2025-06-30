#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filmes.h"

/**
 * @brief Função para salvar o catálogo de filmes em um arquivo.
 *
 * @param filmes Lista de filmes a ser salva.
 * @param quantidade Número de filmes na lista.
 * @param nomeArquivo Nome do arquivo onde os filmes serão salvos.
 */

void salvarEmArquivo(Filme filmes[], int quantidade, const char *nomeArquivo) {
    FILE *f = fopen(nomeArquivo, "w");
    for (int i = 0; i < quantidade; i++) {
        fprintf(f, "id:%d;titulo:%s;diretor:%s;ano:%d;genero:%s;avaliacao:%.1f;\n",
                filmes[i].id, filmes[i].titulo, filmes[i].diretor,
                filmes[i].ano, filmes[i].genero, filmes[i].avaliacao);
    }
    fclose(f);
}

/**
 * @brief Função para salvar o catálogo de filmes em um arquivo.
 *
 * @param filmes Lista de filmes a ser salva.
 * @param quantidade Número de filmes na lista.
 * @param nomeArquivo Nome do arquivo onde os filmes serão salvos.
 */

void carregarDeArquivo(Filme filmes[], int *quantidade, const char *nomeArquivo) {
    FILE *f = fopen(nomeArquivo, "r");
    if (!f) return;
    *quantidade = 0;
    while (!feof(f) && *quantidade < MAX) {
        fscanf(f, "id:%d;titulo:%[^;];diretor:%[^;];ano:%d;genero:%[^;];avaliacao:%f;\n",
               &filmes[*quantidade].id, filmes[*quantidade].titulo,
               filmes[*quantidade].diretor, &filmes[*quantidade].ano,
               filmes[*quantidade].genero, &filmes[*quantidade].avaliacao);
        (*quantidade)++;
    }
    fclose(f);
}

/**
 * @brief Função para adicionar um novo filme ao catálogo.
 *
 * Solicita ao usuário informações sobre o filme e adiciona-o à lista.
 *
 * @param filmes Lista de filmes onde o novo filme será adicionado.
 * @param quantidade Ponteiro para armazenar a quantidade atual de filmes.
 */

void adicionarFilme(Filme filmes[], int *quantidade) {
    Filme novo;
    printf("ID: "); scanf("%d", &novo.id);
    printf("Titulo: "); getchar(); fgets(novo.titulo, 100, stdin); novo.titulo[strcspn(novo.titulo, "\n")] = 0;
    printf("Diretor: "); fgets(novo.diretor, 100, stdin); novo.diretor[strcspn(novo.diretor, "\n")] = 0;
    printf("Ano: "); scanf("%d", &novo.ano);
    printf("Genero: "); getchar(); fgets(novo.genero, 50, stdin); novo.genero[strcspn(novo.genero, "\n")] = 0;
    printf("Avaliacao (0-10): "); scanf("%f", &novo.avaliacao);
    filmes[(*quantidade)++] = novo;
}

/**
 * @brief Função para buscar filmes por diretor.
 *
 * A função verifica todos os filmes e imprime aqueles que possuem o mesmo nome de diretor.
 *
 * @param filmes Lista de filmes a ser pesquisada.
 * @param quantidade Número total de filmes.
 * @param diretor Nome do diretor a ser buscado.
 */

void buscarPorDiretor(Filme filmes[], int quantidade, const char *diretor) {
    for (int i = 0; i < quantidade; i++) {
        if (strcmp(filmes[i].diretor, diretor) == 0) {
            printf("%s (%d) - %.1f\n", filmes[i].titulo, filmes[i].ano, filmes[i].avaliacao);
        }
    }
}

/**
 * @brief Função para filtrar filmes por gênero.
 *
 * A função imprime todos os filmes de um determinado gênero.
 *
 * @param filmes Lista de filmes a ser filtrada.
 * @param quantidade Número total de filmes.
 * @param genero Gênero que será usado para filtrar os filmes.
 */

void filtrarPorGenero(Filme filmes[], int quantidade, const char *genero) {
    for (int i = 0; i < quantidade; i++) {
        if (strcmp(filmes[i].genero, genero) == 0) {
            printf("%s (%d) - %.1f\n", filmes[i].titulo, filmes[i].ano, filmes[i].avaliacao);
        }
    }
}

/**
 * @brief Função para atualizar a avaliação de um filme.
 *
 * A função encontra o filme com o ID correspondente e atualiza sua avaliação.
 *
 * @param filmes Lista de filmes.
 * @param quantidade Número total de filmes.
 * @param id ID do filme a ser atualizado.
 * @param novaAvaliacao Nova avaliação para o filme.
 */

void atualizarAvaliacao(Filme filmes[], int quantidade, int id, float novaAvaliacao) {
    for (int i = 0; i < quantidade; i++) {
        if (filmes[i].id == id) {
            filmes[i].avaliacao = novaAvaliacao;
            return;
        }
    }
}

/**
 * Função que lista um array de filmes ordenado por ano ou por título.
 *
 * @param filmes Array de estruturas do tipo Filme.
 * @param quantidade Número de filmes no array.
 * @param porAno Flag indicando o critério de ordenação:
 *               - Se porAno != 0, ordena por ano (crescente).
 *               - Se porAno == 0, ordena por título em ordem alfabética.
 */

void listarPorAnoOuTitulo(Filme filmes[], int quantidade, int porAno) {
    Filme temp;
    for (int i = 0; i < quantidade - 1; i++) {
        for (int j = i + 1; j < quantidade; j++) {
            int comp = porAno ? (filmes[i].ano > filmes[j].ano) : (strcmp(filmes[i].titulo, filmes[j].titulo) > 0);
            if (comp) {
                temp = filmes[i];
                filmes[i] = filmes[j];
                filmes[j] = temp;
            }
        }
    }
    for (int i = 0; i < quantidade; i++) {
        printf("%s (%d) - Dir: %s, Gênero: %s, Nota: %.1f\n",
               filmes[i].titulo, filmes[i].ano, filmes[i].diretor,
               filmes[i].genero, filmes[i].avaliacao);
    }
}
