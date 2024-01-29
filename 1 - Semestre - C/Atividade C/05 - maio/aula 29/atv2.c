/*Encontrar o maior valor, menor valor e média
dos valores de um vetor de 20 elementos*/

#include <stdio.h>

int main(){
    int num[20], maior = 0, menor = 0;
    printf("insira os valores para armazenar: ");
    scanf("%d", &num[0]);

    maior = num[0];
    menor = num[0];
    for (int i = 1; i < 20; i++)
    {
        scanf("%d", &num[i]);
        if (num[i] > maior)
        {
            maior = num[i];
        }
        if (num[i]<menor)
        {
            menor = num[i];
        }  
    }
    printf("O maior número é: %d\n", maior);
    printf("O menor número é: %d\n", menor);
}