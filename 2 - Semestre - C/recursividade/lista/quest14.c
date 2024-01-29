/*Faça uma função recursiva que permita inverter um número inteiro N.
Ex: 123 – 321*/

#include <stdio.h>
#include <math.h>

int expoente(int a, int b);
int diva(int n);
int invert(int n);


int main(){
    int n = 5420851;
    printf("\n\nINVERTIDO: %d\n\n", invert(n));
}

int expoente(int a, int b){
    if (b == 0){
        return 1;
    }else if (b==1){
        return a;
    }
    return a * expoente(a, b-1);
}

int diva(int n){
    if (n/10 == 0){
        return 0;
    }
    return 1 + diva(n/10);
}

int invert(int n){
    if (n/10 == 0){
        return n;
    }
    return ((n%10) * expoente(10, diva(n)) + invert(n/10));
}