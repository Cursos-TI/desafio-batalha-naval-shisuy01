#include <stdio.h>

#define TAM 10
#define NAVIO_TAM 3
#define AGUA 0
#define NAVIO 3

int main(){
    
    // ===========================
    // 1. DECLARAÇÃO DO TABULEIRO
    // ===========================

    int tabuleiro[TAM][TAM];

    // inicializa todas as posições com água (0)
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // ===================================
    // 2. DECLARAÇÃO DOS NAVIOS (VETORES)
    // ===================================
    int navioHorizontal[NAVIO_TAM] = {NAVIO, NAVIO, NAVIO};
    int navioVertical[NAVIO_TAM] = {NAVIO, NAVIO, NAVIO};

    // Coordenadas iniciais (linha, coluna)
    int linhaH = 2, colunaH = 3; // navio horizontal
    int linhaV = 5, colunaV = 6; // navio vertical 

    // ===================================
    // 3. POSICIONAMENTO NAVIO HORIZONTAL
    // ===================================
    if (colunaH + NAVIO_TAM <= TAM) {
        int podeColocar = 1;

        // Verifica sobreposição 
        for (int i = 0; i < NAVIO_TAM; i++) {
            if (tabuleiro[linhaH][colunaH + i] != AGUA) {
                podeColocar = 0;
            }
        }

        // Coloca o navio no tabuleiro
        if (podeColocar) {
            for (int i = 0; i < NAVIO_TAM; i++) {
                tabuleiro[linhaH][colunaH + i] = navioHorizontal[i];
            }
        }
    }

    // ==================================
    // 4. POSICIONAMENTO NAVIO VERTICAL 
    // ==================================
    if (linhaV + NAVIO_TAM <= TAM) {
        int podeColocar = 1;

        // Verifica sobreposição
        for (int i = 0; i < NAVIO_TAM; i++) {
            if (tabuleiro[linhaV + i][colunaV] != AGUA) {
                podeColocar = 0;
            }
        }

        // coloca o navio no tabuleiro
        if (podeColocar) {
            for (int i = 0; i < NAVIO_TAM; i++) {
                tabuleiro[linhaV + i][colunaV] = navioVertical[i];
            }
        }
    }

    // =========================
    // 5. EXIBIÇÃO DO TABULEIRO 
    // =========================

    printf("\nTABULERIO BATALHA NAVAL\n\n");

    // Cabeçalho com letras A-J
    printf("   ");
    for (char letra = 'A'; letra <= 'J'; letra++) {
        printf("%c ", letra);
    }
     
    printf("\n");

    // Linhas numeradas de 1 a 10
    for(int i = 0; i < TAM; i++) {
        printf("%2d ", i + 1);

        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        } 
        printf("\n");
    } 

  return 0;
  
}