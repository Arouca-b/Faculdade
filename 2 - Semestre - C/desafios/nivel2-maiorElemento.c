/*4. Implemente uma função recursiva para encontrar o maior elemento em um vetor de inteiros.

    Crie uma função recursiva para inverter um vetor de inteiros (sem usar vetores temporários).
    Desenvolva uma função recursiva para calcular a soma dos elementos em uma matriz de inteiros.*/

#include <stdio.h>
#include <stdlib.h>
#include "arouca.h"

int maior_vet(int *v, int tam){
    if (tam==1){
        return v[0];
    }else{
        int maior = maior_vet(v, tam-1);
        return (v[tam-1] >= maior) ? v[tam-1]:maior;
    }
}

void invert(int v[], int tam, int inicio){
    if(tam<=inicio){
        return;
    }
    int temp = v[inicio];
    v[inicio] = v[tam-1];
    v[tam-1] = temp;
    invert(v, tam-1, inicio+1);
}

int soma_elementos_matriz(int **mat, int altura, int t_altura, int largura, int t_largura){
    if (altura == 1 && largura == 1){
        return mat[0][0];
    }else{
        if(altura-1>0 && largura == 0){
           return soma_elementos_matriz(mat, altura-1, t_altura, t_largura, t_largura); 
        }
        return mat[altura-1][largura-1] + soma_elementos_matriz(mat, altura, t_altura, largura-1, t_altura);
    }
}

int main(){
    int a, b;
    int vet[5] = {10,100,8,200,5};
    int **mat = (int**) malloc(2*sizeof(int*));
    for (int i = 0; i < 2; i++){
        mat[i] = malloc(2*sizeof(int));        
    }
    
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            scanf("%d%*c", &mat[i][j]);
        }
    }
    

    printf("Maior elemento: %d", maior_vet(vet, 5));
    invert(vet, 5, 0);
    
    printf("\n\nVetor trocado: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", vet[i]);
    }
    printf("\n");

    printf("Soma dos elementos: %d\n\n", soma_elementos_matriz(mat, 2, 2, 2, 2));

}