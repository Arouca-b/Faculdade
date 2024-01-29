//adicionar um char em uma posição especifica da string

#include <stdio.h>

int main(){
    char matriz[100] = {0}, text;
    int i, tam = 0,pos;

    printf("\n\nDigite uma string: ");
    scanf("%[^\n]s", matriz);
    printf("Insira um char: ");
    scanf(" %c", &text);
    printf("Informe a posição: ");
    scanf("%d%*c", &pos);

    
    printf("\n\nString: %s\n", matriz);
    for (tam = 0; matriz[tam] != '\0'; tam++);
    for (;tam != pos; tam--){
        matriz[tam] = matriz[tam-1];
    }
    matriz[pos] = text;
    printf("Char: %c\n", text);
    printf("Posição: %d\n", pos);
    printf("Nova String: %s\n", matriz);
}