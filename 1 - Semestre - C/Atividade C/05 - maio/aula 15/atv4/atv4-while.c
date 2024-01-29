/*Dado um número natural (n) desenhe um quadrado n x n.
(for aninhado).*/
#include <stdio.h>

int main(){
    int num;

    printf("Insira um valor positivo: ");
    scanf("%d", &num);
    while(num<0){
        printf("\n**número não atende os requisitos**\n\n insira um valor positivo: ");
        scanf("%d", &num);
    }
    printf("\n");
    for(int i = 1; i<= num; i++){
        if (num%i == 0)
        {
            /* code */
        }
        
    }
}