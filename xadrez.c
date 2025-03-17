#include <stdio.h>

// Função recursiva para movimentação da Torre
void moverTorre(int casas, char direcao[]) {
    if (casas == 0) return; // Caso base da recursão

    printf("%s\n", direcao); // Imprime a direção do movimento
    moverTorre(casas - 1, direcao); // Chamada recursiva reduzindo as casas
}

// Função recursiva para movimentação do Bispo
void moverBispo(int casas, int x, int y) {
    if (casas == 0) return; // Caso base da recursão

    printf("Diagonal: (%d, %d)\n", x, y); // Imprime a posição do Bispo
    moverBispo(casas - 1, x + 1, y + 1); // Move diagonalmente (recursão)
}

// Função com loops aninhados para movimentação do Bispo
void moverBispoLoops(int casas) {
    printf("\nMovimento do Bispo (Loops Aninhados):\n");

    for (int i = 1; i <= casas; i++) { // Movimento vertical (linhas)
        for (int j = 1; j <= casas; j++) { // Movimento horizontal (colunas)
            printf("Diagonal: (%d, %d)\n", i, j);
        }
    }
}

// Função recursiva para movimentação da Rainha (combina Torre e Bispo)
void moverRainha(int casas, int x, int y) {
    if (casas == 0) return; // Caso base

    printf("Rainha move-se para: (%d, %d)\n", x, y);
    moverRainha(casas - 1, x + 1, y + 1); // Movimento diagonal
    moverRainha(casas - 1, x + 1, y); // Movimento horizontal
    moverRainha(casas - 1, x, y + 1); // Movimento vertical
}

// Função com loops aninhados para movimentação do Cavalo
void moverCavalo(int movimentos) {
    printf("\nMovimento do Cavalo (L - Duas casas para cima, uma para a direita):\n");

    int x = 0, y = 0; // Posição inicial

    for (int i = 0; i < movimentos; i++) {
        for (int j = 0; j < movimentos; j++) {
            x += 2; // Move duas casas para cima
            y += 1; // Move uma casa para a direita

            // Se atingir o limite, para
            if (x > movimentos || y > movimentos) break;

            printf("Cavalo move-se para: (%d, %d)\n", x, y);
        }
    }
}

// Função principal
int main() {
    int casas = 3; // Define quantas casas cada peça deve se mover

    // Torre se move para cima
    printf("Movimento da Torre:\n");
    moverTorre(casas, "Cima");

    printf("\nMovimento do Bispo (Recursão):\n");
    moverBispo(casas, 0, 0);

    moverBispoLoops(casas);

    printf("\nMovimento da Rainha:\n");
    moverRainha(casas, 0, 0);

    moverCavalo(casas);

    return 0;
}
