/*
Faça a função inverteVet(vet, tam) que recebe como argumento um
vetor de números inteiro e o seu tamanho, e retorna o mesmo vetor
mas invertido.
*/

#include <stdio.h>

int* invertVet_calda(int* vet, int tam, int aux, int guarda){
    if(tam-1 <= aux)
        return vet;
    guarda = vet[tam-1];
    vet[tam-1] = vet[aux];
    vet[aux] = guarda;
    return invertVet_calda(vet, tam-1, aux+1, 0);
}

int* invertVet(int *vet, int tam){
    return invertVet_calda(vet, tam, 0, 0);
}

void imprimir_vetor(int*vet, int tam){
    for (int i = 0; i < tam; i++){
        printf("%d ", vet[i]);
    } 
}

int main(){
    int n[] = {5,0,3,6,1};
    printf("\n\nVETOR: ");
    imprimir_vetor(n, 5);
    
    invertVet(n, 5); // Chama a função para inverter o vetor
    
    printf("\n\nVETOR INVERTIDO: ");
    imprimir_vetor(n, 5);
}