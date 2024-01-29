/*Nível 1: Recursão Simples

    Crie uma função recursiva para calcular o fatorial de um número inteiro.
    Implemente uma função recursiva para calcular a soma dos primeiros N números naturais.
    Escreva uma função recursiva para calcular a potência de um número inteiro (por exemplo, x^y).*/

#include <stdio.h>
#include <stdlib.h>
#include "arouca.h"

int fatorial(int a){
    if (a == 1){
        return a;
    }
    return a * fatorial(a-1);
}

int soma_p(int a){
    if (a == 1){
        return a;
    }
    return a + soma_p(a-1);
}

int pot(int a, int b){
    if (b == 1){
        return a;
    }
    return a * pot(a, b-1);
}

int main(){
    int a, b;

    printf("Insira um valor A: ");
    scanf("%d%*c", &a);
    printf("Insira um valor B: ");
    scanf("%d%*c", &b);
    printf("Fatorial de %d: %d\n", a, fatorial(a));
    printf("Soma dos %d primeiros numeros: %d\n", a, soma_p(a));
    printf("Potência %d ^ %d: %d\n\n", a, b, pot(a, b));
}
