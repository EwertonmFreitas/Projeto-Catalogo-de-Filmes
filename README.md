Para criar um arquivo `README.md` bem detalhado para o seu projeto de gerenciamento de filmes, seguindo as instruções para download, instalação e teste, você pode usar o seguinte modelo. Ele inclui as informações essenciais baseadas nos arquivos de código fornecidos.

-----

# 🎬 Gerenciador de Filmes em C

Um sistema simples e eficiente para gerenciar seu catálogo de filmes. Este projeto permite adicionar, buscar, filtrar, atualizar e listar filmes, sendo uma ótima solução para organizar sua coleção pessoal.

## ✨ Funcionalidades

  * **Adicionar Filme**: Inclua novos filmes com detalhes como ID, título, diretor, ano, gênero e avaliação.
  * **Buscar por Diretor**: Encontre todos os filmes dirigidos por um cineasta específico.
  * **Filtrar por Gênero**: Liste filmes de um determinado gênero (e.g., Comédia, Terror).
  * **Atualizar Avaliação**: Modifique a nota de um filme existente com base em seu ID.
  * **Listar Filmes**: Visualize sua coleção ordenada por ano de lançamento (crescente) ou título (alfabética).
  * **Persistência de Dados**: Todos os dados são salvos em um arquivo `filmes.txt`, garantindo que suas informações não sejam perdidas entre as sessões.

## 🚀 Como Baixar e Instalar

Para obter o código-fonte e prepará-lo para execução, siga os passos abaixo:

1.  **Baixar o Código**:
    Você pode baixar os arquivos diretamente ou clonar o repositório Git (se disponível). Assumindo que os arquivos `main.c`, `filmes.c` e `filmes.h` estejam em um diretório, você pode simplesmente baixá-los e colocá-los juntos em uma pasta de sua escolha.

2.  **Compilador C**:
    Este projeto é escrito em C e requer um compilador C para ser construído. O `GCC` (GNU Compiler Collection) é amplamente recomendado e está disponível para a maioria dos sistemas operacionais.

      * **No Linux (Ubuntu/Debian)**:
        ```bash
        sudo apt update
        sudo apt install build-essential
        ```
      * **No macOS**:
        Instale as ferramentas de linha de comando do Xcode:
        ```bash
        xcode-select --install
        ```
      * **No Windows**:
        Recomenda-se instalar o ` ` para obter o GCC. Você pode baixá-lo do site oficial ou usar um gerenciador de pacotes como `Chocolatey`:
        ```bash
        choco install mingw
        ```

## 🛠️ Como Compilar o Projeto

Após baixar os arquivos e ter um compilador C instalado, navegue até o diretório onde os arquivos do projeto foram salvos via terminal e compile-os:

```bash
gcc main.c filmes.c -o filmes
```

  * `gcc`: O comando para invocar o compilador GCC.
  * `main.c filmes.c`: Os arquivos fonte que serão compilados.
  * `-o filmes`: A opção `-o` especifica o nome do arquivo executável de saída. Neste caso, o programa será chamado `filmes` (ou `filmes.exe` no Windows).

## ▶️ Como Testar e Rodar

Com o projeto compilado, você pode executá-lo a partir do terminal:

```bash
./filmes
```

(No Windows, você pode precisar digitar `filmes.exe` ou apenas `filmes` dependendo da sua configuração de PATH).

Ao executar o programa, você verá um menu interativo:

```
1-Adicionar 2-Buscar Diretor 3-Filtrar Genero 4-Atualizar Avaliacao 5-Listar (1-Ano/0-Titulo) 0-Sair:
```

### Exemplos de Uso:

#### 1\. Adicionar um Filme

```
1-Adicionar 2-Buscar Diretor 3-Filtrar Genero 4-Atualizar Avaliacao 5-Listar (1-Ano/0-Titulo) 0-Sair: 1
ID: 101
Titulo: Blade Runner 2049
Diretor: Denis Villeneuve
Ano: 2017
Genero: Ficcao Cientifica
Avaliacao (0-10): 8.0
```

#### 2\. Buscar Filmes por Diretor

```
1-Adicionar 2-Buscar Diretor 3-Filtrar Genero 4-Atualizar Avaliacao 5-Listar (1-Ano/0-Titulo) 0-Sair: 2
Diretor: Denis Villeneuve
Blade Runner 2049 (2017) - 8.0
```

#### 3\. Filtrar Filmes por Gênero

```
1-Adicionar 2-Buscar Diretor 3-Filtrar Genero 4-Atualizar Avaliacao 5-Listar (1-Ano/0-Titulo) 0-Sair: 3
Genero: Ficcao Cientifica
Blade Runner 2049 (2017) - 8.0
```

#### 4\. Atualizar Avaliação de um Filme

```
1-Adicionar 2-Buscar Diretor 3-Filtrar Genero 4-Atualizar Avaliacao 5-Listar (1-Ano/0-Titulo) 0-Sair: 4
ID do filme: 101
Nova avaliacao: 8.5
```

#### 5\. Listar Filmes (Exemplo: por Título)

```
1-Adicionar 2-Buscar Diretor 3-Filtrar Genero 4-Atualizar Avaliacao 5-Listar (1-Ano/0-Titulo) 0-Sair: 5
1 para ordenar por Ano, 0 por Titulo: 0
Blade Runner 2049 (2017) - Dir: Denis Villeneuve, Gênero: Ficcao Cientifica, Nota: 8.5
```

#### 0\. Sair do Programa

Para sair do programa e salvar as alterações no arquivo `filmes.txt`, digite `0` no menu principal:

```
1-Adicionar 2-Buscar Diretor 3-Filtrar Genero 4-Atualizar Avaliacao 5-Listar (1-Ano/0-Titulo) 0-Sair: 0
```

-----