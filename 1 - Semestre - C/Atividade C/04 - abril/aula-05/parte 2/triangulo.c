#include <stdio.h>

int main(){
    float a, b, c;

    printf("Digite o primeiro valor: ");
    scanf("%f", &a);
    printf("Digite o segunda valor: ");
    scanf("%f", &b);
    printf("Digite o terceiro valor: ");
    scanf("%f", &c);

    if ((b+c)>a)
    {
        if (a==b && b==c)
        {
            printf("\nTriângulo: Equilátero\n");
        }else if (a!=b && b!=c && a!=c)
        {
            printf("\nTriângulo: Escaleno\n");
        }else{
            printf("\nTriângulo: Isósceles\n");
        }
    }else{
        printf("\nNão é um triângulo!!\n");
    }
}