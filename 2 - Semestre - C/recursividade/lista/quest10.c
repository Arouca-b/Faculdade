/*
Faça a função intercala que recebe como argumentos dois vetores
vet1 e vet2, e os respectivos tamanhos, e devolve um vetor com os
elementos de vet1 e vet2 intercalados.
*/

#include <stdio.h>
#include <stdlib.h>

int* intercala_vet_calda(int *vet1, int tam1, int *vet2, int tam2, int *vet_int, int tam_int){
    if (tam1-1 >=0 ){
        vet_int[tam_int-1] = vet1[tam1-1];
        if (tam2-1 >= 0){
            vet_int[tam_int-2] = vet2[tam2-1];
            return intercala_vet_calda(vet1, tam1-1, vet2, tam2-1, vet_int, tam_int-2);
        }
    
    return intercala_vet_calda(vet1, tam1-1, vet2, tam2, vet_int, tam_int-1);

    }else if(tam2-1 >= 0){
            vet_int[tam_int-1] = vet2[tam2-1];
            return intercala_vet_calda(vet1, tam1, vet2, tam2-1, vet_int, tam_int-1);
    }
    return vet_int;
}

int* intercala(int *vet1, int tam1, int *vet2, int tam2){
    int *vet = (int*) malloc(sizeof(int) * (tam1 + tam2));
    return intercala_vet_calda(vet1, tam1, vet2, tam2, vet, tam1+tam2);
}

void imprimir_vetor(int*vet, int tam){
    for (int i = 0; i < tam; i++){
        printf("%d ", vet[i]);
    } 
}

int main(){
    int vet1[] = {1,3,5,7,9};
    int vet2[] = {0,2,4,6,8,10};
    int *Vet_inter = intercala(vet1, 5, vet2, 6);
    imprimir_vetor(Vet_inter, 6+5);
    free(Vet_inter);
}