#include <stdio.h>
#include <stdlib.h>
#include "/home/arouca/Programação/back-end/C/uesc.2/atividades/biblioteca/arouca.h"
#define PI 3.14

float area(float a){
    return (a * a) * PI;
}

int main(){
    float raio;

    printf("Insira o raio da circunferência: ");
    scanf("%f%*c", &raio);
    printf("A área é: %.2f\n\n", area(raio));
}