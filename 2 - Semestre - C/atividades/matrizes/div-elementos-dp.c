#include <stdio.h>
#define TAM 3

void main(){
    float matriz[TAM][TAM]={0}, div = 0, cont = 1;
    for(int i = 0; i < TAM; i++){
        for(int j = 0; j < TAM; j++){
            printf("Insira uma valor para a matriz[%d][%d]: ", i+1, j+1);
            scanf("%f%*c", &matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    for (int i = 0; i < TAM; i++){
        div = matriz[i][i];
        printf("\t\t|");
        for (int j = 0; j < TAM; j++){
            matriz[i][j] /= div;
            printf(" %.1f |", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
}