//temperaturas strtok();

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int mes;
    float media;
    float maior;
    float menor;
    float temperatudas[31];
}MESES;

int main(){
    MESES *mes = (MESES*) malloc(sizeof(MESES));
    
}