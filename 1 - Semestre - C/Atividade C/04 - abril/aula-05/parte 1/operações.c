#include <stdio.h>

int main(){
    float num1,num2, mul, som, div, sub;

    printf("\n\nDigite 2 números para realizar operações matemáticas: ");
    scanf("%f", &num1);
    scanf("\t\t%f", &num2);

    mul = num1 * num2;
    div = num1/num2;
    som = num1 + num2;
    sub = num1 - num2;

    printf("\t\t%.2f + %.2f = %.2f\n\n", num1, num2, som);
    printf("\t\t%.2f - %.2f = %.2f\n\n", num1, num2, sub);
    printf("\t\t%.2f / %.2f = %.2f\n\n", num1, num2, div);
    printf("\t\t%.2f * %.2f = %.2f\n\n", num1, num2, mul);
}