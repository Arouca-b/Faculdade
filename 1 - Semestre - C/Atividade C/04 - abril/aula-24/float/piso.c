/*Dadas as medidas de uma sala em metros
(comprimento e largura), bem como o preço do
metro quadrado de carpete, informe o custo
total para forrar o piso da sala*/

#include <stdio.h>

int main(){
    float l, c, preco, n_preco;

    printf("Valor do carpete por metro quadrado: ");
    scanf("%f", &preco);
    printf("Qual o comprimento da sala: ");
    scanf("%f", &c);
    printf("Qual a largura da sala: ");
    scanf("%f", &l);

    n_preco = (c*l) * preco;

    printf("Metros quadrados da sala: %.2fm²\nValor para formar essa área: R$%.2f\n", c*l, n_preco);
}