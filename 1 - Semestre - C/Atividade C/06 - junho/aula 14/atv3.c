/*Leia uma matriz 3x4 e imprima-a ao contrário,
começando pelo elemento 3x4 e terminando no 0x0,
depois sua transposta (troca de linhas por colunas)*/
#include <stdio.h>
#include <stdlib.h>
int main(){
    int matriz[3][4] = {0}, lin, col, transposta[4][3]={0}; 

    //inserir valor na matriz
    for (lin = 0; lin < 3; lin++){
        for ( col = 0; col < 4; col++){
            printf("%dº elemento da %dº coluna: ", lin+1, col+1);
            scanf("%d%*c", &matriz[lin][col]);
        }
    }
    system("clear||cls");
    printf("\t\t Matriz Original: \n\n\n");
    for (lin = 0; lin < 3; lin++){
        for ( col = 0; col < 4; col++){
            printf("| %4d  |", matriz[lin][col]);
        }
        printf("\n");
    }
    printf("\n");
    printf("\t\t Matriz ao contrário: \n\n\n");
    for (lin = 2; lin >= 0; lin--){
        for ( col = 3; col >= 0; col--){
            printf("| %4d  |", matriz[lin][col]);
        }
        printf("\n");
    }
    printf("\n\n\t\t Matriz Transposta: \n\n\n");
    for (lin = 0; lin <3; lin++)
        for ( col = 0; col < 4; col++)
            transposta[col][lin] = matriz[lin][col];
            
    for (col = 0; col <4; col++){
        for ( lin = 0; lin < 3; lin++){
            printf("| %4d   |", transposta[col][lin]);
        }
        printf("\n");
    }
    printf("\n");
}