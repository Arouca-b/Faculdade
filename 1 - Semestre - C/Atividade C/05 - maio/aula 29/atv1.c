/*Um programa que lê dez números e os
imprime em ordem inversa. Para isso, é
necessário armazenar os 10 números para
poder imprimi-los de trás para frente. Seria
possível utilizar 10 variáveis distintas, mas a
solução com vetor é bem mais elegante. Mais
ainda, se fossem 10.000 números, e não 10,
ficaria impraticável usar variáveis distintas*/
#include <stdio.h>

int main(){
    int num[10], cont;
    printf("insira os valores para armazenar: ");
    for(cont = 0; cont<10; cont++){
        scanf("%d", &num[cont]);
    }
    printf("\n");
    for(cont = 9;cont>=0; --cont){
        printf("%d ", num[cont]);
    }
    printf("\n");
}