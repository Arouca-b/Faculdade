//aplicardo desconto de 10% para compras

#include  <stdio.h>

int main(){
    float valor, valor_p;

    printf("Insira o valor do produto: R$");
    scanf("%f", &valor);

    valor_p = valor * 0.9 * (valor>=1000 && valor < 2000) + valor * 0.8 * (valor >= 2000) + valor * (valor < 1000);

    printf("O cliente irá pagar: R$ %.2f\n", valor_p);
    printf("O desconto foi de: R$%.2f\n", valor - valor_p );
}