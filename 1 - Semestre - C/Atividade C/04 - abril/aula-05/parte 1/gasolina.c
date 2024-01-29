#include <stdio.h>

int main(){
    float km, l,km_l;

    printf("KMs percorridos: ");
    scanf("%f", &km);
    printf("Litros gastos: ");
    scanf("%f", &l);

    km_l = km/l;

    printf("\nSeu carro faz %.2f km/l\n", km_l);
}