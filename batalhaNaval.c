#include <stdio.h>
#include <stdlib.h>

#define TAM 10

int main() {
    int navios[TAM][TAM] = {0};
    int habilidades[TAM][TAM] = {0};

    /* =========================
       NÍVEL NOVATO - AVENTUREIRO – NAVIOS
       ========================= */

    // Horizontal
    navios[2][2] = navios[2][3] = navios[2][4] = 3;

    // Vertical (mais abaixo para não embolar)
    navios[4][7] = navios[5][7] = navios[6][7] = 3;

    // Diagonal principal
    navios[7][1] = navios[8][2] = navios[9][3] = 3;

    // Diagonal secundária
    navios[1][9] = navios[2][8] = navios[3][7] = 3;

    /* =========================
       NÍVEL MESTRE – HABILIDADES
       DESENHOS FIXOS 5x5
       ========================= */

    // CONE (valor 3)
    habilidades[0][4] = 3;
    habilidades[1][3] = habilidades[1][4] = habilidades[1][5] = 3;
    habilidades[2][2] = habilidades[2][3] = habilidades[2][4] = habilidades[2][5] = habilidades[2][6] = 3;

    // OCTAEDRO (valor 5) — COMPLETO
    habilidades[4][4] = 5;
    habilidades[5][3] = habilidades[5][4] = habilidades[5][5] = 5;
    habilidades[6][4] = 5;

    // CRUZ (valor 2)
    habilidades[6][1] = 2;
    habilidades[7][0] = habilidades[7][1] = habilidades[7][2] = 2;
    habilidades[8][1] = 2;
    habilidades[9][1] = 2;

    /* =========================
       IMPRESSÃO
       ========================= */

    printf("\n TABULEIRO NAVIOS            TABULEIRO HABILIDADES\n", "");
    printf("   A B C D E F G H I J         A B C D E F G H I J\n", "");

    for (int i = 0; i < TAM; i++) {
        printf("%2d ", i + 1);
        for (int j = 0; j < TAM; j++) {
            printf("%d ", navios[i][j]);
        }

        printf("     %2d ", i + 1);
        for (int j = 0; j < TAM; j++) {
            printf("%d ", habilidades[i][j]);
        }
        printf("\n");
    }

    printf("\nLegenda:\n");
    printf("0 = Água | 3 = Navio | 3 = Cone | 2 = Cruz | 5 = Octaedro\n");

    return 0;
}
