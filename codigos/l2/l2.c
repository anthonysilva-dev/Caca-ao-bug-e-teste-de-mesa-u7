#include <stdio.h>

typedef struct {
    char nome[30];
    float n1, n2, n3;
} Aluno;

int main(void) {
    Aluno alunos[3] = {
        {"Pedro", 7.0f, 8.0f, 7.5f},
        {"Ana", 9.0f, 8.5f, 9.5f},
        {"Lucas", 6.0f, 7.5f, 6.0f}
    };
    int melhor = 0;
    float maior = (alunos[0].n1 + alunos[0].n2 + alunos[0].n3) / 3.0f;

    for (int i = 1; i < 3; i++) {
        float media = (alunos[i].n1 + alunos[i].n2 + alunos[i].n3) / 3.0f;
        if (media > maior) {
            maior = media;
            melhor = i;
        }
    }

    printf("Maior media: %s (%.2f)\n", alunos[melhor].nome, maior);

    return 0;
}
