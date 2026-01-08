#include<stdio.h>
#include<stdlib.h>

void imprime(char tabuleiro[3][3]) {
    printf("\n");
    printf(" %c | %c | %c \n", tabuleiro[0][0], tabuleiro[0][1], tabuleiro[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", tabuleiro[1][0], tabuleiro[1][1], tabuleiro[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", tabuleiro[2][0], tabuleiro[2][1], tabuleiro[2][2]);
    printf("\n");
}

void inicializa(char (*tabuleiro)[3]) {
    for(int linha = 0; linha < 3; linha++) {
        for(int coluna = 0; coluna < 3; coluna++) {
            tabuleiro[linha][coluna] = ' ';
        }
    }
}

int jogadas_restantes(char (*tabuleiro)[3]) {

    int slot_vazio = 0;

    for(int linha=0; linha<3; linha++) {
        for(int coluna=0; coluna<3; coluna++) {
            if(tabuleiro[linha][coluna] == ' ') {
                slot_vazio++;
            }        
        }
    }

    return slot_vazio;
}
    
int checa_vencedor(char tabuleiro[3][3], char jogador) {
    for (int i = 0; i < 3; i++) {
        if (
            (tabuleiro[i][0] == jogador &&
             tabuleiro[i][1] == jogador &&
             tabuleiro[i][2] == jogador) ||

            (tabuleiro[0][i] == jogador &&
             tabuleiro[1][i] == jogador &&
             tabuleiro[2][i] == jogador)
        ) {
            return 1;
        }
    }
    if ((tabuleiro[0][0] == jogador && tabuleiro[1][1] == jogador &&
                tabuleiro[2][2] == jogador) || (tabuleiro[0][2] == jogador &&
                    tabuleiro[1][1] == jogador && tabuleiro[2][0] == jogador)) {
        return 1;
    }

    return 0;
}


void coordenadas() {
    printf("\n");
    printf(" 00 | 01 | 02 \n");
    printf("----|----|----\n");
    printf(" 10 | 11 | 12 \n");
    printf("----|----|----\n");
    printf(" 20 | 21 | 22 \n");
    printf("\n");
}

void obter_jogada(char (*tabuleiro)[3], char jogador) {
    int linha, coluna;
    printf("Vez: %c\n", jogador);
    printf("Onde você quer jogar? informe a linha e coluna\n");
    coordenadas();

    while(1) {
        printf("linha: ");
        if(scanf("%d", &linha) != 1) {
            while(getchar() != '\n');
            printf("Entrada inválida.\n");
            continue;
        }
        
        printf("coluna: ");
        if(scanf("%d", &coluna) != 1) {
            while(getchar() != '\n');
            printf("Entrada inválida.\n");
            continue;
        }
        
        if(linha < 0 || linha > 2 || coluna < 0 || coluna > 2) {
            printf("cordenadas inválidas! linha, e coluna devem estar entre 0 e 2\n");
            continue;
        }

        if(tabuleiro[linha][coluna] != ' ') {
            printf("A posição já está preenchida! Escolha outra\n");
            continue;
        }
        break;
    }

    tabuleiro[linha][coluna] = jogador;
    imprime(tabuleiro);
}

int main() {
    char tabuleiro[3][3];
    char jogador_um = 'x';
    char jogador_dois = 'o';

    inicializa(tabuleiro);
    imprime(tabuleiro);

    int jogador = jogador_um;

    while(1) {
        obter_jogada(tabuleiro, jogador);
        
        //se vencedor retorna 1 caso contrário 0
        if(checa_vencedor(tabuleiro, jogador)) {
            printf("Parabéns '%c', você ganhou o jogo!\n", jogador);
            exit(EXIT_SUCCESS);
        } else if(jogadas_restantes(tabuleiro) == 0){
            printf("O jogo empatou!\n");
            exit(EXIT_SUCCESS);
        }

        if(jogador == jogador_um) jogador = jogador_dois;
        else jogador = jogador_um;
    }
}
