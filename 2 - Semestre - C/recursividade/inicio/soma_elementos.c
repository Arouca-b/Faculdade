#include <stdio.h>

int soma(int* vet1, int n){
    if (n == 0){
        return 0;
    }
    return vet1[n-1] + soma(vet1,n-1);
}

int main(){
    int*vet = (int*) malloc(sizeof(int));
    int tam;
    printf("Insira o tamanho do vetor: ");
    scanf("%d%*c", &tam);
    vet = realloc(vet, tam*sizeof(int));
    for(int i = 0; i < tam; i++){
        printf("Valor %dº elemento: ", i+1);
        scanf("%d%*c", &vet[i]);
    }
    printf("Soma dos elementos: %d\n\n", soma(vet, tam));
    
}