/*Informar se a string lida do teclado contém um
palíndromo ou não*/
#include <stdio.h>

int main(){
    char texto [50], aux[50];
    int i = 0, j=0, diferente = 0;

    printf("Insira o valor de uma string: ");
    scanf("%[^\n]s", texto);
    printf("\n");
    for (; texto[i] != '\0'; i++){
        printf("%c", texto[i]);
        if (texto[i] != ' '){
            aux[j] = texto[i];
            j++;
        }
    }
    i = j;
    aux[j] = '\0';
    for ( j = 0; aux[j] != '\0'; j++){
        i--;
        if (aux[i] != aux[j])
        {
            diferente = 1;
        }
    }
    printf("\n");
    diferente >0 ? printf("Palindromo: False!\n\n"):printf("Palindromo: True\n\n");
}