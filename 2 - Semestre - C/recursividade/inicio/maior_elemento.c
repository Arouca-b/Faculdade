/*Implemente recursivamente uma função Max que retorne o
maior valor armazenado em um vetor V, contendo n números
inteiros.*/
#include <stdio.h>
#include <stdlib.h>
#include "arouca.h"

int max_vet(int *vetor, int tam){

    if(tam == 0){
        return vetor[0];
    }else{
        if (vetor[tam-1] > max_vet(vetor, tam-1)){
            return vetor[tam-1];
        }
        return max_vet(vetor, tam-1);
    }
}

int main(){
    int *vet = (int*) malloc(sizeof(int));
    int tam;

    printf("Insira tamanho do vetor: ");
    scanf("%d%*c", &tam);
    vet = realloc(vet, tam*sizeof(int));
    for ( int i = 0; i < tam; i++){
        printf("\nElemento [%d]: ", i+1);
        scanf("%d%*c", &vet[i]);
    }
    printf("Maior elemento: %d\n\n", max_vet(vet, tam));
}