//Conte o número de vogais de uma string dada
#include <stdio.h>

int main(){
    char texto[50];
    int q_vogais;

    printf("Insira uma string: ");
    scanf("%[^\n]s", texto);

    for(int i = 0; texto[i] != '\0'; i++){
        if (texto[i] == 'A' || texto[i] == 'E' || texto[i] == 'I' || texto[i] == 'O'|| texto[i] == 'U' || texto[i] == 'a' || texto[i] == 'e' || texto[i] == 'i' || texto[i] == 'o' || texto[i] == 'u')
        {
           q_vogais++;
        }
    }
    printf("Quantidade de vogais: %d\n", q_vogais);
}