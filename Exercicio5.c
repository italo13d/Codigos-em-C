#include <stdio.h>
#include <stdlib.h>
#define X 4
#define Y 4


 /* O programa aloca uma matriz de duas dimensões com 4 dimensões e preenche a matriz com a soma dos índices de
 linha e coluna, imprime a matriz e, desaloca a memória alocada para a matriz*/

int main ()
{
    int **A; int i, j;

/* Aloca as posições na memória para o nosso vetor
 da nossa matriz 4 por 4 basicamente.
 Além disso, é importante testar se o retorno da nossa alocação de memória não é nula,
 pois o nulo é resultado de quando não se consegue alocar eficientemente.*/

 
     A = (int **) malloc ( Y * sizeof(int*));
     if(A == NULL)
     {
        exit(1);
     }
        for( i = 0; i < Y; i++){
            A[i] = (int *) malloc( Y * sizeof(int));
            if(A[i] == NULL)
            {
                exit(1);
            }
        }

/* Passa os valores para as posições das matrizes, onde as linhas recebem os valores
e a coluna recebe o saltar linha até chegar em 4 por 4 nos seus elementos */
    for( i = 0; i < Y; i++){
        for(j = 0; j < X; j++){
            *(*(A + i) + j) = i + j;
        }
        }
        
/*Agora, para conseguir passar seus elementos, devemos fazer uma aritmética de
ponteiros que use os laços de repetição for para preencher nossa matriz*/
    for(i = 0;i < Y; i++) {
        for(j = 0; j < X; j++)
        {
            printf("%d \t", *(*(A + i)+ j));
        }
        printf("\n");
}
/*Além disso, é necessário que desaloquemos as posições ao final também
A memória deve ser desalocada basicamente;*/

    for(i = 0; i < Y; i++)
    {
           free(*(A + i));
    }
    free(A);

    return 0;

}
