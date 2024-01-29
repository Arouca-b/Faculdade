/*Implemente uma função recursiva que receba como
parâmetros um vetor de inteiros e um valor qualquer. Retorne 1,
se o valor existir na estrutura, ou 0, se não existir.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void num_aleatorios_vetor(int**vet, int tam){
    srand(time(NULL));
    if (tam - 1 == 0){
        (*vet) = rand()%10;
    }else{
        (*vet) = rand()%10;
    }
    
}

int main(){
    int* vet1, vet2;
    int tam = 0;
    vet1 = vet2 = malloc(sizeof(int));
    printf("Insira o tamanho dos vetores: ");
    printf("vet1: ");
    scanf("%d%*c", &tam);
    printf("vet2: ");
    scanf("%d%*c", &tam);
    vet1 = realloc(vet1, tam * sizeof(int));
    vet2 = realloc(vet2, tam * sizeof(int));
    
}