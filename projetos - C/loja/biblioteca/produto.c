#include "produto.h"
#include <stdio.h>
#include <stdlib.h>
#include "mensagens.h"

//FUNÇÕES DE PRODUTOS
PRODUTO *alocar_espaco_produtos(){ 
    PRODUTO *prod1 = (PRODUTO *)malloc(sizeof(PRODUTO));
    if (prod1 == NULL) {
        exit(1);
    }
    return prod1;
}

PRODUTO *realocar_espaco_produtos(PRODUTO *prod2, int quant) {
    prod2 = realloc(prod2, (quant + 1) * sizeof(PRODUTO));
    if (prod2 == NULL) {
        exit(1);
    }
    return prod2;
}
// FIM ALOCAÇÃO DE MEMÓRIA

PRODUTO *inserir_prod(int *quant, PRODUTO *prod1) { // Inserir novos produtos
    int indice = *quant, cod = 0;
    int verifica_duplicidade = 0;
    PRODUTO *novo = alocar_espaco_produtos();

    system("clear||cls");
    printf("\t\t\t\tNOVO PRODUTO\n\n");

    printf("Código: ");
    scanf("%d%*c", &cod);
    fflush(stdout);
    fflush(stdin);
    verifica_duplicidade = procurar_produto(cod, prod1, *quant);
    while (verifica_duplicidade != -1){ //VERIFICAR SE JÁ EXISTE UM PRODUTO COM CÓDIGO
        system("clear||cls");
        printf("\n\n\t\t\t\tCódigo já utilizado\n\n");
        printf("\t\t\t\tNOVO PRODUTO\n\n");
        printf("Código: ");
        scanf("%d%*c", &cod);
        verifica_duplicidade = procurar_produto(cod, prod1, *quant);
    }
    novo->cod = cod;
    printf("Nome produto: ");
    scanf("%99[^\n]", novo->desc);
    fflush(stdin);
    // receber valor estoque
    printf("Estoque: ");
    scanf("%d%*c", &novo->estoque);

    printf("Preço: R$ ");
    scanf("%f", &novo->preco);
    novo->Item = novo->preco * novo->estoque;
    fflush(stdin);
    system("clear||cls");
    prod1 = ordenar_produtos(prod1, novo, indice);
    (*quant)++;
    system("clear||cls");
    printf("\n\n\t\t\tPRODUTO CADASTRADO COM SUCESSO!\n\n");
    pausa();

    return prod1;
}

//ordenar caso cliente insira os códigos do poduto
PRODUTO *ordenar_produtos(PRODUTO *origem, PRODUTO *novo,int quant) { // ordenar produtos pelo código
    int i = 0;
    if (quant == 0) {
        origem = novo;
    } else {
        while (i < quant) {
            if (origem[i].cod > novo->cod) {
                break;
            }
            i++;
        }
        origem = realocar_espaco_produtos(origem, quant);

        while (quant > i) {
            origem[quant] = origem[quant - 1];
            quant--;
        }
        origem[i] = *novo;
    }
    return origem;
}

void imprimir_produtos(PRODUTO *produtos, int quant) { // IMPRIMIR TODOS OS PRODUTOS
    printf("\n\t\t\tLISTA DE PRODUTOS\n\n");
    printf("%12s", " Código | ");
    printf("%20s", "Descrição   | ");
    printf("%12s", "Quantidade | ");
    printf("%12s", "Preço unt | ");
    printf("%12s", "Preço\n");
    for (int i = 0; i < quant; i++) {
        printf("%6d", produtos[i].cod);
        printf("%15s", produtos[i].desc);
        printf("%13d", produtos[i].estoque);
        printf("%15.2f", produtos[i].preco);
        printf("%15.2f\n", produtos[i].Item);
    }
}

void atualizar_estoque(PRODUTO *produtos, int quant) { //ATUALIZAR QUANTIDADE DE ESTOQUE, SOMANDO OU DIMINUIDO
    int cod, posicao_produto, op = 0, estoque;
    system("clear||cls");
    printf("\t\t\tATUALIZAÇÃO DE ESTOQUE\n\n");
    printf("Código produto: ");
    scanf("%d%*c", &cod);
    posicao_produto = procurar_produto(cod, produtos, quant); 
    if (posicao_produto != -1) {
        printf("\n1. Inserir itens\n");
        printf("2. Excluir itens\n\n");
        scanf("%d%*c", &op);
        system("clear||cls");
        printf("\t\t\tATUALIZAÇÃO DE ESTOQUE\n\n");
        printf("Produto: %s\n", produtos[posicao_produto].desc);
        printf("Estoque: %d\n", produtos[posicao_produto].estoque);
        if (op == 1) {
            printf("\nQuantos itens inserir no estoque: ");
            scanf("%d%*c", &estoque);
            produtos[posicao_produto].estoque += estoque;
        }else {
            if (op == 2) {
                printf("\nQuantos itens retirar do estoque: ");
                scanf("%d%*c", &estoque);
                produtos[posicao_produto].estoque -= estoque;
            }
        }
    } else {
        erro(); // Caso não ache o produto no banco de dados
    }
    system("clear||cls");
    salvar_lista_produtos(produtos, quant);
}

