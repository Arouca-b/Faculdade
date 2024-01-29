/*Faça a função contem_par(vet,tam) que recebe como argumento um
vetor de números inteiros e o seu tamanho e retorna True se vet
contém um número par e False em caso contrário.*/

#include <stdio.h>
#include <stdlib.h>

int contem_par(int *vet, int tam);

int main(){
    int vet[] = {0,1,3,5,9};
    printf("TEM PAR: %d\n\n", contem_par(vet, 5));
}

int contem_par(int *vet, int tam){
    if(tam-1==0 && vet[tam-1]%2){
        return 0;
    }
    if(vet[tam-1]%2){
        return contem_par(vet, tam-1);
    }
    return 1;
}