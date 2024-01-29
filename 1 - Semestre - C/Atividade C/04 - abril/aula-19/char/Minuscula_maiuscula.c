#include <stdio.h>

int main(){
    char letra;
    printf("\tDigite uma letra minuscula: ");
    scanf("%c", &letra);
    printf("\tSua correspondência em MAIÚSCULA é: %c\n", letra-32);
}