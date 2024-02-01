#include <stdio.h>
#include <stdlib.h>
#include "dados.h"

//MENSAGENS

void creditos(){
    printf("\t\t\t***  **  **  **  **  **  **  **  **  **  **  ***\n");
    printf("\t\t\t*                                              *\n");
    printf("\t\t\t*                                              *\n");
    printf("\t\t\t*           PROJETO DESENVOLVIDO POR:          *\n");
    printf("\t\t\t*              --> BRENO AROUCA <--            *\n");
    printf("\t\t\t*                                              *\n");
  /*printf("\t\t\t*                => PROFESSOR <=               *\n");
    printf("\t\t\t*                 --> EDGAR <--                *\n");
    printf("\t\t\t*                                              *\n");*/
    printf("\t\t\t*             PROGRAMA PARA SIMULAR            *\n");
    printf("\t\t\t*          MERCADO - LOJA - RESTAURANTE        *\n");
    printf("\t\t\t*                                              *\n");
    printf("\t\t\t*              REGISTRO DE PRODUTOS            *\n");
    printf("\t\t\t*                       &                      *\n");
    printf("\t\t\t*              EFETUAÇÃO DE VENDAS             *\n");
    printf("\t\t\t*                                              *\n");
    printf("\t\t\t*                                              *\n");
    printf("\t\t\t***  **  **  **  **  **  **  **  **  **  **  ***\n");
    sleep(8);
    system("clear||cls");
}

void menu() {
    printf("\t\t\t*------------------------------------------*\n");
    printf("\t\t\t|                                          |\n");
    printf("\t\t\t|               MERCADO NEGRO              |\n");
    printf("\t\t\t|                                          |\n");
    printf("\t\t\t|                                          |\n");
    printf("\t\t\t|    1.   Inserir Produto                  |\n");
    printf("\t\t\t|    2.   Atualizar estoque                |\n");
    printf("\t\t\t|    3.   Realizar venda                   |\n");
    printf("\t\t\t|    4.   Consultar preço                  |\n");
    printf("\t\t\t|    5.   Produtos Cadastrados             |\n");
    printf("\t\t\t|    6.   Relatório Faturamento            |\n");
    printf("\t\t\t|                                          |\n");
    printf("\t\t\t|                                          |\n");
    printf("\t\t\t|    0.   Sair                             |\n");
    printf("\t\t\t*------------------------------------------*\n\n\n");

    printf("\t\t\tEscolhe: ");
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
