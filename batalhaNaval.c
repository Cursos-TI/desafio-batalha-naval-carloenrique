#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Aqui a gente vai posicionar os navios e também adicionar as habilidades especiais (cone, cruz e octaedro).

int main() {
    // Nível Novato - Posicionamento dos Navios
    // Criação do tabuleiro inicial 10x10, onde 0 é água
    int tabuleiro[10][10] = {0};

    // Posicionando dois navios (um na vertical e outro na horizontal) usando valor 3
    // Navio vertical (ocupa três casas na mesma coluna)
    tabuleiro[1][2] = 3;
    tabuleiro[2][2] = 3;
    tabuleiro[3][2] = 3;

    // Navio horizontal (ocupa três casas na mesma linha)
    tabuleiro[5][5] = 3;
    tabuleiro[5][6] = 3;
    tabuleiro[5][7] = 3;

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Agora mais dois navios, mas na diagonal
    tabuleiro[7][7] = 3;
    tabuleiro[8][8] = 3;
    tabuleiro[9][9] = 3;

    tabuleiro[2][7] = 3;
    tabuleiro[3][6] = 3;
    tabuleiro[4][5] = 3;

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Vamos criar três matrizes para representar as habilidades especiais
    int habilidade_cone[5][5] = {0};
    int habilidade_cruz[5][5] = {0};
    int habilidade_octaedro[5][5] = {0};

    // Preenchendo a habilidade CONE (forma de cone apontando para baixo)
    for (int i = 0; i < 5; i++) { // linha
        for (int j = 0; j < 5; j++) { // coluna
            if ((i == 0 && j == 2) || 
                (i == 1 && (j == 1 || j == 2 || j == 3)) || 
                (i == 2 && (j >= 0 && j <= 4))) {
                habilidade_cone[i][j] = 1; // Preenche o cone com 1
            }
        }
    }

    // Preenchendo a habilidade CRUZ (forma de cruz)
    for (int i = 0; i < 5; i++) { // linha
        for (int j = 0; j < 5; j++) { // coluna
            if (i == 2 || j == 2) {
                habilidade_cruz[i][j] = 1; // Preenche a cruz com 1
            }
        }
    }

    // Preenchendo a habilidade OCTAEDRO (losango, tipo um diamante)
    for (int i = 0; i < 5; i++) { // linha
        for (int j = 0; j < 5; j++) { // coluna
            if ((i == 0 && j == 2) ||
                (i == 1 && (j == 1 || j == 2 || j == 3)) ||
                (i == 2 && j == 2) ||
                (i == 3 && (j == 1 || j == 2 || j == 3)) ||
                (i == 4 && j == 2)) {
                habilidade_octaedro[i][j] = 1; // Preenche o octaedro com 1
            }
        }
    }

    // Definindo pontos de origem das habilidades no tabuleiro
    int origem_cone_linha = 1, origem_cone_coluna = 4;
    int origem_cruz_linha = 5, origem_cruz_coluna = 2;
    int origem_octaedro_linha = 7, origem_octaedro_coluna = 4;

    // Aplicando a habilidade CONE no tabuleiro
    for (int i = 0; i < 5; i++) { // linha do cone
        for (int j = 0; j < 5; j++) { // coluna do cone
            int linha = origem_cone_linha + i - 2; // Cálculo para centralizar
            int coluna = origem_cone_coluna + j - 2;
            if (linha >= 0 && linha < 10 && coluna >= 0 && coluna < 10) { // Checa limites
                if (habilidade_cone[i][j] == 1 && tabuleiro[linha][coluna] == 0) {
                    tabuleiro[linha][coluna] = 5; // Marca com 5 as áreas afetadas
                }
            }
        }
    }

    // Aplicando a habilidade CRUZ no tabuleiro
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int linha = origem_cruz_linha + i - 2;
            int coluna = origem_cruz_coluna + j - 2;
            if (linha >= 0 && linha < 10 && coluna >= 0 && coluna < 10) {
                if (habilidade_cruz[i][j] == 1 && tabuleiro[linha][coluna] == 0) {
                    tabuleiro[linha][coluna] = 5;
                }
            }
        }
    }

    // Aplicando a habilidade OCTAEDRO no tabuleiro
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int linha = origem_octaedro_linha + i - 2;
            int coluna = origem_octaedro_coluna + j - 2;
            if (linha >= 0 && linha < 10 && coluna >= 0 && coluna < 10) {
                if (habilidade_octaedro[i][j] == 1 && tabuleiro[linha][coluna] == 0) {
                    tabuleiro[linha][coluna] = 5;
                }
            }
        }
    }

    // Exibindo o tabuleiro final
    printf("\n=== Tabuleiro Final com Navios (3) e Habilidades (5) ===\n\n");
    for (int i = 0; i < 10; i++) { // Percorre linhas
        for (int j = 0; j < 10; j++) { // Percorre colunas
            printf("%d ", tabuleiro[i][j]); // Imprime valor do tabuleiro
        }
        printf("\n"); // Nova linha no final de cada linha
    }

    return 0; // Finaliza o programa
}
