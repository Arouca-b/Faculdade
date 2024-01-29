#include <stdio.h>

int main(){
    char letra;
    printf("\tDigite uma letra minúscula: ");
    scanf("%c", &letra);

    if (letra != 'a' && letra != 'z')
    {
        printf("\tPredecessora é: %c\n \tSucessora é: %c\n", letra - 1, letra + 1);
    }else{
        if (letra == 'a')
        {
            printf("\tSucessora é: %c\n", letra + 1);
            printf("\tOBS: letra *%c* é a primeira letra do alfabeto, não tem Predecessora\n", letra);
        }else{
            printf("\tPredecessora é: %c\n", letra - 1);
            printf("\tOBS: letra *%c* é a última letra do alfabeto, não tem Sucessora\n", letra);
        } 
    }
}