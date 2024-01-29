/*Programa para imprimir todos os divisores de um
número. Para um dado número n, o programa tem
que testar todos os números de 1 até n.*/

#include <stdio.h>

int main(){
    int num;
    printf("Insira um valor positivo: ");
    scanf("%d", &num);
    
    while(num<=0){
        printf("\n**número não atende os requisitos**\n insira um valor positivo: ");
        scanf("%d", &num);
    }
    printf("Divisores de %d: ", num);
    for(int div = 1; div <= num; div++){
        int a = num % div == 0;
        printf("%d ", a * div);
    }
}