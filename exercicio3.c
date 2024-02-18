#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main ()
{
    int x, y, *p;
    setlocale(LC_ALL,"pt_BR.UTF-8");
    y = 0;
    printf("Esses são os valores de x, y e valor de p e endereço de p respectivamente: %d %d %d\n", x, y, p);
    p = &y;
    printf("Esse é o valor do endereço de memória de p %d\n" ,*p);
    x = *p;
    printf("Esse é o x recebendo o valor do ponteiro %d\n", x);
    x = 4;
    printf("Essa é a reatribuição de x: %d\n", x);
    (*p)++;
    printf("Esse é o valor e o endereço de memória de p: %d %d\n",p, *p);
    --x;
    printf("Esse é o valor do decremento de x: %d\n", x);
    (*p) += x;
    printf("Esse é o valor da soma do valor do ponteiro (*p) com x: %d\n", *p);
    return 0;
}