/*Receber 4 notas de um aluno, calcular média e
informar situação: passou se 7 ou mais, abaixo de 3
está reprovado sem direito a final com todos os 3
condicionais*/

#include <stdio.h>

int main(){
    float media, nota1, nota2, nota3, nota4;

    printf("Insira a primeira nota do aluno: ");
    scanf("%f", &nota1);
    printf("Insira a segunda nota do aluno: ");
    scanf("%f", &nota2);
    printf("Insira a terceira nota do aluno: ");
    scanf("%f", &nota3);
    printf("Insira a quarta nota do aluno: ");   
    scanf("%f", &nota4);

    media = (nota1 + nota2 + nota3 + nota4)/4;
    printf("\n\t\tMédia: %.1f", media);
    if(media>=7){
        printf("\n\t*******APROVADO*******\n");
    }else if (media>=3){
        printf("\n\t*******FINAL*******\n");
    }else{
        printf("\n\t*******REPROVADO*******\n");
        printf("OBS: Te esperamos novamente no próximo semestre\n\n");
    }    
}