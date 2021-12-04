#include <stdio.h>
#include <stdlib.h>

#define TAM_DESC 50
#define MAX_PROD 100

typedef struct {
    int codigo;
    char descricao[TAM_DESC + 1];
    double preco;
} Produto;

typedef struct {
    Produto *produto;
    int quantidadeProdutos;
    double precoTotal;
} Carrinho;


void mostraCarrinho(Carrinho *carrinho) {
    int i;
    printf("\n=== CARRINHO DE COMPRAS ===\n");
    for (i = 0; i < carrinho->quantidadeProdutos; i++) {
        printf("%d - %s - R$%.2lf\n", carrinho->produto[i].codigo, carrinho->produto[i].descricao, carrinho->produto[i].preco);
    }
    printf("Total R$%.2lf\n", carrinho->precoTotal);

}

int main() {
    char opc;
    int x;
    Carrinho *carrinho = malloc(sizeof(Carrinho));
    carrinho->produto = malloc(sizeof(Produto) * MAX_PROD);
    carrinho->quantidadeProdutos = 0;

    do {
        x = carrinho->quantidadeProdutos;
        printf("\n== CADASTRO DE PRODUTOS ==\n");
        printf("Digite o codigo: ");
        scanf("%d", &carrinho->produto[x].codigo);

        printf("Digite a descricao: ");
        scanf(" %[^\n]s", carrinho->produto[x].descricao);

        printf("Digite o preco: R$");
        scanf("%lf", &carrinho->produto[x].preco);

        printf("\nProduto adicionado ao carrinho!\n");

        carrinho->precoTotal += carrinho->produto[x].preco;
        carrinho->quantidadeProdutos++;

        if (x + 1 == MAX_PROD) {
            printf("Limite de produtos atingido.\n");
            break;
        }

        printf("\nDeseja adicionar um novo produto? (s/n)\n=> ");
        scanf(" %c", &opc);

    } while (opc != 'n' && opc != 'N');


    mostraCarrinho(carrinho);

}
