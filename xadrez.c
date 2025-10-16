#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // para usar sleep (Unix). Em Windows, troque por Sleep(ms).

#define TAM 8
#define DELAY 300000 // microsegundos (0.3s entre movimentos)

// ---------- Funções auxiliares ----------
void limpar_tabuleiro(char tab[TAM][TAM]) {
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            tab[i][j] = '.';
}

void mostrar_tabuleiro(char tab[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++)
            printf("%c ", tab[i][j]);
        printf("\n");
    }
    printf("\n");
    usleep(DELAY); // pausa curta para visualizar movimento
}

void mover_peca(char tab[TAM][TAM], int *linha, int *coluna, int nova_linha, int nova_coluna, char simbolo) {
    tab[*linha][*coluna] = '.';
    *linha = nova_linha;
    *coluna = nova_coluna;
    tab[*linha][*coluna] = simbolo;
    mostrar_tabuleiro(tab);
}

// ---------- Nível Novato ----------
void nivel_novato() {
    char tab[TAM][TAM];
    limpar_tabuleiro(tab);

    printf("\n=== NÍVEL NOVATO ===\n");

    // Começamos com as peças no centro
    int bispoL = 4, bispoC = 4;
    int torreL = 5, torreC = 1;
    int rainhaL = 2, rainhaC = 6;

    tab[bispoL][bispoC] = 'B';
    tab[torreL][torreC] = 'T';
    tab[rainhaL][rainhaC] = 'Q';
    mostrar_tabuleiro(tab);

    printf("Movendo Bispo 5 casas (Cima+Direita)\n");
    for (int i = 0; i < 5; i++)
        mover_peca(tab, &bispoL, &bispoC, bispoL - 1, bispoC + 1, 'B');

    printf("Movendo Torre 5 casas para a Direita\n");
    for (int i = 0; i < 5; i++)
        mover_peca(tab, &torreL, &torreC, torreL, torreC + 1, 'T');

    printf("Movendo Rainha 8 casas para a Esquerda\n");
    for (int i = 0; i < 8 && rainhaC > 0; i++)
        mover_peca(tab, &rainhaL, &rainhaC, rainhaL, rainhaC - 1, 'Q');
}

// ---------- Nível Aventureiro ----------
void nivel_aventureiro() {
    char tab[TAM][TAM];
    limpar_tabuleiro(tab);

    printf("\n=== NÍVEL AVENTUREIRO ===\n");

    int cavaloL = 7, cavaloC = 1;
    tab[cavaloL][cavaloC] = 'C';
    mostrar_tabuleiro(tab);

    printf("Movendo Cavalo em L (Baixo + Esquerda)\n");

    // Usando loops aninhados: for + while
    for (int bloco = 0; bloco < 2; bloco++) {
        int movimentos = 0;
        while (movimentos < 3) {
            if (movimentos < 2) {
                // Dois para baixo
                if (cavaloL + 1 < TAM)
                    mover_peca(tab, &cavaloL, &cavaloC, cavaloL + 1, cavaloC, 'C');
            } else {
                // Um para esquerda
                if (cavaloC - 1 >= 0)
                    mover_peca(tab, &cavaloL, &cavaloC, cavaloL, cavaloC - 1, 'C');
            }
            movimentos++;
        }
    }
}

// ---------- Funções recursivas para o Nível Mestre ----------
void mover_bispo_rec(char tab[TAM][TAM], int *l, int *c, int passos) {
    if (passos == 0 || *l == 0 || *c == TAM - 1) return;
    mover_peca(tab, l, c, *l - 1, *c + 1, 'B');
    mover_bispo_rec(tab, l, c, passos - 1);
}

void mover_torre_rec(char tab[TAM][TAM], int *l, int *c, int passos) {
    if (passos == 0 || *c == TAM - 1) return;
    mover_peca(tab, l, c, *l, *c + 1, 'T');
    mover_torre_rec(tab, l, c, passos - 1);
}

void mover_rainha_rec(char tab[TAM][TAM], int *l, int *c, int passos) {
    if (passos == 0 || *c == 0) return;
    mover_peca(tab, l, c, *l, *c - 1, 'Q');
    mover_rainha_rec(tab, l, c, passos - 1);
}

void mover_cavalo_maestro(char tab[TAM][TAM], int *l, int *c) {
    printf("Movendo Cavalo 1 vez em L (Cima+Direita)\n");
    for (int i = 0, j = 0; i < 3; i++, j++) {
        if (i < 2) {
            if (*l - 1 >= 0)
                mover_peca(tab, l, c, *l - 1, *c, 'C');
            else break;
        } else {
            if (*c + 1 < TAM)
                mover_peca(tab, l, c, *l, *c + 1, 'C');
        }
    }
}

// ---------- Nível Mestre ----------
void nivel_mestre() {
    char tab[TAM][TAM];
    limpar_tabuleiro(tab);

    printf("\n=== NÍVEL MESTRE ===\n");

    int bispoL = 7, bispoC = 0;
    int torreL = 5, torreC = 1;
    int rainhaL = 3, rainhaC = 7;
    int cavaloL = 6, cavaloC = 2;

    tab[bispoL][bispoC] = 'B';
    tab[torreL][torreC] = 'T';
    tab[rainhaL][rainhaC] = 'Q';
    tab[cavaloL][cavaloC] = 'C';
    mostrar_tabuleiro(tab);

    mover_bispo_rec(tab, &bispoL, &bispoC, 5);
    mover_torre_rec(tab, &torreL, &torreC, 5);
    mover_rainha_rec(tab, &rainhaL, &rainhaC, 8);
    mover_cavalo_maestro(tab, &cavaloL, &cavaloC);
}

// ---------- Programa principal ----------
int main() {
    int opcao;

    printf("=====================================\n");
    printf("         MATECHECK - TABULEIRO       \n");
    printf("=====================================\n");
    printf("Escolha o nível:\n");
    printf("1 - Novato\n");
    printf("2 - Aventureiro\n");
    printf("3 - Mestre\n");
    printf("Opção: ");
    scanf("%d", &opcao);

    switch (opcao) {
        case 1: nivel_novato(); break;
        case 2: nivel_aventureiro(); break;
        case 3: nivel_mestre(); break;
        default: printf("Opção inválida!\n");
    }

    printf("\nDesafio concluído. Fim da simulação.\n");
    return 0;
}
