/*Criar um programa que imprima na tela os
números de 0 a N em ordem crescente e
decrescente. Usar os 3 laços...*/

#include <stdio.h>

int main(){
    int num;

    printf("Insira um valor positivo: ");
    scanf("%d", &num);
    
    while(num<=0){
        printf("\n**número não atende os requisitos**\n insira um valor positivo: ");
        scanf("%d", &num);
    }

    printf("\nForma crescente:   ");
    for(int cont = 0; cont <= num; cont++){
        printf("%d ", cont);
    }

    printf("\nForma decrescente: ");
    for(int cont = 0; num >= cont; num--){
        printf("%d ", num);
    }

    printf("\n\n");
}