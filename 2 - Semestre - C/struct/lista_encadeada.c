#include <stdio.h>
#include <stdlib.h>
#include "arouca.h"


int main(){
    LISTA* lista = inicializar();
    lista = ordenar(lista, 11);
    lista = ordenar(lista, 9);
    lista = ordenar(lista, 10);
    lista = ordenar(lista, 12);
    lista = ordenar(lista, 1);
    lista = ordenar(lista, 17);
    lista = ordenar(lista, 18);
    lista = ordenar(lista, 5);
    lista = ordenar(lista, 2);
    imprimir_lista(lista);
}

