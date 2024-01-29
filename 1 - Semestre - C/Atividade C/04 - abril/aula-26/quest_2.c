/*Dado um número de três algarismos (abc),
construir outro número de quatro algarismos (abcd)
de acordo com a seguinte regra: d=(a+b+c) mod 10.
Exemplo: 123 vira 1236.*/

#include <stdio.h>

int main(){
    int a, b, c, d, number;

    printf("Insira um número: ");
    scanf("%d", &number);

    a = number/100;
    b = number/10%10;
    c = number%10;
    d = a + b + c;
    number = number * 10 + d; 
    printf("number com 4 algarismo: %d", number);
}