/*Faça um programa que imprima uma letra C gigante,
usando a própria letra ‘C’ de 2 maneiras diferente:
tudo num printf único e com vários printfs
CCCCC
C
C
CCCCC*/
#include <stdio.h>

int main(){
    printf("%c%c%c%c%c",'C','C','C','C','C');
    printf("\n%c",'C');
    printf("\n%c",'C');
    printf("\n%c",'C');
    printf("%c",'C');
    printf("%c",'C');
    printf("%c",'C');
    printf("%c\n",'C');
}