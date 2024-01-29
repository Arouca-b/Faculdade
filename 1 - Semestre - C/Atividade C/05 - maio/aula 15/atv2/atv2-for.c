#include <stdio.h>

int main(){
    int num, soma, resto, a = 11, div = 1;

    printf("Insira um valor positivo: ");
    scanf("%d", &num);
    
    while(num<=0){
        printf("\n**número não atende os requisitos**\n insira um valor positivo: ");
        scanf("%d", &num);
    }
    // descobrir quantos digitos tem o numero
    for (int b = num; a > 10 ;)
    {
        a = b/10;
        b = b/10;
        div = div * 10;
    }
    // somar os digitos
    for(; num > 0; div = div/10){
        resto = num/div;
        soma = soma + resto;
        printf("+ %d ", resto);
        num = num%div;
    }
    printf("= %d\n", soma);
}