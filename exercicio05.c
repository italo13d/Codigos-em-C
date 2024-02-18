#include <stdio.h>
#include <stdlib.h>
#define Y 4
#define X 4

int main() {


    int **A;int i, j;
    A = (int **) malloc (Y * sizeof(int*));
    for(i = 0; i < Y; i++)
    A[i] = (int *) malloc( X * sizeof(int));
    

    for(i = 0;i < Y; i++)
        for(j = 0; j < X; j++)
            A[i][j] = i + j;
    
    for(i = 0; i < Y; i++){
        for(j = 0; j < X; j++)
            printf("%d \t", A[i][j]);
        printf("\n");
    }


    for( i = 0; i < Y; i++)
        free(A[i]);
    free(A);

    return 0;
}