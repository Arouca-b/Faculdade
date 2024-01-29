/*1. Na teoria dos sistemas, define-se como elemento minimax de uma matriz, o menor elemento de uma linha onde se encontra o maior elemento da matriz. Faça um programa que leia uma matriz A(5,5), imprima-a e imprima o seu elemento minimax, juntamente com a sua posição (linha e coluna)*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    int A[5][5] = {0}, minimax = 0,max = 0, lin = 0, col = 0, i = 0, max_col, max_lin;


    //inserir valor para cada elemento da matriz
    for (lin = 0; lin < 5; lin++){
        for(col = 0; col < 5; col++){
            printf("Insira um valor para o elemento A[%d][%d]: ", lin+1, col+1);
            scanf("%d%*c", &A[lin][col]);
        }
    }
    //fim preenchimento

    //o maior valor passa a ser o primeiro elemento que vc inseriu
    max = A[0][0];
    system("clear||cls");

    //fazendo comparação para achar um valor maior do que o max = max = A[0][0];
    for (lin = 0; lin < 5; lin++){
        for ( col = 0; col < 5; col++){
            if (A[lin][col] > max){
                max = A[lin][col];

                //guardar as coodernadas do elemento com maior valor;
                max_col = col;
                max_lin = lin;
            }  
        }
    }
    //fim da comparação

    //aqui é para achar o menor valor da linha que o maior elemento está, o max_lin é a linha que o maior elemento está
    minimax = A[max_lin][0];

    for ( i = 0; i < 5; i++){
        if (A[max_lin][i] < minimax){
            minimax = A[max_lin][i];

            //preciso guardar as coodernadas do menor elemento, a linha já está armazenada no max_lin e utilizo o max_col para guardar a coluna
            max_col = i;
        }
    }
    printf("MAX: %d\n", max);
    printf("Minimax: %d\n", minimax);
    printf("Posição: [%d][%d]\n\n\n", max_lin + 1, max_col + 1);

    //imprimir a matriz na tela
    for(lin = 0; lin < 5; lin++){
        for ( col = 0; col < 5; col++)
        {
            printf("%4d |", A[lin][col]);
        }
        printf("\n");
    }
    printf("\n\n\n");
    
}