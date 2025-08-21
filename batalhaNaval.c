#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 5  // Tamanho das matrizes de habilidade (5x5)

// Função para exibir a matriz na tela
void exibirMatriz(int matriz[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            if (matriz[i][j] == 1)
                printf("3 ");
            else
                printf("0 ");
        }
        printf("\n");
    }
    printf("\n");
}

// Gera a matriz em formato de cone
void gerarCone(int matriz[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            int meio = TAMANHO / 2;
            if (j >= meio - i && j <= meio + i)
                matriz[i][j] = 1;
            else
                matriz[i][j] = 0;
        }
    }
}

// Gera a matriz em formato de cruz
void gerarCruz(int matriz[TAMANHO][TAMANHO]) {
    int meio = TAMANHO / 2;
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            if (i == meio || j == meio)
                matriz[i][j] = 1;
            else
                matriz[i][j] = 0;
        }
    }
}

// Gera a matriz em formato de octaedro (losango)
void gerarOctaedro(int matriz[TAMANHO][TAMANHO]) {
    int meio = TAMANHO / 2;
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            if (abs(i - meio) + abs(j - meio) <= meio)
                matriz[i][j] = 1;
            else
                matriz[i][j] = 0;
        }
    }
}

int main() {
    int cone[TAMANHO][TAMANHO];
    int cruz[TAMANHO][TAMANHO];
    int octaedro[TAMANHO][TAMANHO];

    // Gerar matrizes
    gerarCone(cone);
    gerarCruz(cruz);
    gerarOctaedro(octaedro);

    // Exibir cada uma
    printf("Matriz - Habilidade: Cone\n");
    exibirMatriz(cone);

    printf("Matriz - Habilidade: Cruz\n");
    exibirMatriz(cruz);

    printf("Matriz - Habilidade: Octaedro\n");
    exibirMatriz(octaedro);

    return 0;
}




    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0


