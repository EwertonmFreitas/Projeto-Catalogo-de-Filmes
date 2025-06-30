#ifndef FILMES_H
#define FILMES_H

#define MAX 100

/**
 * @brief Estrutura que representa um filme no catálogo.
 *
 * Essa estrutura contém informações sobre um filme, como:
 * - ID: Identificador único do filme (exemplo: "12314").
 * - Titulo: Nome do filme.
 * - Diretor: Pessoa responsável pela direção do filme.
 * - Ano: Ano de lançamento do filme.
 * - Genero: Gênero do filme (exemplo: "comédia", "terror").
 * - Avaliacao: Nota que o filme recebe, de 0 a 10.
 */

typedef struct {
    int id;               /**< Identificador único do filme. */
    char titulo[100];     /**< Título do filme. */
    char diretor[100];    /**< Diretor do filme. */
    int ano;              /**< Ano de lançamento do filme. */
    char genero[50];      /**< Gênero do filme. */
    float avaliacao;      /**< Avaliação do filme, de 0 a 10. */
} Filme;

void salvarEmArquivo(Filme filmes[], int quantidade, const char *nomeArquivo);
void carregarDeArquivo(Filme filmes[], int *quantidade, const char *nomeArquivo);
void adicionarFilme(Filme filmes[], int *quantidade);
void buscarPorDiretor(Filme filmes[], int quantidade, const char *diretor);
void filtrarPorGenero(Filme filmes[], int quantidade, const char *genero);
void atualizarAvaliacao(Filme filmes[], int quantidade, int id, float novaAvaliacao);
void listarPorAnoOuTitulo(Filme filmes[], int quantidade, int porAno);

#endif
