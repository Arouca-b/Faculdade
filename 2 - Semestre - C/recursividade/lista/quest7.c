/*
Defina a função prim_alg que recebe como argumento um número
natural e devolve o primeiro algarismo (o mais significativo) na
representação decimal de n.
Exemplo: prim_alg(832) = 8;
Prim_alg(3452)=3;
Prim_alg(6) = 6
*/

#include <stdio.h>

int prim_alg(int n){
    if(n/10 == 0)
        return n;
    return prim_alg(n/10);
}

int main(){
    int n = 600;
    printf("\n\nPRIMEIRO ALGARISDO DE %d: %d\n\n", n, prim_alg(n));
}