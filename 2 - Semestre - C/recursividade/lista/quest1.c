/*Faça função recursiva que determine quantas vezes um dígito K ocorre
em um número natural N.
Por exemplo, o dígito 2 ocorre 3 vezes em 762021192.*/

#include <stdio.h>

int conta_k(int n, int k){
    if (n/10 == 0){
        if (n == k){
            return 1;
        }
        return 0;
    }
    if (n%10 == k){
        printf("%d\n", n);
        return 1 + conta_k(n/10, k);
    }
    return conta_k(n/10, k);
}

int main(){
    int n = 762021192;
    int k = 2;
    printf("\n\n%d aparece %d  no número %d\n\n\n", k, conta_k(n, k), n);
}