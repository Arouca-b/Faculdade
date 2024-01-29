/*
    12. Faça uma função recursiva que receba um vetor e o seu tamanho e
calcule a média dos elementos do vetor.
*/
#include <stdlib.h>
#include <stdio.h>

float media_vet_calda(int *vet, int tam, int inicio, float soma){
    if (inicio == tam)
        return soma/inicio;
    soma+=vet[inicio];
    return media_vet_calda(vet, tam, inicio+1, soma);
}

float media_vet(int *vet, int tam){
    return media_vet_calda(vet, tam, 0, 0);
}

int main(){
    int vet[] = {1,2, 4, 9, 15};

    printf("MEDIA DA SOMA DOS ELEMENTOS: %.2f\n\n", media_vet(vet, 5));
}