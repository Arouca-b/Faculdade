/*Faça um programa em C que imprima uma constante
numérica PI, com 2, 4 e 6 e 8 casas decimais, usando
o comando de formatação numérica. Assuma PI
sendo 3.14159295*/

#include <stdio.h>
#define PI 3.14159295

int main(){
    printf("\n\t\tValor de pi com 2 casas decimais: %.2f\n", PI);
    printf("\t\tValor de pi com 4 casas decimais: %.4f\n", PI);
    printf("\t\tValor de pi com 6 casas decimais: %.6f\n", PI);
    printf("\t\tValor de pi com 8 casas decimais: %.8f\n\n", PI);
}