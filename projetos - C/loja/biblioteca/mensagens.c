#include <stdio.h>
#include <stdlib.h>
#include "dados.h"

//MENSAGENS
void menu() {
    printf("\t\t\t\tMERCADO NEGRO\n\n\n");
    printf("1.    Inserir Produto\n");
    printf("2.    Atualizar estoque\n");
    printf("3.    Vendas\n");
    printf("4.    Consultar preço\n");
    printf("5.    Mostrar na tela os produtos e a quantidade existente em "
            "estoque\n");
    printf(
        "6.    Relatório de faturamento de vendas em um determinado periodo\n\n");
    printf("0.    SAIR\n\n");

    printf("Escolhe: ");
}

int escolhe_opcao() {
    char t[20];
    int opcao = 0;
    scanf("%19[^\n]", t);
    opcao = atoi(t);
    getchar();
    if ((opcao > 6 || opcao < 0)) {
        system("clear||cls");
        printf("\n\n\t\t\t\t OPÇÃO INVÁLIDA\n\n");
        return -1;
    }
    return opcao;
}

void pausa() {
    printf("\n\n\t\t\t\taperte ENTER para continuar\n\n");
    scanf("%*c");
    system("clear||cls");
}

void falta_dados() {
    system("clear||cls");
    printf("\n\n\t\t\t   Alimente o Banco de dados primeiro!!\n\n");
    pausa();
}

void erro() {
    system("clear||cls");
    printf("\n\n\t\t\tNão encontrado no banco de dados!!\n\n");
    pausa();
}

void limpar_memoria(VENDA *sistema_vendas, int quantidade_venda, PRODUTO *lista_produtos) {
    free(lista_produtos);
    for (int i = 0; i < quantidade_venda; i++) {
        free(sistema_vendas[i].itemvenda);
    }
    free(sistema_vendas);
}

void despedida(){
    system("clear||cls");
    printf("\n\n\n\n\t\t\tDESCANSAR NÉ!!\n\n\n\n\n\n\n\n");
}
