/*
15. Crie um programa em C, que contenha uma função recursiva para
encontrar o menor elemento em um vetor. A leitura dos elementos do
vetor e impressão do menor elemento devem ser feitas no programa
principal.
*/

#include <stdio.h>
#include <stdlib.h>
#define TAM 9

int menor_elemento(int* vet, int tam);

int main(){
    int vet[TAM] = {4, 3, 2 , 0 ,5,20,7,6,9};
    
    printf("Elementos vetor: ");
    for (int i = 0; i < TAM; i++){
        printf("%d ", vet[i]);
    }
    printf("\nMenor elemento está na posição: %d\n\n\n", menor_elemento(vet, TAM));
}

int menor_elemento(int* vet, int tam){
    if (tam-1 == 0){
        return vet[0];
    }
    if(vet[tam-1] < menor_elemento(vet, tam-1)){
        return tam;
    }
    return menor_elemento(vet, tam-1);
}