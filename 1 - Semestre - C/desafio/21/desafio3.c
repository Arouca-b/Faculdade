#include <stdio.h>

int main(){
    char frase[1000] = {0};
    int cont, palavras = 1;

    printf("Digite uma frase: ");
    scanf("%[^\n]s%*c", frase);

    for (cont = 0; frase[cont] != '\0'; cont++){
        if (frase[cont] == ' ')
        {
            palavras++;
        }
    }

    printf("Frase: %s\n", frase);
    printf("Quant palavras: %d\n", palavras);
    printf("\n\n");
}