#include <stdio.h>

int main(){
    float altura, peso, imc;

    printf("\nDigite sua altura(m): ");
    scanf("%f", &altura);
    printf("Digite seu peso(kg): ");
    scanf("%f", &peso);
    
    imc = peso/(altura*altura);

    printf("\nSeu IMC é: %.2f\n\n", imc);
}