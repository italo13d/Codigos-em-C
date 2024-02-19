#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <stdlib.h>

typedef struct {
    char nome[100];
    int x;
    int y;
}   Cidade;

int main ()
{
    int N;
    setlocale(LC_ALL, "pt_BR.UTF-8");
    printf("Digite o número de cidades: \n");
    scanf("%d", &N);

    Cidade cidades[N];

    for(int i = 0; i<N;i++)
    {
        printf("Digite o nome da cidade %d: \n", i+1);
        scanf("%s", &cidades[i].nome);
        
        printf("Digite a coordenada X da cidade %d: \n", i+1);
        scanf("%d", &cidades[i].x);

        printf("Digite a coordenada Y da cidade %d: \n", i+1);
        scanf("%d", &cidades[i].y);
    }

    // Cria a matriz de distâncias
    double distancias[N][N];

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            int dx = cidades[i].x - cidades[j].x;
            int dy = cidades[i].y - cidades[j].y;
            distancias[i][j] = sqrt(dx*dx + dy*dy);
        }
    }
    // Exibe a matriz de distâncias
    for(int i = 0; i < N; i++){
        for(int j = 0;j< N;j++){
        printf("%f ", distancias[i][j]);
        }
        printf("\n");
}
    
    return 0;
}