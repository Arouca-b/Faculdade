/*
Faça uma função chamada repete que receba como argumento um
vetor de números inteiros e retorne outro vetor onde o primeiro
elemento aparece repetido uma vez, o segundo elemento aparece
repetido duas vezes e assim sucessivamente.
Exemplo:
repete({1,2,3}) = {1, 2, 2, 3, 3, 3}
*/
#include <stdio.h>
#include <stdlib.h>

int* calda_repete(int *vet, int tam, int *vet_r, int tam_r, int rep){
    if(tam-1==0){
        vet_r[0] = vet[0];
        return vet_r;
    }
    if (rep){
        vet_r[tam_r-1] = vet[tam-1];
        return calda_repete(vet, tam, vet_r, tam_r-1, rep-1);
    }
    return calda_repete(vet, tam-1, vet_r, tam_r, tam-1);
}

int somatorio(int n){
    if(n==0)
        return 0;
    return n+somatorio(n-1);
}

int *repete(int*vet, int tam){
    int tam_r = somatorio(tam);
    int *vet_r = (int*) malloc(sizeof(int) * tam_r);
    return calda_repete(vet, tam, vet_r, tam_r, tam);
}

void imprimir_vetor(int*vet, int tam){
    for (int i = 0; i < tam; i++){
        printf("%d ", vet[i]);
    } 
}

int main(){
    int vet1[] = {1,2,3, 4, 5};
    int *Vet_inter = repete(vet1, 5);
    imprimir_vetor(Vet_inter, somatorio(5));
    free(Vet_inter);
}