/*O índice de massa corpórea (IMC) de uma pessoa é
igual ao seu peso (em quilogramas) dividido pelo
quadradro de sua altura (em metros). Dados o peso e
a altura de uma pessoa, informe o valor do seu IMC*/
#include <stdio.h>
 int main(){
    float imc, altura, peso;

    printf("Insira seu peso: ");
    scanf("%f", &peso);
    printf("Insira sua altura: ");
    scanf("%f", &altura);

    imc = peso/(altura*altura);

    printf("Seu IMC é: %.2f \n", imc);
 } 