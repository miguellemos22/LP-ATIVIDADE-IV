#include <stdio.h>
#include <string.h>


struct Funcionario {
    char nome[50];
    char cargo[50];
    int salarioemcentavos; 
};


int calcularMediaSalarialPorCargo(struct Funcionario funcionarios[], int numFuncionarios, char* cargoDesejado) {
    int somaSalarios = 0;
    int contador = 0;

    for (int i = 0; i < numFuncionarios; ++i) {
        if (strcmp(funcionarios[i].cargo, cargoDesejado) == 0) {
            somaSalarios += funcionarios[i].salario_em_centavos;
            contador++;
        }
    }

    return (contador > 0) ? (somaSalarios / contador) : 0;
}

int main() {
    int numFuncionarios = 5;
    struct Funcionario funcionarios[numFuncionarios];

    for (int i = 0; i < numFuncionarios; ++i) {
        printf("Digite o nome do funcionário %d: ", i + 1);
        fgets(funcionarios[i].nome, sizeof(funcionarios[i].nome), stdin);
        funcionarios[i].nome[strcspn(funcionarios[i].nome, "\n")] = '\0';  

        printf("Digite o cargo do funcionário %d: ", i + 1);
        fgets(funcionarios[i].cargo, sizeof(funcionarios[i].cargo), stdin);
        funcionarios[i].cargo[strcspn(funcionarios[i].cargo, "\n")] = '\0';  

        printf("Digite o salário do funcionário %d em centavos: ", i + 1);
        scanf("%d", &funcionarios[i].salario_em_centavos);

        printf("\n");
    }

  
    char cargoDesejado[] = "Programador";
    int mediaSalarial = calcularMediaSalarialPorCargo(funcionarios, numFuncionarios, cargoDesejado);

    printf("Média salarial dos programadores: R$ %d.%02d\n", mediaSalarial / 100, mediaSalarial % 100);

    return 0;
}