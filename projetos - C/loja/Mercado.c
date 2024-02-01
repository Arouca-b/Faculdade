#include "biblioteca/vendas.h"
#include "biblioteca/produto.h"
#include "biblioteca/dados.h"
#include "biblioteca/mensagens.h"
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


int main() {
    setlocale(LC_ALL, "Portuguese");
    int quant_produtos = 0, quant_vendas = 0;
    int opcao = 0;
    VENDA *vendas_prod = recupera_historico_vendas(vendas_prod, &quant_vendas);
    PRODUTO *lista_Produtos = recupera_lista_produtos(lista_Produtos, &quant_produtos);
    
    if (quant_produtos == 0 && quant_vendas==0){
        creditos();
    }
    do {
        menu();
        fflush(stdin);
        opcao = escolhe_opcao();

        switch (opcao) {
            case 1:
                lista_Produtos = inserir_prod(&quant_produtos, lista_Produtos);
                salvar_lista_produtos(lista_Produtos, quant_produtos);
            break;

            case 2:
                if (quant_produtos) {
                    atualizar_estoque(lista_Produtos, quant_produtos);
                } else {
                    falta_dados();
                }
            break;

            case 3:
                if (quant_produtos) {
                    vendas_prod = venda_de_produto(vendas_prod, &quant_vendas, lista_Produtos, quant_produtos);
                } else {
                    falta_dados();
                }
            break;

            case 4:
                if (quant_produtos) {
                    consultar_preco(lista_Produtos, quant_produtos);
                } else {
                    falta_dados();
                }
            break;

            case 5:
                if (quant_produtos) {
                    system("clear||cls");
                    imprimir_produtos(lista_Produtos, quant_produtos);
                    pausa();
                } else {
                    falta_dados();
                }
            break;

            case 6:
                if (quant_vendas) {
                    relatorio_faturamento(vendas_prod, quant_vendas);
                }else{
                    falta_dados();
                }
            break;
        }
    } while (opcao != 0);
    limpar_memoria(vendas_prod, quant_vendas, lista_Produtos);
    despedida();
}