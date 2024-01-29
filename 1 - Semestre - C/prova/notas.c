//valores com notas de 100, 50, 10 e 1

#include <stdio.h>

int main(){
    int valor, nota100, nota50, nota10, nota1;

    printf("Insira o valor: ");
    scanf("%d", &valor);
    
    nota100 = valor/100;
    nota50 = (valor%100)/50;
    nota10 = ((valor%100)%50)/10;
    nota1 = valor - nota100*100 - nota50*50 - nota10*10;

    printf("notas de 100: %d\n", nota100);
    printf("notas de 50: %d\n", nota50);
    printf("nota de 10: %d\n", nota10);
    printf("notas de 1: %d\n", nota1);
    return 0;
}