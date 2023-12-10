#include <stdio.h>
#include <stdlib.h>


struct Produto {
    char nome[50];
    float preco;
    int quantidadeEstoque;
};


float calcularValorTotal(const struct Produto* produto) {
    return produto->preco * produto->quantidadeEstoque;
}


void realizarCompra(struct Produto* produto, int quantidadeComprada) {
    if (quantidadeComprada > 0) {
        produto->quantidadeEstoque += quantidadeComprada;
        printf("Compra realizada com sucesso. Quantidade em estoque atualizada: %d\n", produto->quantidadeEstoque);
    } else {
        printf("Quantidade inválida para compra.\n");
    }
}


void consultarEstoque(const struct Produto* produto) {
    printf("Nome do produto: %s\n", produto->nome);
    printf("Quantidade em estoque: %d\n", produto->quantidadeEstoque);
    printf("Preço por unidade: R$ %.2f\n", produto->preco);
    printf("Valor total em estoque: R$ %.2f\n", calcularValorTotal(produto));
}

int main() {
    struct Produto meuProduto = {"Produto A", 10.50, 20};
    int opcao, quantidadeCompra;

    do {
       
        printf("\nMenu:\n");
        printf("1 - Realizar uma compra\n");
        printf("2 - Consultar estoque\n");
        printf("3 - Sair do programa\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                
                printf("Digite a quantidade a ser comprada: ");
                scanf("%d", &quantidadeCompra);
                realizarCompra(&meuProduto, quantidadeCompra);
                break;

            case 2:
                
                consultarEstoque(&meuProduto);
                break;

            case 3:
                
                printf("Saindo do programa.\n");
                break;

            default:
                
                printf("Opção inválida. Tente novamente.\n");
        }

    } while (opcao != 3);

    return 0;
}