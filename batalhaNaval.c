#include <stdio.h>

/*
========================================
 DEFINIÇÕES GERAIS (NÍVEL NOVATO)
========================================
*/
#define TAM 10        // Tamanho do tabuleiro (10x10)
#define NAVIO_TAM 3  // Tamanho fixo dos navios
#define AGUA 0        // Representa água no tabuleiro
#define NAVIO 3       // Representa parte de um navio

int main() {

    /*
    ========================================
     1. DECLARAÇÃO DO TABULEIRO (NÍVEL NOVATO)
    ========================================
    */
    int tabuleiro[TAM][TAM];

    /*
    ========================================
     2. INICIALIZAÇÃO DO TABULEIRO (NÍVEL NOVATO)
     Preenche todas as posições com 0 (água)
    ========================================
    */
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    /*
    ========================================
     3. DECLARAÇÃO DOS NAVIOS (NÍVEL NOVATO)
     Navios representados por vetores 1D
    ========================================
    */
    int navioHorizontal[NAVIO_TAM] = {NAVIO, NAVIO, NAVIO};
    int navioVertical[NAVIO_TAM]   = {NAVIO, NAVIO, NAVIO};
    int navioDiagonal1[NAVIO_TAM]  = {NAVIO, NAVIO, NAVIO};
    int navioDiagonal2[NAVIO_TAM]  = {NAVIO, NAVIO, NAVIO};

    /*
    ========================================
     4. COORDENADAS DOS NAVIOS
     - Horizontal e Vertical → NÍVEL NOVATO
     - Diagonais → NÍVEL AVENTUREIRO
    ========================================
    */

    // --- NÍVEL AVENTUREIRO (Diagonais)
    int d1_linha = 0, d1_coluna = 0; // Diagonal ↘
    int d2_linha = 0, d2_coluna = 9; // Diagonal ↙

    // --- NÍVEL NOVATO
    int h_linha = 6, h_coluna = 1;   // Horizontal
    int v_linha = 4, v_coluna = 8;   // Vertical

    /*
    ========================================
     5. POSICIONAMENTO DE NAVIO DIAGONAL ↘
     (NÍVEL AVENTUREIRO)
     Linha e coluna aumentam juntas
    ========================================
    */
    for (int i = 0; i < NAVIO_TAM; i++) {
        tabuleiro[d1_linha + i][d1_coluna + i] = navioDiagonal1[i];
    }

    /*
    ========================================
     6. POSICIONAMENTO DE NAVIO DIAGONAL ↙
     (NÍVEL AVENTUREIRO)
     Linha aumenta e coluna diminui
    ========================================
    */
    for (int i = 0; i < NAVIO_TAM; i++) {
        tabuleiro[d2_linha + i][d2_coluna - i] = navioDiagonal2[i];
    }

    /*
    ========================================
     7. POSICIONAMENTO DE NAVIO HORIZONTAL
     (NÍVEL NOVATO)
     Coluna varia, linha fixa
    ========================================
    */
    for (int i = 0; i < NAVIO_TAM; i++) {
        tabuleiro[h_linha][h_coluna + i] = navioHorizontal[i];
    }

    /*
    ========================================
     8. POSICIONAMENTO DE NAVIO VERTICAL
     (NÍVEL NOVATO)
     Linha varia, coluna fixa
    ========================================
    */
    for (int i = 0; i < NAVIO_TAM; i++) {
        tabuleiro[v_linha + i][v_coluna] = navioVertical[i];
    }

    /*
    ========================================
     9. EXIBIÇÃO DO TABULEIRO
     (NÍVEL NOVATO – saída visual)
    ========================================
    */
    printf("\nTABULEIRO BATALHA NAVAL\n\n");

    // Cabeçalho com letras A–J
    printf("    ");
    for (char c = 'A'; c <= 'J'; c++) {
        printf("%c ", c);
    }
    printf("\n");

    // Linhas numeradas de 1 a 10
    for (int i = 0; i < TAM; i++) {
        printf("%2d  ", i + 1);
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
