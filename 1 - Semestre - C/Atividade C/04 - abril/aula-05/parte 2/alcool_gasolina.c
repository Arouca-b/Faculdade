#include <stdio.h>

int main(){
    float alc, gas, percentual;

    printf("Insira o valor do Álcool: R$");
    scanf("%f", &alc);
    printf("Insira o valor do Gasolina: R$");
    scanf("%f", &gas);

    percentual = (alc/gas) * 100;

    printf("O percentual é: %.2f%%\n", percentual);
}