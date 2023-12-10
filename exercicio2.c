#include <stdio.h>
#include <string.h>

o
struct Aluno {
    char nome[50];
    char dataNascimento[20];
    double nota1;
    double nota2;
    double media;
};


double calcularMedia(const struct Aluno* aluno) {
    return (aluno->nota1 + aluno->nota2) / 2.0;
}


int verificarAprovacao(const struct Aluno* aluno) {
    return aluno->media >= 7.0;
}

int main() {
    const int numAlunos = 5;
    struct Aluno alunos[numAlunos];

      for (int i = 0; i < numAlunos; ++i) {
        printf("Digite o nome do aluno %d: ", i + 1);
        fgets(alunos[i].nome, sizeof(alunos[i].nome), stdin);
        alunos[i].nome[strcspn(alunos[i].nome, "\n")] = '\0'; 

        printf("Digite a data de nascimento do aluno %d: ", i + 1);
        fgets(alunos[i].dataNascimento, sizeof(alunos[i].dataNascimento), stdin);
        alunos[i].dataNascimento[strcspn(alunos[i].dataNascimento, "\n")] = '\0'; 
        printf("Digite a nota 1 do aluno %d: ", i + 1);
        scanf("%lf", &alunos[i].nota1);

        printf("Digite a nota 2 do aluno %d: ", i + 1);
        scanf("%lf", &alunos[i].nota2);

        // Calcular a média
        alunos[i].media = calcularMedia(&alunos[i]);

        printf("\n");
    }

   
        printf("Aluno: %s\n", alunos[i].nome);
        printf("Média: %.2f\n", alunos[i].media);

        if (verificarAprovacao(&alunos[i])) {
            printf("Situação: Aprovado\n");
        } else {
            printf("Situação: Reprovado\n");
        }

        printf("\n");
    }

    return 0;
}