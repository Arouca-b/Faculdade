#include <stdio.h>

int main(){
    char frase[1000] = {0}, frase2[1000] = {0};
    int cont, maior = 0, tam1, tam2;

    printf("Digite uma frase: ");
    scanf("%[^\n]s%*c", frase);

    printf("Digite uma Segunda frase: ");
    scanf(" %[^\n]s%*c", frase2);

    for (tam1 = 0; frase[tam1] != '\0'; tam1++);
    for (tam2 = 0; frase[tam2] != '\0'; tam2++);
    
    cont = tam2;
    if(tam1 > tam2){
        cont = tam1;
    }
    for(int i = 0; i <= cont; i++){
        if ((int) frase[i] > (int) frase2[i]){
            maior--;
            break;
        }else if((int) frase[i] < (int) frase2[i]){
            maior++;
            break;
        }
    }
    maior > 0 ? printf("A primeira frase é maior: %s\n\n", frase) : maior == 0 ? printf("As duas são iguais: %s\n\n", frase) : printf("A segunda frase é maior: %s\n\n", frase2); 
}