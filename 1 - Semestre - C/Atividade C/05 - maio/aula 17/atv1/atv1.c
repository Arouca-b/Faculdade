/*No programa de perguntas para TV “Quer
ganhar uma bolada?”, cada pergunta
respondida corretamente vale o dobro da
anterior. Sendo 100 reais o valor da primeira
pergunta, faça um programa que receba o
número de perguntas certas e informe o
valor ganho pelo concorrente*/
#include <stdio.h>

int main(){
    int perguntas;
    float valor = 100, patrimonio;

    perguntas = patrimonio = 0;

    printf("Insira a quantidade de perguntas que o participante acertou: ");
    scanf("%d", &perguntas);

    for(int i = 1; i <= perguntas; ++i){
        patrimonio += valor;
        valor *= 2;
    }       
    printf("--------------------------------------------------\n|  O participante ganhou cerca de: R$%.2f  |\n--------------------------------------------------\n", patrimonio);

    for(perguntas = 0, valor = 100, patrimonio = 0; patrimonio <= 1000000.00; perguntas++){
        patrimonio += valor;
        valor *= 2;
    }       
    printf("\n\n**É necessário %d perguntas certas para o player atingir R$ 1 MILHAO**\n\n", perguntas);

    
}