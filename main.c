#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SELECOES 48
#define MAX_JOGADORES 26
#define MAX_FIGURINHAS (MAX_SELECOES * MAX_JOGADORES)

#define MAX_NOME_SELECAO 30
#define MAX_NOME_JOGADOR 50
#define MAX_NOME_ARQUIVO 50
#define MAX_LINHA 200

typedef struct {
    int id;
    char selecao[MAX_NOME_SELECAO];
    char jogador[MAX_NOME_JOGADOR];
    int quantidade;
} Figurinha;

int calcularLinha(int id);
int buscarFigurinha(Figurinha album[], int qtd, int id);
void lerLinha(char linha[], FILE *arq);
void exibirAlbum(Figurinha album[], int qtd, char selecoes[][MAX_NOME_SELECAO]);

void cadastrarFigurinha(Figurinha album[], int *qtd, char selecoes[][MAX_NOME_SELECAO]);
void atualizarQuantidade(Figurinha album[], int qtd);
void listarFaltantes(Figurinha album[], int qtd, char selecoes[][MAX_NOME_SELECAO]);
void listarRepetidas(Figurinha album[], int qtd);
void salvarArquivo(Figurinha album[], int qtd, char nomeArquivo[]);
void carregarArquivo(Figurinha album[], int *qtd, char nomeArquivo[], char selecoes[][MAX_NOME_SELECAO]);

int main() {
    Figurinha album[MAX_FIGURINHAS];
    int qtd = 0;
    int opcao;
    char nomeArquivo[MAX_NOME_ARQUIVO];

    char selecoes[MAX_SELECOES][MAX_NOME_SELECAO] = {
        "Canada", "Estados Unidos", "Mexico", "Curacao", "Haiti", "Panama",
        "Argentina", "Brasil", "Colombia", "Equador", "Paraguai", "Uruguai",
        "Alemanha", "Austria", "Belgica", "Bosnia e Herzegovina", "Croacia",
        "Escocia", "Espanha", "Franca", "Inglaterra", "Noruega",
        "Paises Baixos", "Portugal", "Republica Tcheca", "Suecia", "Suica",
        "Turquia", "Arabia Saudita", "Australia", "Catar", "Coreia do Sul",
        "Ira", "Iraque", "Japao", "Jordania", "Uzbequistao",
        "Africa do Sul", "Argelia", "Cabo Verde", "Costa do Marfim",
        "Egito", "Gana", "Marrocos", "RD do Congo", "Senegal", "Tunisia",
        "Nova Zelandia"
    };

    do {
        printf("\n===== GERENCIADOR DE ALBUM DA COPA =====\n");
        printf("1 - Cadastrar figurinha\n");
        printf("2 - Atualizar quantidade\n");
        printf("3 - Exibir album\n");
        printf("4 - Listar figurinhas faltantes\n");
        printf("5 - Listar figurinhas repetidas\n");
        printf("6 - Salvar album em arquivo\n");
        printf("7 - Carregar album de arquivo\n");
        printf("8 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarFigurinha(album, &qtd, selecoes);
                break;

            case 2:
                atualizarQuantidade(album, qtd);
                break;

            case 3:
                exibirAlbum(album, qtd, selecoes);
                break;

            case 4:
                listarFaltantes(album, qtd, selecoes);
                break;

            case 5:
                listarRepetidas(album, qtd);
                break;

            case 6:
                printf("Nome do arquivo para salvar: ");
                scanf(" %s", nomeArquivo);
                salvarArquivo(album, qtd, nomeArquivo);
                break;

            case 7:
                printf("Nome do arquivo para carregar: ");
                scanf(" %s", nomeArquivo);
                carregarArquivo(album, &qtd, nomeArquivo, selecoes);
                break;

            case 8:
                printf("Encerrando programa...\n");
                break;

            default:
                printf("Opcao invalida.\n");
        }

    } while (opcao != 8);

    return 0;
}

int calcularLinha(int id) {
    return (id - 1) / MAX_JOGADORES;
}

int buscarFigurinha(Figurinha album[], int qtd, int id) {
    int i;

    for (i = 0; i < qtd; i++) {
        if (album[i].id == id) {
            return i;
        }
    }

    return -1;
}

void lerLinha(char linha[], FILE *arq){
    fgets(linha, MAX_LINHA, arq);
    if(linha[strlen(linha)-1] == '\n')
        linha[strlen(linha)-1] = '\0';
}

void exibirAlbum(Figurinha album[], int qtd, char selecoes[][MAX_NOME_SELECAO]) {
    int matriz[MAX_SELECOES][MAX_JOGADORES] = {0};
    int i;
    int linha;
    int coluna;

    for (i = 0; i < qtd; i++) {
        linha = calcularLinha(album[i].id);
        coluna = (album[i].id - 1) % MAX_JOGADORES;

        if (album[i].quantidade > 0) {
            matriz[linha][coluna] = 1;
        }
    }

    printf("\n===== ALBUM =====\n\n");
    printf("Legenda: [1] = possui | [0] = faltante\n\n");

    printf("%-25s", "Selecao");
    for (coluna = 0; coluna < MAX_JOGADORES; coluna++) {
        printf("%3d", coluna + 1);
    }
    printf("\n");

    for (linha = 0; linha < MAX_SELECOES; linha++) {
        printf("%-25s", selecoes[linha]);

        for (coluna = 0; coluna < MAX_JOGADORES; coluna++) {
            printf("[%d]", matriz[linha][coluna]);
        }

        printf("\n");
    }
}

