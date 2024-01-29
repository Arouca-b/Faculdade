#include <stdio.h>
#define PREST 5
int main(){
    float valor, valor_mes;
    printf("Qual o valor do produto: ");
    scanf("%f", &valor);
    valor_mes = valor/PREST;
    printf("O valor das 5 prestações são: R$%.2f \n\n", valor_mes);
}