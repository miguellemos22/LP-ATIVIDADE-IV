#include <stdio.h>
#include <string.h>


struct Contato {
    char nome[50];
    char telefone[20];
    char email[50];
};


char* buscarTelefonePorNome(const struct Contato contatos[], int tamanho, const char* nome) {
    for (int i = 0; i < tamanho; ++i) {
        if (strcmp(contatos[i].nome, nome) == 0) {
            return contatos[i].telefone;
        }
    }
    return "Contato não encontrado";
}

int main() {
    const int numContatos = 3;
    struct Contato contatos[numContatos];

   
    for (int i = 0; i < numContatos; ++i) {
        printf("Digite o nome do contato %d: ", i + 1);
        scanf("%s", contatos[i].nome);

        printf("Digite o número de telefone do contato %d: ", i + 1);
        scanf("%s", contatos[i].telefone);

        printf("Digite o email do contato %d: ", i + 1);
        scanf("%s", contatos[i].email);

        printf("\n");
    }

    
    char nomeBuscado[50];
    printf("Digite o nome do contato que você deseja buscar: ");
    scanf("%s", nomeBuscado);

    
    char* telefoneEncontrado = buscarTelefonePorNome(contatos, numContatos, nomeBuscado);
    printf("Número de telefone de %s: %s\n", nomeBuscado, telefoneEncontrado);

    return 0;
}