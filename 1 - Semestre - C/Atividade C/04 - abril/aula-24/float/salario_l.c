/*Calcule o salário líquido de um profissional,
informando valor da hora trabalhada, números de
horas e o % de desconto de INSS*/

#include <stdio.h>

int main(){
    float v_hora, q_hora, inss, s_liquido;

    printf("Insira o valor da hora de trabalho: ");
    scanf("%f", &v_hora);
    printf("Insira a quantidade de horas trabalhadas: ");
    scanf("%f", &q_hora);
    printf("Insira a porcentagem de desconto INSS: ");
    scanf("%f", &inss);

    s_liquido = v_hora * q_hora - (inss * (v_hora * q_hora))/100;

    printf("\nO salário liquido do funcionário é: %.2f\nDesconto de: R$%.2f\n", s_liquido, (inss * (v_hora * q_hora))/100);
}