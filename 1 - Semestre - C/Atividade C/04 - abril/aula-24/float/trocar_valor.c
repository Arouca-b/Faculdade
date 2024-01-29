/*Faça um programa que peça para o usuário digitar 2
caracteres e leia-os, depois coloque o primeiro valor
em uma variável chamada de A e o segundo valor em
outra variável chamada de B. Em seguida, seu
programa deverá trocar o conteúdo destas variáveis e
imprimir na tela o que cada variável contém*/
#include <stdio.h>

int main(){
    char A, B, aux;

    printf("Digite um caractere: ");
    scanf("%c", &A);
    printf("Digite outro caractere: ");
    scanf(" %c%*c", &B);  
    
    aux = A;
    A=B;
    B=aux;

    printf("A = %c\nB = %c\n", A, B); 
}