#include <stdio.h>

int main(){
    int num, cont = 0;

    printf("Insira um valor positivo: ");
    scanf("%d", &num);

    //validação de entrada
    while(num<=0){
        printf("\n------------------\n| Valor Inválido |\n------------------\n\n\nInsira um valor positivo: ");
        scanf("%d", &num);
    }

    //ordem crescente
    printf("Ordem crescente:   ");
    do{
        printf("%d ", cont);
        cont++;
    }while(cont<=num);

    cont = 0;
    //ordem decrescente
    printf("\nOrdem decrescente: ");
    do{
        printf("%d ", num);
        num--;
    }while(num>=cont);
    printf("\n");

}