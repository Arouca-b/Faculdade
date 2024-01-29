/*Ler temperatura em graus Celsius e apresentá-la
convertida em graus Fahrenheit. A fórmula de
conversão é: (F=(9*C+160)/5), sendo F a
temperatura em Fahrenheit e C em Celsius*/
#include <stdio.h>

int main(){
    float f, c;
    
    printf("Insira os graus em Celsius: ");
    scanf("%f", &c);

    f = (9*c+160)/5;

    printf("%.1f°C em Fahrenheit é: %.1fF\n", c, f);
}