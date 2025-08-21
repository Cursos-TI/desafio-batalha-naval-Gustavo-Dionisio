#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define OCUPADO 3
#define AGUA 0

// Função para exibir o tabuleiro com coordenadas
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    // Cabeçalho com letras A-J
    printf("   ");
    for (char letra = 'A'; letra < 'A' + TAMANHO_TABULEIRO; letra++) {
        printf(" %c", letra);
    }
    printf("\n");

    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%2d ", i + 1);
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf(" %d", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função para verificar se o navio pode ser colocado
int podeColocar(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, int delta_linha, int delta_coluna) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int l = linha + i * delta_linha;
        int c = coluna + i * delta_coluna;

        if (l < 0 || l >= TAMANHO_TABULEIRO || c < 0 || c >= TAMANHO_TABULEIRO)
            return 0; // fora dos limites

        if (tabuleiro[l][c] != AGUA)
            return 0; // sobreposição
    }
    return 1;
}

// Função para posicionar o navio no tabuleiro
void posicionarNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, int delta_linha, int delta_coluna) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int l = linha + i * delta_linha;
        int c = coluna + i * delta_coluna;
        tabuleiro[l][c] = OCUPADO;
    }
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

    // Coordenadas e direções dos 4 navios (linha, coluna, direção linha, direção coluna)

    // 1. Navio horizontal: linha 2, colunas 3-5 (índices 1,2,3)
    int l1 = 1, c1 = 2, dl1 = 0, dc1 = 1;

    // 2. Navio vertical: coluna 7, linhas 5-7 (índices 4,5,6)
    int l2 = 4, c2 = 6, dl2 = 1, dc2 = 0;

    // 3. Navio diagonal principal (descendo): inicia em (0,0) → (0,0), (1,1), (2,2)
    int l3 = 0, c3 = 0, dl3 = 1, dc3 = 1;

    // 4. Navio diagonal secundária (subindo): inicia em (9,0) → (9,0), (8,1), (7,2)
    int l4 = 9, c4 = 0, dl4 = -1, dc4 = 1;

    // Tenta posicionar cada navio com validação
    if (podeColocar(tabuleiro, l1, c1, dl1, dc1))
        posicionarNavio(tabuleiro, l1, c1, dl1, dc1);
    else
        printf("Erro: Não foi possível posicionar o navio horizontal.\n");

    if (podeColocar(tabuleiro, l2, c2, dl2, dc2))
        posicionarNavio(tabuleiro, l2, c2, dl2, dc2);
    else
        printf("Erro: Não foi possível posicionar o navio vertical.\n");

    if (podeColocar(tabuleiro, l3, c3, dl3, dc3))
        posicionarNavio(tabuleiro, l3, c3, dl3, dc3);
    else
        printf("Erro: Não foi possível posicionar o navio diagonal principal.\n");

    if (podeColocar(tabuleiro, l4, c4, dl4, dc4))
        posicionarNavio(tabuleiro, l4, c4, dl4, dc4);
    else
        printf("Erro: Não foi possível posicionar o navio diagonal secundária.\n");

    // Exibe o tabuleiro final
    exibirTabuleiro(tabuleiro);

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


