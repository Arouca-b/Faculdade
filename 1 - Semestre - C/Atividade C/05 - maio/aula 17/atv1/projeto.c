#include <stdio.h>

int main(){
    int i, j, soma, limite = 0, q_vizinhos = 0, matriz[3][3];
    float media = 0;

    printf("Digite o limite para ruído na imagem: ");
    scanf("%d", &limite);

    for(i = 0; i <= 2; i++){
        for(j = 0; j <= 2; j++){
            printf("Digite o valor da posição [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    printf("\n");
    /*//para os ruidos não terem influência na média
    for(i = 0; i <= 2; i++){
        for(j = 0; j <= 2; j++){
           if(matriz[i][j] > limite){
                matriz[i][j] = 0;
            }
        }
    }*/
    printf("  ____________________\n");

    //for mais importante, corrigir os ruídos pela média dos vizinhos
    for(i = 0; i <= 2; i++){
        printf(" | ");
        for(j = 0; j <= 2; j++){
            // identificar e somar os vizinhos
            if(matriz[i][j] == 0){
                if((i == 1 && j == 0) || (i == 1 && j == 2)){
                    q_vizinhos = 5;
                }else{
                    q_vizinhos = (i-1 >= 0 && j-1 >= 0) + (i-1 >= 0) + (i-1 >= 0 && j+1 <= 2) + (j-1 >= 0) + (j+1 <= 2) + (j-1 >= 0 && i+1<=2) + (i+1<=2) + (j+1 <= 2 && i+1<=2); 
                }
                soma = matriz[i-1][j-1] * (i-1 >= 0 && j-1 >= 0) + matriz[i-1][j] * (i-1 >= 0) + matriz[i-1][j+1] * (i-1 >= 0 && j+1 <= 2) + matriz[i][j-1] * (j-1 >= 0) + matriz[i][j+1] * (j+1 <= 2) + matriz[i+1][j-1] * (j-1 >= 0 && i+1<=2) + matriz[i+1][j] * (i+1<=2) + matriz[i+1][j+1] * (j+1 <= 2 && i+1<=2);
                
                media = soma/(q_vizinhos);
                

                matriz[i][j] = (((matriz[i][j] - media ) > limite) ||  ((matriz[i][j] - media ) < 0)) ? media : matriz[i][j];
            }
            printf(" %4d ", matriz[i][j]);
        }
        printf(" |\n");
    }
    printf("  ---------------------\n");
}