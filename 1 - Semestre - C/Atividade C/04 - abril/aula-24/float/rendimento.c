/*Faça um programa que receba um valor que foi
depositado e exiba o valor com rendimento
após um mês. Considere fixo o juro da
poupança em 0,70% a. m.*/
#include <stdio.h>
#define juros 0.007
int main(){
    float dep, rend;

    printf("Insira o valor depositado: R$");
    scanf("%f", &dep);
    rend = (dep * juros) + dep;
    printf("Rendimento do saldo em 1 mês: %.2f\nNovo saldo: %.2f\n", dep*juros, rend);
}