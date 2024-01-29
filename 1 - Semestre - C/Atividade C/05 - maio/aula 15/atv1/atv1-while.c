#include <stdio.h>

int main(){
    int num, cont = 0;

    printf("Insira um valor positivo: ");
    scanf("%d", &num);

    //validação de entrada
    while(num<=0){
        printf("%d não é positivo!!\nInsira uma valor positivo: ",num);
        scanf("%d", &num);
    }

    //Ordem Crescente
    printf("\nForma crescente:     ");
    while(cont <= num){
        printf("%d ", cont);
        cont++;
    }
    
    //Ordem Decrescente
    printf("\nForma decrescente:   ");
    cont = 0;
    while(num>=cont){
        printf("%d ", num);
        num--;
    }
    printf("\n");
}