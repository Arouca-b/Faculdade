/*
Pode-se calcular o resto da divisão, MOD, de x por y, dois números
inteiros positivos, usando-se a seguinte definição:
MOD(x,y) = MOD(x - y, y) se x > y
MOD(x,y) = x se x < y
MOD(x,y) = 0 se x = y
Implemente
*/

#include <stdio.h>

int MOD(int x, int y){
    if(x==y)
        return 0;
    if(x < y)
        return x;
    return MOD(x-y, y);
}
int main(){
    int x = 3;
    int y = 10;
    printf("\n\nRESTO DA DIVISÃO ENTRE %d e %d : %d\n\n", y, x, MOD(y, x));
}