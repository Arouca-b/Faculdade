
#ifndef MENSAGENS_H
#define MENSAGENS_H
#include "dados.h"

void creditos();
void menu();
int escolhe_opcao();
void falta_dados();
void pausa();
void erro();
void limpar_memoria(VENDA *sistema_vendas, int quantidade_venda, PRODUTO *lista_produtos);
void despedida();

#endif // MENSAGENS_H
