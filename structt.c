#include <stdio.h>
#include <locale.h>

struct Produto {
   int codigo;
   char nome[50];
   int quantidade;
   float preco;
};

int main ()

{
    setlocale(LC_ALL,"pt_BR.UTF-8");
    int N; float maior = 0;

    printf("Digite o número de produtos: ");
    scanf("%d", &N);

    struct Produto produtos[N];

    for(int i = 0; i < N; i++)
    {
        printf("Digite o código do %d: ", i+1);
        scanf("%d", &produtos[i].codigo);

        printf("Digite o nome do produto %d: ", i+1);
        scanf("%s", produtos[i].nome);

        printf("Digite a quantidade %d: ", i+1);
        scanf("%d", &produtos[i].quantidade);

        printf("Digite o preço do produto %d: ", i+1);
        scanf("%f", &produtos[i].preco);
    }

    // Agora, os produtos[] contém as informações dos N produtos que foram solicitados pelo usuário;

    for(int i = 0; i < N; i++)
    {
        if(produtos[i].preco > maior)
        maior = produtos[i].preco;
    }
    printf("%.2f", maior);
    return 0;
}