#include <stdio.h>

int main(){
    int num1, num2, soma, sub, mul, div;

    printf("\n\tDigite 2 números: ");
    scanf("%d", &num1);
    scanf("%d", &num2);

    soma = num1 + num2;
    sub = num1 - num2;
    mul = num1 * num2;
    div = num1 / num2;

    printf("\n\t%d + %d = %d\n", num1, num2, soma); 
    printf("\t%d - %d = %d\n", num1, num2, sub);
    printf("\t%d * %d = %d\n", num1, num2, mul);
    printf("\t%d / %d = %d\n", num1, num2, div);
}