/*Escreva um programa que pergunte um número ao usuário que deve estar entre 2 a 10, e leia este número validando-o. Em seguida gere e imprima uma matriz quadrada do tamanho do número lido, com os seguintes valores: 0 para a diagonal principal, 1 nas bordas e o restante com 2*/
#include <stdio.h>
#include <stdlib.h>

int main(){
    int num, matriz[10][10];

    printf("Qual o tamanho da matriz que vc deseja? ");
    scanf("%d%*c", &num);

    while (num>10 || num<2)
    {
        system("clear||cls");
        printf("\t\tValor inválido!! precisa ser de 2 até 10\n\n\n");
        printf("Qual o tamanho da matriz que vc deseja? ");
        scanf("%d%*c", &num);
    }
    for (int lin = 0; lin < num; lin++){
        for (int col = 0; col < num; col++){
            if (lin == col){
                matriz[lin][col] = 0;
            }else if(col == num-num || col == num-1 || lin == num-num || lin == num-1){
                matriz[lin][col] = 1;
                }else{
                matriz[lin][col] = 2;
                }   
            printf("%d | ", matriz[lin][col]);
        }
        printf("\n");
    }
}