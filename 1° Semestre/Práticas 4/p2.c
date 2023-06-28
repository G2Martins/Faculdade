//Faça um programa em C que leia as notas de 10 alunos, calcule a média da turma e contabilize quantos alunos estão com a nota acima da média.
#include <stdio.h>

int main() {

    struct aluno_t{
    float nota;
    float soma;
    };

    float media = 0;
    int alunos_acima_media = 0;
    
    struct aluno_t alunos[10];

    for (int i = 0; i < 10; i++) {
        printf("Digite a nota do %d° aluno: ", i + 1);
        scanf("%f", &alunos[i].nota);
        alunos[i].soma += alunos[i].nota;
        media += alunos[i].nota;
    }

    media /= 10; // Calcula a média dividindo pelo número de alunos

    for (int i = 0; i < 10; i++) {
        if (alunos[i].nota > media) {
            alunos_acima_media++;
        }
    }

    printf("A média da turma é: %.2f\n", media);
    printf("Quantidade de alunos com nota acima da média: %d\n", alunos_acima_media);

    return 0;
}
