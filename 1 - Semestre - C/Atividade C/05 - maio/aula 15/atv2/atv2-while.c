#include <stdio.h>

int main(){
    int num, soma, resto, a = 101, div = 1;

    printf("Insira um valor positivo: ");
    scanf("%d", &num);
    
    while(num<=0){
        printf("\n**número não atende os requisitos**\n insira um valor positivo: ");
        scanf("%d", &num);
    }
    // descobrir quantos digitos tem o numero
    while(a>100){
        a = num/div;
        div = div * 10;
    }
    
    // somar os digitos
    while(num > 0){
        resto = num/div;
        soma = soma + resto;
        printf("+ %d ", resto);
        num = num%div;
        div = div/10;
    }
    printf("= %d\n", soma);
}