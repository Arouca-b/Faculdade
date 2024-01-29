/*
Implemente uma função recursiva soma(n) que calcula o somatório
dos n primeiros números inteiros.
*/

#include <stdio.h>

int somatorio(int n){
    if(n==0)
        return 0;
    if(n==1)
        return 1;
    return n + somatorio(n-1);
}

int main(){
    int n = 5;
    printf("\n\nSOMATÓRIO %d: %d\n\n", n, somatorio(n));
}