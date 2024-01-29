/*Receber um número do teclado e informar se ele é
par ou impar com todos os 3 condicionais
– (Num mod 2) em portugol é equivalente em C a
(num % 2)*/

#include <stdio.h>

int main(){
    int num;

    printf("Insira um número: ");
    scanf("%d", &num);
    (num%2 == 0) ? printf("O número é IMPAR ou PAR: PAR!!\n\n") : printf("O número é IMPAR ou PAR: IMPAR!!\n\n");
}