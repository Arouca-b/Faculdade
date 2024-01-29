#include <stdio.h>
#include <stdlib.h>
#define TAM 3
void main(){
    int quad[TAM][TAM] = {0}, soma = 0, soma2=0, aux=0, verdade=1;
    
    printf("\t\tMATRIZES\n");
    for (int i = 0; i < TAM ; i++){ //Inicio das atribuições e soma das linhas
        for (int j = 0; j < TAM; j++){
            //aplicando valores nos elementos
            printf("Insira um valor para a posição [%d][%d]: ", i,j);
            scanf("%d%*c", &quad[i][j]);
            if (verdade){
                soma+=quad[i][j]; //Soma horizontal
                if (i+j == TAM - 1){
                    soma2+=quad[i][j]; //Soma Diagonal Secundaria
                }
                if( i && j==TAM-1 && (soma != aux || (i == TAM-1 && soma2 != aux)) && verdade == 1){ //comparação das somas das linhas
                //o if serve para fazer validação, se as somas forem diferentes vai acusar falso e não será executado mais nenhum cálculo no código
                    verdade = 0;
                }
                if ((!i) && j==TAM-1){ //atribuir o valor da soma da primeira linha
                    aux = soma;
                }
            }
        }
        soma = 0;
    } //final das atribuições e soma das linhas
    printf("\n\n\n");

    //Imprimir na tela e realizar cálculos
    for (int i = 0; i < TAM; i++){
        printf("\t\t\t\t");
        soma2=0;
        for (int j = 0; j < TAM; j++){
            printf("| %2d ", quad[i][j]); // -> Imprimir na tela
            if (verdade){ // Realizar os cálculos da vertical e DP se os calculos anteriores forem iguais
                soma2+=quad[j][i]; //Soma vertical
                if((i == j)){
                    soma += quad[i][j]; //Soma diagonal principal
                }
            }
            if((( i == TAM-1 && j == TAM-1 && soma != aux) || ( j == TAM -1 && soma2 != aux)) && verdade == 1 ){ //para fazer validação, se as somas forem diferentes vai acusar falso e não será executado mais nenhum cálculo
                verdade = 0;
            }
        }
        printf("| \n\n");
    }
    (!verdade) ? printf("\n\n\t\t\t\tNão é Cubo Mágico!\n\n\n\n") : printf("\n\n\t\t\t\tÉ um Cubo mágico!!\n\n\n\n");
}