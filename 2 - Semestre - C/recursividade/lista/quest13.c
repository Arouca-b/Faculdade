/*
    Escreva uma função recursiva que calcule o número de grupos
    distintos com k pessoas que podem ser formados a partir de um
    conjunto de n pessoas.
    A definição abaixo da função Comb(n,k) define as regras:
*/

#include <stdio.h>
#include <stdlib.h>

int comb(int n, int k){
    if(k==1)
        return n;
    if(k==n)
        return 1;
    return comb(n-1, k-1) + comb(n-1, k);
}

int main(){
    int n = 3;
    int k = 2;

    printf("GRUPOS QUE PODEM SER FORMADOS %d pessoas - %d Pessoas/grupo: %d\n\n", n, k, comb(n,k));
}