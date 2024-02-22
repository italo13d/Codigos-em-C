#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/* Trabalho 1 de Algoritmos 2 realizados pelos alunos:
    Ítalo Nunes Tillmann de Abreu - 12221BSI238
    Carlos Eduardo Moreno Nunes Guerra - 12221BSI237
    */

int main()
{
    int hanoi[3][5];
    setlocale(LC_ALL,"pt_br.UTF-8");
    int *pa = &hanoi[0][4]; // Ponteiro para o topo da torre A
    int *pb = &hanoi[1][4]; // Ponteiro para o topo da torre B
    int *pc = &hanoi[2][4]; // Ponteiro para o topo da torre C

    for (int i = 0; i <5; i++){
        for (int j=0; j<3; j++){
            hanoi[j][i]=0;
        }
    }
    hanoi[0][4] = 1;
    hanoi[0][3] = 2;
    hanoi[0][2] = 3;
    hanoi[0][1] = 4;
    hanoi[0][0] = 5;
    
    int finished = 0;
    while (!finished){
        printf("Escolha uma opção: \n 1-Mover de A para B. Remove o elemento do topo de A e insere em B.\n 2-Mover de A para C. Remove o elemento do topo de A e insere em C.\n 3-Mover de B para C. Remove o elemento do topo de B e insere em C.\n 4-Mover de B para A. Remove o elemento do topo de B e insere em A.\n 5-Mover de C para B. Remove o elemento do topo de C e insere em B.\n");
        printf(" 6-Mover de C para A. Remove o elemento do topo de C e insere em A.\n 7-Desistir do jogo.\n");
        for (int i = 4; i >= 0; i--) {
                printf("| ");
                for (int j = 0; j < 3; j++) {
                    printf("%d ", hanoi[j][i]);
            }
                printf("|\n"); 
        }
    int a;
    scanf("%d", &a);

    if (a == 1) {
    // Mover de A para B. Remove o elemento do topo de A e insere em B
    // Encontrar o disco no topo da torre A
    while (*pa == 0 && pa > &hanoi[0][0]) {
        pa--;
    }
    int disk = *pa;
    if (disk == 0) {
        printf("Não há discos para mover na torre A.\n");
        continue;
    }

    // Encontrar a primeira posição vazia de baixo para cima na torre B
    pb = &hanoi[1][0];
    while (*pb != 0 && pb < &hanoi[1][4]) {
        pb++;
    }

    // Verificar se o movimento é válido (o disco sendo movido é menor que o disco no topo da torre B)
    if (pb > &hanoi[1][0] && disk > *(pb - 1)) {
        printf("Movimento inválido. O disco na torre A é maior que o disco no topo da torre B.\n");
        continue;
    }

    // Mover o disco da torre A para a torre B
    *pb = disk;
    *pa = 0;
}

if (a == 2) {
    // Mover de A para C. Remove o elemento do topo de A e insere em C
    // Encontrar o disco no topo da torre A
    while (*pa == 0 && pa > &hanoi[0][0]) {
        pa--;
    }
    int disk = *pa;
    if (disk == 0) {
        printf("Não há discos para mover na torre A.\n");
        continue;
    }

    // Encontrar a posição no topo da torre C
    pc = &hanoi[2][4];
    while (*pc == 0 && pc > &hanoi[2][0]) {
        pc--;
    }

    // Verificar se o disco é menor que o disco no topo da torre C ou se a torre C está vazia
    if (pc >= &hanoi[2][0] && (*pc == 0 || disk < *pc)) {
        // Mover o disco de A para C
        *pa = 0;
        *pc = disk;
    } else {
        printf("Não pode colocar um disco maior em cima de um disco menor.\n");
        continue;
    }

    // Redefinir o ponteiro para o topo da torre A
    pa = &hanoi[0][4];
    while (*pa == 0 && pa > &hanoi[0][0]) {
        pa--;
    }

    // Redefinir o ponteiro para o topo da torre C
    pc = &hanoi[2][4];
    while (*pc == 0 && pc > &hanoi[2][0]) {
        pc--;
    }
}

if (a == 3) {
    // Mover de B para C. Remove o elemento do topo de B e insere em C
    // Encontrar o disco no topo da torre B
    while (*pb == 0 && pb > &hanoi[1][0]) {
        pb--;
    }
    int disk = *pb;
    if (disk == 0) {
        printf("Não há discos para mover na torre B.\n");
        continue;
    }

    // Encontrar a primeira posição vazia na torre C de baixo para cima
    pc = &hanoi[2][0];
    while (*pc != 0 && pc < &hanoi[2][4]) {
        pc++;
    }

    // Verificar se o disco é menor que o disco abaixo na torre C ou se a torre C está vazia
    if (pc <= &hanoi[2][4] && (pc == &hanoi[2][0] || disk < *(pc - 1))) {
        // Mover o disco de B para C
        *pb = 0;
        *pc = disk;
    } else {
        printf("Não pode colocar um disco maior em cima de um disco menor.\n");
        continue;
    }

    // Redefinir o ponteiro para o topo da torre B
    pb = &hanoi[1][4];
    while (*pb == 0 && pb > &hanoi[1][0]) {
        pb--;
    }

    // Redefinir o ponteiro para o topo da torre C
    pc = &hanoi[2][4];
    while (*pc == 0 && pc > &hanoi[2][0]) {
        pc--;
    }
}

if (a == 4) {
    // Mover de B para A. Remove o elemento do topo de B e insere em A
    // Encontrar o disco no topo da torre B
    while (*pb == 0 && pb > &hanoi[1][0]) {
        pb--;
    }
    int disk = *pb;
    if (disk == 0) {
        printf("Não há discos para mover na torre B.\n");
        continue;
    }

    // Encontrar a posição no topo da torre A
    pa = &hanoi[0][4];
    while (*pa == 0 && pa > &hanoi[0][0]) {
        pa--;
    }
    if (*pa != 0) {
        printf("A torre A está cheia.\n");
        continue;
    }

    // Mover o disco de B para A
    *pb = 0;
    *pa = disk;
}

if (a == 5) {
    // Mover de C para B. Remove o elemento do topo de C e insere em B
    // Encontrar o disco no topo da torre C
    while (*pc == 0 && pc > &hanoi[2][0]) {
        pc--;
    }
    int disk = *pc;
    if (disk == 0) {
        printf("Não há discos para mover na torre C.\n");
        continue;
    }

    // Encontrar a primeira posição vazia de baixo para cima na torre B
    pb = &hanoi[1][0];
    while (*pb != 0 && pb < &hanoi[1][4]) {
        pb++;
    }

    // Verificar se o movimento é válido (o disco sendo movido é menor que o disco no topo da torre B)
    if (pb > &hanoi[1][0] && disk > *(pb - 1)) {
        printf("Movimento inválido. O disco na torre C é maior que o disco no topo da torre B.\n");
        continue;
    }

    // Mover o disco da torre C para a torre B
    *pb = disk;
    *pc = 0;
}

if (a == 6) {
    // Mover de C para A. Remove o elemento do topo de C e insere em A
    // Encontrar o disco no topo da torre C
    while (*pc == 0 && pc > &hanoi[2][0]) {
        pc--;
    }
    int disk = *pc;
    if (disk == 0) {
        printf("Não há discos para mover na torre C.\n");
        continue;
    }

    // Encontrar a primeira posição vazia na torre A de baixo para cima
    pa = &hanoi[0][0];
    while (*pa != 0 && pa < &hanoi[0][4]) {
        pa++;
    }

    // Verificar se o disco é menor que o disco abaixo na torre A ou se a torre A está vazia
    if (pa <= &hanoi[0][4] && (pa == &hanoi[0][0] || disk < *(pa - 1))) {
        // Mover o disco de C para A
        *pc = 0;
        *pa = disk;
    } else {
        printf("Não pode colocar um disco maior em cima de um disco menor.\n");
        continue;
    }
}
    // Opção para desistir
if (a == 7) {
        printf("Você escolheu desistir do jogo. Até a próxima!\n");
        break;
        }
    }

    return 0;
}