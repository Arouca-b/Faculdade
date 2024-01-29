/*O professor com 2 turmas de 4 alunos cada, fez 3
provas durante um semestre mas só levará em
conta 2 notas mais altas para calcular a média.
Faça um programa que peça as 3 notas de cada
aluno de cada turma, valide-as (0 - 10), e que
mostre como seria a média com as 3 notas, e que
mostre a média com as 2 notas mais altas,
apresentando a nota descartada. Utilizar matriz 3D*/
#include <stdio.h>

int main(){
    char aluno[2][4][100] = {0};
    int q_al = 0, turma = 0;
    float notas[2][4][3] = {0}, soma = 0, maior = 0, maior1 = 0, menor = 0, media[2][4] = {0}, media_m[2][4] = {0};

    for (turma = 0; turma < 2; turma++){
        printf("\n\n\t\tTurma %d\n\n", turma);
        for(q_al = 0; q_al < 4; q_al++){
            printf("Aluno: ");
            scanf(" %[^\n]s%*c", aluno[turma][q_al]);
        }
    }
    for (turma = 0; turma < 2; turma++){
        printf("\n\n\t\tTurma %d\n\n", turma);
        for(q_al = 0; q_al < 4; q_al++){
            soma = maior1 = maior = menor = 0;
            printf("Aluno: %s\n", aluno[turma][q_al]);
            for ( int nota = 0; nota < 3; nota++){
                printf("%dº avaliação: ", nota);
                scanf("%f%*c", &notas[turma][q_al][nota]);
                if (notas[turma][q_al][nota]>=maior){
                    maior1 = maior; 
                    maior = notas[turma][q_al][nota];
                }
                soma+= notas[turma][q_al][nota];
                media_m [turma][q_al] = (maior1 + maior)/2;
                media[turma][q_al] = soma/3;
                menor = soma - (maior+maior1);
            }
            printf("Maiores notas: %.2f, %.2f\n", maior, maior1);
            printf("Média: %.2f\n", media[turma][q_al]);
            printf("Média maiores notas: %.2f\n\n", media_m[turma][q_al]);
        }
    }    
}