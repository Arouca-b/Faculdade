#include <stdio.h>
#include <stdlib.h>
#define TAM 4

void main(){
    int matriz[TAM][TAM], retorno = 1, superior = 0, inferior = 0;

    printf("\t\tMATRIZES\n");
    for (int i = 0; i < TAM; i++){
        for (int j = 0; j < TAM; j++){
            if (i > j){
                matriz[i][j] = 1;
            }else if(i==j){
                    matriz[i][j] = 2;
                }else{
                matriz[i][j] = 0;
            } 
        }
    }
    system("clear||cls");
    for (int i = 0; i < TAM; i++){
        printf("\t\t|");
        for (int j = 0; j < TAM; j++){
            printf(" %d |", matriz[i][j]);
            if (i>j && superior == 0 && matriz [i][j] && retorno == 1){
                superior = 1;
            }else if (i<j && matriz [i][j] && inferior == 0 && retorno == 1){
                inferior = 1;
            }
            if(inferior != 0  && superior != 0 && retorno == 1){
                retorno = 0;
            }
        }
        printf("\n");
    }
    printf("\n\t");
    (retorno == 0) ? printf("Não é uma matriz Triangular;") : (inferior == 0 && superior == 0) ? printf("Matriz Triangular: Inferior e Superior!") : (superior == 0) ? printf("Matriz Triangular: Superior") : printf("\tMatriz Triangular: Inferior");
    printf("\n\n");
}