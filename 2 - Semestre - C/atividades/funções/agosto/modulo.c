#include <stdio.h>
#include <stdlib.h>
int absoluto(int a){
    if (a < 0){
        return a * -1;
    }
    return a;
}

void main(){
    int num;

    printf("Insira o valor de um número: ");
    scanf("%d%*c", &num);

    printf("\nAbsoluto do número é: %d\n\n\n",absoluto(num));
}