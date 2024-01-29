/*Escreva um programa que leia uma matriz 3x3,
imprima-a em forma de tabela, calcule seu traço,
maior valor, menor valor e média. Lembrando que o
traço de uma matriz é a soma dos elementos da
diagonal principal*/
#include <stdio.h>
#include <stdlib.h>

int main(){
    int matriz[3][3] = {0}, lin, col, soma = 0, traco = 0, maior = 0, menor = 0; 

    //inserir valor na matriz
    for (lin = 0; lin < 3; lin++){
        for ( col = 0; col < 3; col++){
            printf("%dº elemento da %dº coluna: ", lin+1, col+1);
            scanf("%d%*c", &matriz[lin][col]);
        }
    }
    system("clear||cls");

    maior = matriz[0][0];
    menor = matriz[0][0];
    printf("\n\n");
    //Imprimir matriz, achar menor e maior elemento
    for (lin = 0; lin < 3; lin++){
        printf("\t\t");
        for ( col = 0; col < 3; col++){
            printf("|   %4d   |", matriz[lin][col]);

            //valor da dp
            if(col == lin)
                traco+=matriz[lin][col];
            
            //Maior elemento
            if (matriz[lin][col] > maior)
                maior = matriz[lin][col];
            
            //menor elemento
            if (matriz[lin][col] < menor)
                menor = matriz[lin][col];

            //soma dos elementos
            soma += matriz[lin][col];
        }
        printf("\n");
    }
 
    printf("\n\tTraço = %d\n", traco);
    printf("\tMaior elemento = %d\n", maior);
    printf("\tMenor elemento = %d\n", menor);
    printf("\tMédia = %.2f\n\n\n", (float) soma/9);
}