int procurar_produto(int cod, PRODUTO *prod2, int quant){//PROCURAR DETERMINADO PRODUTO NO ESTOQUE
    for (int posicao = 0; posicao < quant; posicao++) {
        if (prod2[posicao].cod == cod) {
            return posicao;
        }
    }
    return -1;
}

void consultar_preco(PRODUTO *produto, int quant_produtos) { // PESQUISA PRODUTO E IMPRIME O PREÇO
    int cod, posicao = 0;
    system("clear||cls");
    printf("\t\t\t\tCONSULTA PREÇO\n\n\n");
    printf("Insira Código do produto: ");
    scanf("%d%*c", &cod);
    posicao = procurar_produto(cod, produto, quant_produtos);
    if (posicao != -1) {
        system("clear||cls");
        printf("\t\t\t\tCONSULTA PREÇO\n\n\n");
        printf("%12s", " Código | ");
        printf("%20s", "Descrição   | ");
        printf("%12s", "Estoque | ");
        printf("%12s", "Preço unt\n");
        printf("%6d", produto[posicao].cod);
        printf("%15s", produto[posicao].desc);
        printf("%13d", produto[posicao].estoque);
        printf("%15.2f\n\n\n", produto[posicao].preco);
        pausa();
    } else {
        erro();
    }
}

void salvar_lista_produtos(PRODUTO *produtos, int quant_produtos) { // SALVAR A LISTA DE PRODUTOS DO MERCADO
    FILE *fp;
    fp = fopen("listaProdutos.txt", "wb");
    fwrite(&quant_produtos, sizeof(int), 1, fp);    //quantidade de protudos no BD
    fwrite(produtos, sizeof(PRODUTO), quant_produtos, fp); //produtos
    fclose(fp);
}

//Caso tehha um problema na venda, todos os produtos volta para o estoque
PRODUTO *recuperar_estoque_preVenda(PRODUTO* lista_produtos, int quantidade_l, PRODUTO* lista_preVenda, int quantidade_preVenda){
    int indice, cod;
    for (int i = 0; i < quantidade_preVenda; i++){
        cod = lista_preVenda[i].cod;
        indice = procurar_produto(cod, lista_produtos, quantidade_l);
        lista_produtos[indice].estoque += lista_preVenda[i].estoque;
    }
    return lista_produtos;
}

PRODUTO *recupera_lista_produtos(PRODUTO *produtos, int *quant_produtos){ // RECUPERAR DADOS DA LISTA DE PRODUTOS
    FILE *fp;
    FILE *pre_venda;
    PRODUTO *repor_vendas_nao_concluidas = alocar_espaco_produtos();
    int quant_pre_venda = 0;


    fp = fopen("listaProdutos.txt", "rb");
    if(fp == NULL) { //se não existir lista de produto
        return alocar_espaco_produtos();//alocar 1 espaço
    }
    fread(quant_produtos, sizeof(int), 1, fp);//quantidade de produtos
    produtos = realocar_espaco_produtos(produtos, (*quant_produtos) - 1);//realocar memória para armazenar todos esses produtos
    
    fread(produtos, sizeof(PRODUTO), *quant_produtos, fp);
    fclose(fp);

    
    pre_venda = fopen("preVenda.txt", "rb");
    if (pre_venda == NULL){
        free(repor_vendas_nao_concluidas);
        return produtos;
    }
    fread(&quant_pre_venda, sizeof(int), 1, pre_venda);
    repor_vendas_nao_concluidas = realocar_espaco_produtos(repor_vendas_nao_concluidas, quant_pre_venda-1);
    fread(repor_vendas_nao_concluidas, sizeof(PRODUTO), quant_pre_venda, pre_venda);
    produtos = recuperar_estoque_preVenda(produtos, *quant_produtos, repor_vendas_nao_concluidas, quant_pre_venda);
    free(repor_vendas_nao_concluidas);
    remove("preVenda.txt");
    return produtos;
}
// FIM PRODUTOS