/*Leia um número inteiro e converta-o para uma string,
imprima-o na tela como string*/

#include <stdio.h>

int main(){
    int caralho, i=0;
    char emyle[100];

    printf("Insira um número: ");
    scanf("%d", &caralho);
    
    for( i = 0; caralho > 0; i++){
        int aux = caralho % 10;
        emyle[i] = aux + 48;
        caralho = caralho / 10;
        
    }
    printf("String: ");
    for (i-=1; i >= 0; --i){
        printf("%c", emyle[i]); 
    }
    printf("\n\n");
}