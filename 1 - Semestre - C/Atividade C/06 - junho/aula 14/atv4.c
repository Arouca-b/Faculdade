/*Multiplique matrizes lidas de 4x4 (soma dos produtos
dos elementos correspondentes da i-ésima linha de A
pelos elementos da j-ésima coluna B)*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    int matriz[4][4]={0}, matriz2[4][4]={0}, lin, col, mul[4][4]={0};

    //armazenar matriz A
    printf("\n\t\t\tPrimeira Matriz\n\n");

    for (lin = 0; lin < 4; lin++){
        for ( col = 0; col < 4; col++){
            printf("%dº elemento da %dº coluna: ", lin+1, col+1);
            scanf("%d%*c", &matriz[lin][col]);
        }
    }

    system("clear||cls");
    //armazenar matriz B
    printf("\n\t\t\tSegunda Matriz\n\n");

    for (lin = 0; lin < 4; lin++){
        for ( col = 0; col < 4; col++){
            printf("%dº elemento da %dº coluna: ", lin+1, col+1);
            scanf("%d%*c", &matriz2[lin][col]);
        }
    }

    system("clear||cls");  
    printf("\t\t\t\tMatriz A\n\n");
    //imprimir matriz A
    for (lin = 0; lin < 4; lin++){
        printf("\t\t");
        for ( col = 0; col < 4; col++){
            printf("|   %4d   |", matriz[lin][col]);
        }
        printf("\n");
    }
    printf("\n\n");
    //Imprimir matriz B
    printf("\t\t\t\tMatriz B\n\n");
    for (lin = 0; lin < 4; lin++){
        printf("\t\t");
        for ( col = 0; col < 4; col++){
            printf("|   %4d   |", matriz2[lin][col]);
        }
        printf("\n");
    }
    //armazenar multiplicação matriz 
    for ( lin = 0; lin < 4; lin++){
        int l_aux = 0;
            for ( col = 0; col < 4; col++){
                for ( int c_aux = 0; c_aux < 4; c_aux++){
                    mul[lin][col] += matriz[lin][c_aux] * matriz2[c_aux][l_aux];
                }
                l_aux++;
            }
    }
    printf("\n\n");
    //Imprimir multiplicação matriz 
    printf("\n\t\t\t\tMultiplicação\n\n");
    for (lin = 0; lin < 4; lin++){
        printf("\t\t");
        for ( col = 0; col < 4; col++){
            printf("|   %4d   |", mul[lin][col]);
        }
        printf("\n");
    }
}