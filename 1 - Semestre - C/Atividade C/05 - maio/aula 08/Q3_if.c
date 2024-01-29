/*Receber um número do teclado e informar se ele é
par ou impar com todos os 3 condicionais
– (Num mod 2) em portugol é equivalente em C a
(num % 2)*/

#include <stdio.h>

int main(){
    int num;

    printf("Insira um número inteiro: ");
    scanf("%d", &num);

    if(num%2 == 0){
        printf("O numero é IMPAR OU PAR: PAR!\n\n");
    }else{
        printf("O numero é IMPAR OU PAR: IMPAR!\n\n");
    }
}