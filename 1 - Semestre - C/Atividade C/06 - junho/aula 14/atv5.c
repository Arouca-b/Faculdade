/*Escreva um programa que imprima a tabuada de multiplicação
em forma de tabela:*/

#include <stdio.h>

int main(){
    int tabuada[10][10] = {0}, mul;

    printf("\t");
    for(int i = 0; i<10; i++)
        printf("%2d ", i);
    printf("\n\t------------------------------\n"); 

    for ( int i = 0; i < 10; i++){
        printf("    %2d |", i);
        for(int j = 0; j < 10; j++){
            mul = i * j;
            printf("%2d ", mul);
        }
        printf("\n");
    }
printf("\n\n\n");
}