#include <stdio.h>
#include <stdlib.h>

float menor(float a, float b, float c){
    float menor = 0;

    if ((a<=b) && (a<=c)) return a;
    if ((b<=a) && (b<=c)) return b;
    return c;
}

int main(){
    float num, num2, num3;

    printf("Insira o valor de 3 números: ");
    scanf("%f%*c", &num);
    scanf("%f%*c", &num2);
    scanf("%f%*c", &num3);

    printf("O menor é: %.2f\n\n", menor(num, num2, num3));
}