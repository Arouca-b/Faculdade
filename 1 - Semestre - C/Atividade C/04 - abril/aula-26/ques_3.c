#include <stdio.h>

int main(){
    float valor, horas;

    printf("Insira as horas no estacionamento: ");
    scanf("%f", &horas);

    int t_base = (int) horas/4;
    int t_extra = horas - t_base * 4;

    float v_base = t_base * 10;
    float v_extra = t_extra * 5;

    valor = v_base + v_extra; 

    printf("Valor a pagar é: %.2f", valor);
}