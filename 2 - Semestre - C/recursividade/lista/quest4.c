/*
    Os números tetranacci iniciam com quatro termos pré-determinados e a
partir daí todos os demais números são obtidos pela soma dos quatro
números anteriores.
Os primeiros números tetranacci são: 0, 0, 0, 1, 1, 2, 4, 8, 15, 29, 56, 108,

208... Faça uma função recursiva que receba um número N e retorne o N-
ésimo termo da sequência de tetranacci.
*/

#include <stdio.h>

int tetra(int n){
    if(n==0||n==1||n==2)
        return 0;
    if(n==3)
        return 1;
    return tetra(n-4) + tetra(n-3) + tetra(n-2) + tetra(n-1);
}

int main(){
    int n = 10;
    printf("\n\n%d-ésimo termo da sequência de tetranacci: %d\n\n", n, tetra(n));
}