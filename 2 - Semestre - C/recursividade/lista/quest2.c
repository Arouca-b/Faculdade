/*
    O máximo divisor comum (MDC) de dois números inteiros x e y pode
    ser calculado usando-se uma definição recursiva:
    MDC(x, y) = MDC(x − y, y), se x > y
    MDC(x,y) = MDC(y,x)
    MDC(x,x) = x
    Implemente a função.
*/

#include <stdio.h>

int MDC(int x, int y){
    if (x == y){
        return x;
    }
    if (x > y){
        return MDC(x-y, y);
    }
    return MDC(y,x);
}

int main(){
    int x = 3;
    int y = 10;
    printf("\n\nMENOR DIVISOR COMUM ENTRE %d e %d : %d\n\n", x, y, MDC(x, y));
}