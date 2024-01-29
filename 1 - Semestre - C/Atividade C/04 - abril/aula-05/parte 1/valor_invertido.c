#include <stdio.h>

int main(){
    int a,b,invert;
    printf("Insira um valor para a: ");
    scanf("%d", &a);
    printf("Insira um valor para b: ");
    scanf("%d", &b);
    
    invert = a;
    a = b;
    b = invert;

    printf("\no valor para a é: %d\n", a);
    printf("o valor para b é: %d\n", b);
}