//Receba uma string e um caractere, e apague todas as ocorrências desse caractere na string

#include <stdio.h>

int main(){
    char matriz[100] = {0}, n_matriz[100] = {0}, text;
    int i, tam = 0,pos;

    printf("\n\nDigite uma string: ");
    scanf("%[^\n]%*c", matriz);
    printf("Insira um char: ");
    scanf("%c", &text);
    
    printf("\n\nString: %s\n", matriz);
    for ( i = 0, tam = 0; matriz[tam] != '\0'; tam++){
            if (matriz[tam] != text){
                n_matriz[i] = matriz[tam];
                i++;
            }
    }

    printf("Char: %c\n", text);
    printf("Nova String: %s\n", n_matriz);
}