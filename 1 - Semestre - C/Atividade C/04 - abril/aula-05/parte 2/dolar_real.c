#include <stdio.h>

int main(){
    float dollar, q, conv;
    printf("Insira a cotação do dolar hoje: US$1 = R$");
    scanf("%f", &dollar);
    printf("Insira a quantidade de dolares que você tem: ");
    scanf("%f", &q);
    conv = dollar * q;
    printf("\nvocê tem R$%.2f em dolar!\n", conv);
}