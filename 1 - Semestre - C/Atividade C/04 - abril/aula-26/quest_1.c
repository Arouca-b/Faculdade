/*1. Fazer um programa em C que lê o preço de um
produto e inflaciona esse preço em 10% se ele for
menor que 100 e em 20% se ele for maior ou igual a
100.*/

#include <stdio.h>

int main(){
    float preco, inf;
    printf("Insira o valor do produto: R$");
    scanf("%f", &preco);

    inf = 1.1 + 0.1 * (preco>=100);
    inf = inf * preco;
    printf("Novo valor do produto: R$%.2f\n", inf);
    printf("Inflação de: R$%.2f\n", inf - preco);
}