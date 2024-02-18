#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#define X 5

int main ()
{
    setlocale(LC_ALL, "pt_br.UTF-8");
    int A[X] = {1,2,3,55,0};
    printf("O valor de memória é: %p e os valores são:  %d %d %d %d %d", (void*)A, A[0], A[1], A[2],A[3], A[4]);

}