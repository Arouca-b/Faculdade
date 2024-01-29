/*Escreva um programa em C que produza a seguinte
saída na tela (nomes alinhados a direita ecvírgula
embaixo de vírgula), utilizando só formatação:
ALUNO(A)       NOTA
============= =====
   ALECSANDER   9,0
  ALEXSSANDRO   9,93
        BRENO  10,0
        EMYLE   8,5
    VALENTINA   8,0
      MICHAEL   8,45
         RYAN   9,99*/

#include <stdio.h>
#define MAX 7

int main(){
    char nome[MAX][30] = {"ALECSANDER","ALEXSSANDRO","BRENO", "EMYLE", "VALENTINA","MICHAEL","RYAN"};
    float nota[7] = {9.0, 9.93, 10.0, 8.5, 8.0, 8.45, 9.99};

    printf("ALUNO(A)\tNOTA\n");
    printf("=============\t=====\n");
    for(int i = 0; i<MAX; i++){
        printf("%12s \t", nome[i]);

        if (nota[i] == 10.0 || nota[i] == 9.0 || nota[i] == 8.5 || nota[i] == 8.0)
        {
            printf("%4.1f\n", nota[i]);
        } else{
            printf("%5.2f\n", nota[i]); 
        }
    }
}
