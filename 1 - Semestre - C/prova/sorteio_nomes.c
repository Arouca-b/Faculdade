//sorteio de pessoas

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
    int q = 2;
    int idade[q];
    char nome[q][30]; 
    
    for ( int i = 0; i < q; i++){
    printf("Insira seu nome: ");
    scanf("%s", nome[i]);
    printf("Insira sua idade: ");
    scanf("%d", &idade[i]);
    printf("\n");
    }

    system("clear||cls");

    srand(time(0));
    q = rand() % q;
    printf("Nome: %s\n", nome[q]);
    printf("Idade: %d\n\n", idade[q]); 
}