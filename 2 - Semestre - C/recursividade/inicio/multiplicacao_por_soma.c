/*Escreva uma função recursiva para multiplicar dois números.
Lembre-se que multiplicar 4 por 5 é somar 4 com ele mesmo 5
vezes ou somar 5 com ele mesmo 4 vezes.*/

#include <stdio.h>
#include <stdlib.h>

int mul_soma(int a, int b){
    if (b == 0){
        return 0;
    }else{
        if(b-1>0){
            return a + mul_soma(a, b-1);
        }
        return a;
    }
}

int main(){
    printf("\n%d\n\n", mul_soma(4,10));
}