void cadastrarFigurinha(Figurinha album[], int *qtd, char selecoes[][MAX_NOME_SELECAO]) {
    char nomeJogador[MAX_NOME_JOGADOR];
    int quantidade;
    int id;
    int linha;
    int indiceFigurinha;

    printf("ID da figurinha: ");
    scanf("%d", &id);

    indiceFigurinha = buscarFigurinha(album, *qtd, id);

    if (indiceFigurinha != -1) {
        printf("Essa figurinha ja esta cadastrada.\n");
        return;
    }

    printf("Nome do jogador: ");
    scanf(" %s", nomeJogador);

    printf("Quantidade: ");
    scanf("%d", &quantidade);

    linha = calcularLinha(id);

    album[*qtd].id = id;
    strcpy(album[*qtd].selecao, selecoes[linha]);
    strcpy(album[*qtd].jogador, nomeJogador);
    album[*qtd].quantidade = quantidade;

    (*qtd)++;

    printf("Figurinha cadastrada com sucesso.\n");
}

void atualizarQuantidade(Figurinha album[], int qtd) {
    int id;
    int novaQuantidade;
    int indice;
    int posicao;

    printf("ID da figurinha: ");
    scanf("%d", &id);

    indice = buscarFigurinha(album, qtd, id);

    if (indice == -1) {
        printf("Figurinha nao encontrada.\n");
        return;
    }

    printf("Figurinha encontrada: %s - %s \n", album[indice].selecao, album[indice].jogador);

    printf("Nova quantidade: ");
    scanf("%d", &novaQuantidade);

    album[indice].quantidade = novaQuantidade;

    printf("Quantidade atualizada com sucesso.\n");
}

void listarFaltantes(Figurinha album[], int qtd, char selecoes[][MAX_NOME_SELECAO]) {
    int id;
    int indice;
    int linha;
    int encontrou = 0;

    printf("\n===== FIGURINHAS FALTANTES =====\n");

    for (id = 1; id <= MAX_FIGURINHAS; id++) {
        indice = buscarFigurinha(album, qtd, id);

        if (indice == -1 || album[indice].quantidade == 0) {
            linha = calcularLinha(id);

            printf("ID: %4d | Selecao: %s\n", id, selecoes[linha]);

            encontrou = 1;
        }
    }

    if (!encontrou) {
        printf("Nenhuma figurinha faltante.\n");
    }
}

void listarRepetidas(Figurinha album[], int qtd) {
    int i;
    int encontrou = 0;

    printf("\n===== FIGURINHAS REPETIDAS =====\n");

    for (i = 0; i < qtd; i++) {
        if (album[i].quantidade > 1) {

            printf("ID: %4d | Selecao: %s | Jogador: %s | Repetidas: %d\n",
                   album[i].id,
                   album[i].selecao,
                   album[i].jogador,
                   album[i].quantidade - 1);

            encontrou = 1;
        }
    }

    if (!encontrou) {
        printf("Nenhuma figurinha repetida.\n");
    }
}

void salvarArquivo(Figurinha album[], int qtd, char nomeArquivo[]) {
    FILE *arquivo;
    int i;

    arquivo = fopen(nomeArquivo, "w");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }

    for (i = 0; i < qtd; i++) {
        fprintf(arquivo, "%d;%s;%s;%d\n",
                album[i].id,
                album[i].selecao,
                album[i].jogador,
                album[i].quantidade);
    }

    fclose(arquivo);

    printf("Album salvo com sucesso no arquivo %s.\n", nomeArquivo);
}

void carregarArquivo(Figurinha album[], int *qtd, char nomeArquivo[], char selecoes[][MAX_NOME_SELECAO]) {
    FILE *arquivo;
    char linhaArquivo[MAX_LINHA];
    char *token;
    int id;
    int linhaSelecao;
    int indiceExistente;
    char jogador[MAX_NOME_JOGADOR];
    char selecao[MAX_NOME_SELECAO];
    int quantidade;

    arquivo = fopen(nomeArquivo, "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para leitura.\n");
        return;
    }

    while (1) {
        if (*qtd >= MAX_FIGURINHAS) {
            printf("Limite de figurinhas atingido durante a leitura.\n");
            break;
        }

        lerLinha(linhaArquivo, arquivo);

        token = strtok(linhaArquivo, ";");
        id = atoi(token);

        token = strtok(NULL, ";");
        strcpy(selecao, token);

        token = strtok(NULL, ";");
        strcpy(jogador, token);

        token = strtok(NULL, ";");
        quantidade = atoi(token);

        linhaSelecao = calcularLinha(id);

        indiceExistente = buscarFigurinha(album, *qtd, id);

        if (indiceExistente != -1) {
            strcpy(album[indiceExistente].selecao, selecoes[linhaSelecao]);
            strcpy(album[indiceExistente].jogador, jogador);
            album[indiceExistente].quantidade = quantidade;
        } else {
            album[*qtd].id = id;
            strcpy(album[*qtd].selecao, selecoes[linhaSelecao]);
            strcpy(album[*qtd].jogador, jogador);
            album[*qtd].quantidade = quantidade;

            (*qtd)++;
        }

        if(feof(arquivo))
            break;
    }

    fclose(arquivo);

    printf("Album carregado com sucesso. Total de figurinhas no album: %d\n", *qtd);
}
