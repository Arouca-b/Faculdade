#include <stdio.h>

void mostrar_pares(int n){
    if(n == 0){
        printf("0\n\n");
    }else{
        if((n%2)==0){
            printf("%d ", n);
        }
        mostrar_pares(n-1);
    }
}

void mostrar_pares2(int n){
    if(n == 0){
        printf("0 ");
    }else{
        mostrar_pares2(n-1);
        if((n%2)==0){
            printf("%d ", n);
        }
    }
}


int main(){

    printf("\nPares: ");
    mostrar_pares(4);
    printf("\nPares Crescente: ");
    mostrar_pares2(4);
    printf("\n\n");
}