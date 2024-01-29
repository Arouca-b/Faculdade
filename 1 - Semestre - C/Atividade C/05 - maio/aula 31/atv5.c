#include <stdio.h>
#include <stdlib.h>

int main(){
    char texto[100], cripto[100];
    int i;

    printf("Insira uma mensagem: ");
    scanf("%[^\n]s", texto);
    system("clear||cls");
    printf("\n\n\n\n\t\t\tTexto: ");
    for ( i = 0; texto[i] != '\0'; i++){
        if (texto[i] == 'A' || texto[i] == 'E' || texto[i] == 'I' || texto[i] == 'O'|| texto[i] == 'U' || texto[i] == 'a' || texto[i] == 'e' || texto[i] == 'i' || texto[i] == 'o' || texto[i] == 'u'){
           cripto[i] = texto[i] + 5;
        }else if(texto[i] >= 65 && texto[i] <= 77 || texto[i] >= 97 && texto[i] <= 109 ){
            cripto[i] = texto[i] + 11;
            
        }else if(texto[i] == ' ' || texto[i] == '-'){
            cripto[i] = 33;
        }else{
            cripto[i] = texto[i] - 10;
        }
        printf("%c", texto[i]);
    }
    cripto[i] = '\0';
    printf("\n\n\t\t\tCriptografia: ");
    for (int j = 0; j <= i; j++)
    {
        printf("%c", cripto[j]);
    }
    printf("\n\n\n\n\n\n");
}