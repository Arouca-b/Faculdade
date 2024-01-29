/*Programa para imprimir todos os divisores de um
número. Para um dado número n, o programa tem
que testar todos os números de 1 até n.*/

#include <stdio.h>

int main(){
    int num, div = 1;
    printf("Insira um valor positivo: ");
    scanf("%d", &num);
    
    while(num<=0){
        printf("\n**número não atende os requisitos**\n\n insira um valor positivo: ");
        scanf("%d", &num);
    }
    // Divisores
    printf("Divisores de %d: ", num);

    do
    {
        int a = num % div == 0;
        printf("%d ", a * div);
        div++;
    } while (div <= num);

}