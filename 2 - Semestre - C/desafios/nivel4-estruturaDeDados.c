/*  Nível 4: Recursão com Estruturas de Dados
    Desenvolva uma função recursiva para percorrer uma lista encadeada e encontrar o elemento máximo.
    Implemente uma função recursiva para inverter uma lista encadeada.
    Escreva uma função recursiva para calcular a soma dos elementos em uma árvore binária.*/

#include <stdio.h>
#include <stdlib.h>
#include "arouca.h"

typedef struct arvore{
    int info;
    struct arvore *esquerda;
    struct arvore *direita;
}ARV;

int lista_max(LISTA* list, int max){
    if (list == NULL){
        return max;
    }else{
        if (list->info >= max){
            max = list->info;
        }
        return lista_max(list->prox, max);
    }
}

LISTA* invert(LISTA* list){
    if (list == NULL){
        return NULL;
    }

    if (list->prox == NULL){
        return list;
    }
    
    if(list->prox->prox == NULL){
        list->prox->prox = list;
        return list->prox;
    }else{
        LISTA* aux = invert(list->prox);
        list->prox->prox = list;
        list->prox = NULL;
        return aux;
    }
}

int soma_arvore(ARV *arvore){
    if (arvore == NULL){
        return 0;
    }
    else{
        return arvore->info + soma_arvore(arvore->direita) + soma_arvore(arvore->esquerda);
    }    
}

void liberarArvore(ARV *raiz) {
    if (raiz == NULL) {
        return;
    }
    liberarArvore(raiz->esquerda);
    liberarArvore(raiz->direita);
    free(raiz);
}

int main(){
    LISTA* lista = inicializar();
    ARV* teste = malloc(sizeof(ARV));
    lista = insere_fim_rec(lista, 1);
    lista = insere_fim_rec(lista, 2);      
    lista = insere_fim_rec(lista, 3); 
    lista = insere_fim_rec(lista, 4);  
    lista = insere_fim_rec(lista, 5);   
    lista = insere_fim_rec(lista, 6);   
    lista = insere_fim_rec(lista, 7);
    lista = insere_fim_rec(lista, 8);
    lista = insere_fim_rec(lista, 9);
    lista = insere_fim_rec(lista, 10);
    printf("MAX: %d\n\n", lista_max(lista, 0));
    printf("ANTES DE INVERTER: ");
    imprimir_lista(lista);
    lista = invert(lista);
    printf("DEPOIS DE INVERTER: ");
    imprimir_lista(lista);

    teste->info = 1; 
    teste->direita = malloc(sizeof(ARV));
    teste->direita->info = 2;
    teste->esquerda = malloc(sizeof(ARV));
    teste->esquerda->info = 3;
     teste->direita->direita = malloc(sizeof(ARV));
    teste->direita->esquerda = malloc(sizeof(ARV));
    teste->esquerda->direita = malloc(sizeof(ARV));
    teste->esquerda->esquerda = malloc(sizeof(ARV));
    teste->direita->direita->info = 2;
    teste->direita->esquerda->info = 3;
    teste->esquerda->direita->info = 2;
    teste->esquerda->esquerda->info = 3;
    printf("soma: %d\n\n", soma_arvore(teste));
    liberarArvore(teste);
}