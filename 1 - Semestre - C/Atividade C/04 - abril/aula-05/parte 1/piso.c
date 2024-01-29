#include <stdio.h>

int main(){
    float comp, lar, valor,valor_c ;

    printf("\n\t\tvalor metro² do forro: R$ ");
    scanf("%f", &valor);
    
    printf("\nDigite o comprimento da sala: ");
    scanf("%f", &comp);
    printf("Digite a largura da sala: ");
    scanf("%f", &lar);
    valor_c = valor * (comp*lar);

    printf("valor do forro para a sala R$: %.2f\n", valor_c);
}