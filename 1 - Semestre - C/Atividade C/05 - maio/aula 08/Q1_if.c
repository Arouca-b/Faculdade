/* Uma papelaria, até 100 folhas, a cópia custa R$0.25 e acima de 100 a folha custa R$0.20, Dado o total de cópias, informe o total a ser pago.*/
#include <stdio.h>

int main(){
    int q_folhas;
    float p;

    printf("Insira a quantidade de folhas: ");
    scanf("%d", &q_folhas);

    if (q_folhas<=100)
    {
        p = q_folhas * 0.25;
    }else{
        p = q_folhas * 0.2;
    }
    printf("Quantidade de folhas: %d\n", q_folhas);
    printf("Preço: R$%.2f\n", p);
}