/*Ler as 4 notas de um aluno e imprimir sua
média final com 1 casa decimal*/
#include <stdio.h>

int main(){
    float n1, n2, n3, n4, media;

    printf("Digite as 4 notas desse aluno: ");
    scanf("%f %f %f %f", &n1, &n2, &n3, &n4);

    media = (n1 + n2 + n3 + n4)/4;

    printf("A média do aluno foi: %.1f /n", media);
}