#include <stdio.h>
#include "filmes.h"

/**
 * Função principal do programa de gerenciamento de filmes.
 * Realiza operações como adicionar, buscar, filtrar, atualizar e listar filmes,
 * utilizando um menu interativo com o usuário.
 */

int main() {
    Filme filmes[MAX];           // Array para armazenar os filmes.
    int quantidade = 0;          // Quantidade atual de filmes.

    // Carrega os filmes salvos previamente do arquivo.
    carregarDeArquivo(filmes, &quantidade, "filmes.txt");

    int opcao;
    do {
        // Exibe o menu de opções.
        printf("\n1-Adicionar 2-Buscar Diretor 3-Filtrar Genero 4-Atualizar Avaliacao 5-Listar (1-Ano/0-Titulo) 0-Sair: ");
        scanf("%d", &opcao);

        // Opção 1: Adiciona um novo filme.
        if (opcao == 1) adicionarFilme(filmes, &quantidade);

        // Opção 2: Busca filmes por nome do diretor.
        else if (opcao == 2) {
            char diretor[100];
            printf("Diretor: "); getchar(); fgets(diretor, 100, stdin); diretor[strcspn(diretor, "\n")] = 0;
            buscarPorDiretor(filmes, quantidade, diretor);

        // Opção 3: Filtra filmes por gênero.
        } else if (opcao == 3) {
            char genero[50];
            printf("Genero: "); getchar(); fgets(genero, 50, stdin); genero[strcspn(genero, "\n")] = 0;
            filtrarPorGenero(filmes, quantidade, genero);
        // Opção 4: Atualiza a avaliação de um filme específico pelo ID.
        } else if (opcao == 4) {
            int id; float nota;
            printf("ID do filme: "); scanf("%d", &id);
            printf("Nova avaliacao: "); scanf("%f", &nota);
            atualizarAvaliacao(filmes, quantidade, id, nota);
        } else if (opcao == 5) {
            int modo;
            printf("1 para ordenar por Ano, 0 por Titulo: "); scanf("%d", &modo);
            listarPorAnoOuTitulo(filmes, quantidade, modo);
        }

    } while (opcao != 0);// Continua o loop até que o usuário escolha sair.

    // Salva os dados atualizados no arquivo antes de encerrar o programa.
    salvarEmArquivo(filmes, quantidade, "filmes.txt");
    return 0;
}
