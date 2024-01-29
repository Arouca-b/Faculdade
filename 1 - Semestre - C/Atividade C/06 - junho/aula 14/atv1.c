/*Exercício: Faça um programa em C que leia o
nome dos alunos de uma turma de 5 alunos,
as suas 3 notas na ordem da execução das
provas, e vá informando a média parcial de
cada aluno, na medida que cada nota é lida.
No final imprima o número, o nomes, as notas
e média de cada aluno na forma de tabela
com rótulos*/
#include <stdio.h>
#include <stdlib.h>
int main(){
    char alunos[5][50];
    int q_al, indice= 0, avaliacao=0;
    float media[5]={0}, notas[5][3] = {0}, soma[5]={0}, aux;

    for (int avaliacao = 0; avaliacao < 3; avaliacao++){
        for ( q_al = 0;q_al<5; q_al++){
            while(indice < 5){
                printf("Nome do Aluno %d : ",indice + 1);
                scanf(" %[^\n]s", alunos[indice]);
                indice++;
                printf("\n");
            }
            printf("\nAluno: %s\n", alunos[q_al]);
            printf("Nota da %dº Avaliação: ", avaliacao+1);
            scanf("%f", &notas[q_al][avaliacao]);
            while (notas[q_al][avaliacao] < 0 || notas[q_al][avaliacao] > 10)
            {
                system("clear||cls");
                printf("\t\t\tValor Inválido\n\n");
                printf("\nAluno: %s\n", alunos[q_al]);
                printf("Nota da %dº Avaliação: ", avaliacao+1);
                scanf("%f", &notas[q_al][avaliacao]);
            }
            soma[q_al] += notas[q_al][avaliacao];
            media[q_al] = soma[q_al] / 3;
            printf("Média parcial: %.2f\n\n", media[q_al]);
        }
    }
        printf("\n NUM |    NOME DO ALUNO   |  NOTA 1 | NOTA 2 | NOTA 3 |  MÉDIA | "
               "\n ===================================================================\n");
    for (q_al = 0; q_al < 5; q_al++) {
        printf("|  %1d  ", q_al);
        printf("|\t\t%s\t|", alunos[q_al]);
        for (avaliacao = 0; avaliacao < 3; avaliacao++) {
            printf("   %3.1f   |", notas[q_al][avaliacao]);
        }
        printf("   %4.1f   |\n", media[q_al]);
    }
    printf("\n\n\n");

    return 0;
}