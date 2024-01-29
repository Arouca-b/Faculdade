/* Uma papelaria, até 100 folhas, a cópia custa R$0.25 e acima de 100 a folha custa R$0.20, Dado o total de cópias, informe o total a ser pago.*/

#include <stdio.h>

int main(){
    int q_folhas;
    float p;

    printf("Insira a quantidade de folhas: ");
    scanf("%d", &q_folhas);

    switch(q_folhas){
        case 0 ... 100 : p = q_folhas * .25;
            break;
        default: p = q_folhas * .20;
            break;
    }
    printf("Quantidade de folhas: %d\n", q_folhas);
    printf("Valor: %.2f\n", p);
}