Sistema desenvolvido em linguagem C para gerenciamento de um álbum de figurinhas da Copa do Mundo.

O programa permite cadastrar figurinhas, atualizar suas quantidades, visualizar o estado do álbum, identificar figurinhas faltantes e repetidas, além de salvar e carregar os dados utilizando arquivos.


O sistema possui um menu interativo com as seguintes opções:

| Opção | Funcionalidade              |
| ----- | --------------------------- |
| 1     | Cadastrar figurinha         |
| 2     | Atualizar quantidade        |
| 3     | Exibir álbum                |
| 4     | Listar figurinhas faltantes |
| 5     | Listar figurinhas repetidas |
| 6     | Salvar álbum em arquivo     |
| 7     | Carregar álbum de arquivo   |
| 8     | Sair do programa            |

### 1. Cadastrar figurinha

Permite cadastrar uma nova figurinha informando:

* ID da figurinha;
* Nome do jogador;
* Quantidade de exemplares.

A seleção é determinada automaticamente a partir do ID da figurinha.

O programa também verifica se o ID já foi cadastrado para evitar duplicidade de registros.

### 2. Atualizar quantidade

Permite alterar a quantidade de uma figurinha já cadastrada.

O usuário informa o ID e a nova quantidade.

### 3. Exibir álbum

Exibe uma representação do álbum contendo todas as seleções e suas respectivas 26 figurinhas.

A legenda utilizada é:

* `[1]` → figurinha possui pelo menos um exemplar;
* `[0]` → figurinha faltante.

### 4. Listar figurinhas faltantes

Percorre todas as figurinhas possíveis do álbum e identifica aquelas que:

* ainda não foram cadastradas; ou
* possuem quantidade igual a `0`.

São exibidos o ID e a seleção correspondente.

### 5. Listar figurinhas repetidas

Identifica as figurinhas que possuem mais de um exemplar.

Por exemplo, se uma figurinha possui quantidade `4`, o programa informa que existem `3` repetidas.

### 6. Salvar álbum em arquivo

Salva os dados cadastrados em um arquivo de texto.

Cada figurinha é armazenada no seguinte formato:

```text
ID;Seleção;Jogador;Quantidade
```


### 7. Carregar álbum de arquivo

Permite recuperar os dados anteriormente salvos em um arquivo.

Caso uma figurinha já exista na memória, seus dados são atualizados. Caso contrário, uma nova figurinha é adicionada ao álbum.

---

##  Estrutura dos dados

As informações de cada figurinha são armazenadas utilizando a estrutura `Figurinha`:

Cada registro possui:

* `id` → identificador único da figurinha;
* `selecao` → seleção à qual a figurinha pertence;
* `jogador` → nome do jogador;
* `quantidade` → quantidade de exemplares que o usuário possui.

---

##  Seleções

O programa possui **48 seleções**, organizadas em uma matriz de 48 × 26.

Cada seleção possui até **26 jogadores/figurinhas**.


##  Tecnologias utilizadas

Linguagem: C
Bibliotecas:

  * `stdio.h` — entrada, saída e manipulação de arquivos;
  * `string.h` — manipulação de strings;
  * `stdlib.h` — conversão de strings e outras funções utilitárias.




## Formato do arquivo

O sistema utiliza arquivos de texto para persistência dos dados.

O formato de cada linha é:

text
id;selecao;jogador;quantidade


Exemplo:

text
1;Canada;Jogador 1;1
2;Canada;Jogador 2;3
27;Estados Unidos;Jogador 1;0

O caractere `;` é utilizado como separador entre os campos.

### `buscarFigurinha()`

Procura uma figurinha pelo seu ID dentro do álbum.

Retorna o índice encontrado ou `-1` caso a figurinha não exista.

### `cadastrarFigurinha()`

Realiza o cadastro de uma nova figurinha.

### `atualizarQuantidade()`

Atualiza a quantidade de uma figurinha existente.

### `exibirAlbum()`

Monta e exibe uma representação matricial do álbum.

### `listarFaltantes()`

Lista todas as figurinhas que ainda não foram adquiridas.


### `listarRepetidas()`

Lista as figurinhas que possuem mais de um exemplar.

### `salvarArquivo()`

Salva o conteúdo do álbum em um arquivo de texto.


### `carregarArquivo()`

Carrega os dados de um arquivo para a memória.

## Conceitos de programação utilizados

O projeto utiliza diversos conceitos fundamentais da linguagem C:

* `struct`;
* vetores;
* matrizes;
* strings;
* ponteiros;
* funções;
* passagem de parâmetros;
* manipulação de arquivos;
* leitura e escrita de dados;
* busca sequencial;
* `switch/case`;
* estruturas de repetição;
* `strcpy()`;
* `strtok()`;
* `fopen()`;
* `fprintf()`;
* `fgets()`;
* `atoi()`.



