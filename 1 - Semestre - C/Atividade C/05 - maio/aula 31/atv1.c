#include <stdio.h>

int main() {
    char texto[50];
    int i;
    printf("Insira um valor para uma string: ");
    scanf("%[^\n]s", texto);

    for(i = 0; texto[i] != '\0'; i++);
    printf("\nO inverso é: ");
    for (; i>=0; i--)
    {
        printf("%c", texto[i]);
    }
    printf("\n");
}