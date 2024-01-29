/*Crie um registro para armazenar as seguintes
informações de um aluno: sua matrícula, seu
nome, suas 3 notas e média. Receba estas
informações, calcule a média e imprima tudo com a
informação se o aluno passou, se está na final ou
foi reprovado*/
#include <stdio.h>
#include <stdlib.h>

struct aluno{
    int matricula;
    char nome[100];
    float notas[3], media;
};

int main(void){
    struct aluno;
    float soma;

    printf("Nome do aluno: ");
    scanf("%[^\n]s%*c", aluno1.nome);
    printf("Num de matricula: ");
    scanf("%d%*c", &aluno1.matricula);
    for(int i = 0; i < 3; i++){
        do{
            printf("Nota %d: ", i+1);
            scanf("%f%*c", &aluno1.notas[i]);
        } while (aluno1.notas[i] > 10 || aluno1.notas[i] < 0);
        soma+=aluno1.notas[i];
    }
    aluno1.media = soma/3;
    system("clear||cls");
    printf("Nome: %s\n", aluno1.nome);
    printf("Matricula: %d\n", aluno1.matricula);
    for(int i = 0; i < 3; i++){
        printf("%dº Nota: %.2f\n", i+1, aluno1.notas[i]);
    }
    printf("Media: %.2f\n", aluno1.media);
    printf("Situação: ");
    if(aluno1.media >= 7){
        printf("Aprovado\n");
    } else if(aluno1.media >= 4){
        printf("Final\n");
    } else {
        printf("Reprovado\n");
    }
}