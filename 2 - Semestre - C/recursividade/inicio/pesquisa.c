#include <stdio.h>
#include <stdlib.h>
#include "arouca.h"

int main(){
    LISTA* ini = inicializar();
    int *vet = (int *) malloc(sizeof(int));
    int tam, pos;

    ini = insere_fim_rec(ini, 5);
    ini = insere_fim_rec(ini, 1);      
    ini = insere_fim_rec(ini, 4);   
    ini = insere_fim_rec(ini, 8);   
    ini = insere_fim_rec(ini, 7);   
    ini = insere_fim_rec(ini, 10);
    ini = insere_fim_rec(ini, 20);

    printf("\n\n");
    for (LISTA* a = ini; a != NULL; a = a->prox){
        printf("%d ", a->info);
    }
    printf("\n\n\n\n");

}