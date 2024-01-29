#include "vendas.h"
#include "mensagens.h"
#include "produto.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//FUNÇÕES VENDAS

VENDA *alocar_espaco_vendas(){// reservar Espaço para uma venda
    VENDA *prod1 = (VENDA *)malloc(sizeof(VENDA));
    if (prod1 == NULL) {
        exit(1);
    }
    prod1->itemvenda = alocar_espaco_produtos(); //reservar espaço para um produto
    return prod1;
}

VENDA *realocar_espaco_vendas(VENDA *prod2, int quant) { // Realocação de espaço do vetor, aumentar
// para inserir mais vendas
    prod2 = realloc(prod2, (quant + 1) * sizeof(VENDA));
    if (prod2 == NULL) {
        exit(1);
    }
    return prod2;
}

//Função para efetuar Vendas
VENDA *venda_de_produto(VENDA *sistema_compras, int *quantidade_vendas, PRODUTO *produtos, int quantidade_produtos) {
    pre_venda(produtos, quantidade_produtos);
    if (*quantidade_vendas > 0) {
        sistema_compras = realocar_espaco_vendas(sistema_compras, *quantidade_vendas);
    }
    sistema_compras[(*quantidade_vendas)] = concluir_venda(sistema_compras[(*quantidade_vendas)], *quantidade_vendas);
    (*quantidade_vendas)++;
    salva_venda(sistema_compras, *quantidade_vendas);
    system("clear||cls");
    printf("\n\n\t\t\t\tVENDA EFETUADA COM SUCESSO!\n\n");
    pausa();
    return sistema_compras;
}

//Função que serve como carrinho, escolher os produtos 
void pre_venda(PRODUTO *lista_produtos, int quantidade_produtos){
    int cod = 0, indice_produto = 0, comprar = 1, q_item = 0, quant_itens_comprados = 0;
    float VALOR_TOTAL = 0;
    PRODUTO *produtos_cliente = alocar_espaco_produtos();

    system("clear||cls");
    while (comprar) {
        printf("\n\t\t\tSISTEMA DE VENDAS\n\n");

        printf("Código do produto: ");
        scanf("%d%*c", &cod);
        fflush(stdin);
        indice_produto = procurar_produto(cod, lista_produtos, quantidade_produtos);
        if (indice_produto != -1) {
            do {
                printf("Produto: %s\n", lista_produtos[indice_produto].desc);
                printf("Quantidade: ");
                scanf("%d%*c", &q_item);
                if (q_item <= 0) {
                printf("\n\n\n\t\tInsira um valor válido\n\n");
                }
            } while (q_item <= 0);

            if (quant_itens_comprados) {
                produtos_cliente = realocar_espaco_produtos(produtos_cliente, quant_itens_comprados); // Aumentar tamanho da quant produtos
            }
            produtos_cliente[quant_itens_comprados] = lista_produtos[indice_produto];

            lista_produtos[indice_produto].estoque -= q_item;//diminuir estoque da lista de produtos

            lista_produtos[indice_produto].Item = lista_produtos[indice_produto].estoque * lista_produtos[indice_produto].preco; //novo preco ITEM

            produtos_cliente[quant_itens_comprados].estoque = q_item;
            produtos_cliente[quant_itens_comprados].Item = q_item * lista_produtos[indice_produto].preco;
            salvar_lista_produtos(lista_produtos, quantidade_produtos);
            VALOR_TOTAL += produtos_cliente[quant_itens_comprados].preco * q_item;
            quant_itens_comprados++;

            system("clear||cls");
            imprimir_produtos(produtos_cliente, quant_itens_comprados);
            printf("\n\nVALOR TOTAL \t\t\t\t\t\tR$ %.2f\n\n\n", VALOR_TOTAL);
            salva_pre_venda(produtos_cliente, quant_itens_comprados, VALOR_TOTAL);
            printf("\n\n(1 - Sim) (0 - Não) \nTem mais produtos:  ");
            scanf("%d%*c", &comprar);
            fflush(stdin);
            fflush(stdout);
            system("clear||cls");
        } else {
            system("clear||cls");
            printf("\t\t\tPRODUTO NÃO ENCONTRADO\n\n\n");
            printf("\t\t\t\tInsira um código válido\n\n");
            pausa();
        }
    }
    if (quant_itens_comprados) {
        free(produtos_cliente);//limpar "carrinho" já foi salvo em arquivo então pode limpar
    }
}

void salva_pre_venda(PRODUTO *produtos_comprados, int quantidade, float valor_total) { // SALVAR PRODUTOS ESCOLHIDOS
    FILE *arquivo = fopen("preVenda.txt", "wb");
    fwrite(&quantidade, sizeof(int), 1, arquivo);
    fwrite(produtos_comprados, sizeof(PRODUTO), quantidade, arquivo);
    fwrite(&valor_total, sizeof(float), 1, arquivo);
    fclose(arquivo);
}

VENDA concluir_venda(VENDA venda_efetuada, int codigo_venda){ // RESGATA OS PRODUTOS ESCOLHIDOS DO ARQUIVO Prevenda
    FILE *preVenda;
    int produtos_comprados;
    time_t currentTime;
    struct tm *localTime;
    currentTime = time(NULL);
    localTime = localtime(&currentTime);

    preVenda = fopen("preVenda.txt", "rb");
    fread(&produtos_comprados, sizeof(int), 1, preVenda);
    venda_efetuada.itemvenda = realocar_espaco_produtos(venda_efetuada.itemvenda, produtos_comprados - 1);
    fread(venda_efetuada.itemvenda, sizeof(PRODUTO), produtos_comprados, preVenda);
    venda_efetuada.quantidade_produtos = produtos_comprados;
    fread(&venda_efetuada.preco_venda, sizeof(float), 1, preVenda);
    fclose(preVenda);

    venda_efetuada.hora = localTime->tm_hour;
    venda_efetuada.minutos = localTime->tm_min;
    venda_efetuada.segundos = localTime->tm_sec;
    venda_efetuada.dia = localTime->tm_mday;
    venda_efetuada.mes = localTime->tm_mon + 1;
    venda_efetuada.ano = localTime->tm_year + 1900;
    venda_efetuada.codigoVenda = codigo_venda+1;

    // zerando o conteudo do arquivo preVenda que não é necessário
    remove("preVenda.txt");
    
    return venda_efetuada;
}

void salva_venda(VENDA *historico_vendas, int quantidade_vendas) { //Salva Venda
    FILE *fp = fopen("historico_vendas.txt", "wb");
    if (fp == NULL) {
        perror("Erro ao abrir o arquivo historico_vendas.txt");
        exit(1);
    }

    fwrite(&quantidade_vendas, sizeof(int), 1, fp);//Quantidade de vendas registradas

    for (int i = 0; i < quantidade_vendas; i++) {
        fwrite(&historico_vendas[i], sizeof(VENDA) - sizeof(PRODUTO *), 1, fp);//vendas
        //Salva os produtos da venda em análise
        fwrite(historico_vendas[i].itemvenda, sizeof(PRODUTO), historico_vendas[i].quantidade_produtos, fp);
    }

    fclose(fp);
}

VENDA *recupera_historico_vendas(VENDA *historico_vendas, int *quantidade_vendas) {
    FILE *fp = fopen("historico_vendas.txt", "rb");
    if (fp == NULL){
        return alocar_espaco_vendas();
    }

    fread(quantidade_vendas, sizeof(int), 1, fp);//quantidade de vendas

    historico_vendas = realocar_espaco_vendas(historico_vendas, *quantidade_vendas);//alocar tamanho para armazenar os dados de vendas

    for (int i = 0; i < *quantidade_vendas; i++) {
        fread(&historico_vendas[i], sizeof(VENDA) - sizeof(PRODUTO *), 1, fp);//salvar uma venda de cada vez
        historico_vendas[i].itemvenda = alocar_espaco_produtos();
        // Aloca espaço para os produtos, pois não alocado no realocar_espaco_vendas

        historico_vendas[i].itemvenda = realocar_espaco_produtos(historico_vendas[i].itemvenda, historico_vendas[i].quantidade_produtos);
        //poderia substituir isso pelo malloc(sizeof(PRODUTO) * historico_vendas[i].quantidade_produtos)

        // Lê os produtos individualmente
        fread(historico_vendas[i].itemvenda, sizeof(PRODUTO), historico_vendas[i].quantidade_produtos, fp);
    }

    fclose(fp);
    return historico_vendas;
}

void relatorio_faturamento(VENDA *vendas, int quant_vendas) { // IMPRIMIR TODAS AS VENDAS E VALOR ARRECADADO NO MÊS
    int mes, ano;
    float faturamentoMes = 0;
    system("clear||cls");
    printf("\t\t\t\tFATURAMENTO MENSAL\n\n\n");
    printf("Insira o mês e o ano que deseja verificar (ex: 06 2023): ");
    scanf("%d%*c%d%*c", &mes, &ano);
    system("clear||cls");
    printf("\t\t\t\tFATURAMENTO %d/%d\n\n\n", mes, ano);
    for (int i = 0; i < quant_vendas; i++) {
        if (vendas[i].mes == mes && vendas[i].ano == ano){
            imprimir_vendas(vendas[i]);
            faturamentoMes += vendas[i].preco_venda;
        }
    }
    printf("\n\nTOTAL ARRECADADO MÊS %d/%d                         R$ %.2f\n\n", mes, ano, faturamentoMes);
    pausa();
    system("clear||cls");
}

void imprimir_vendas(VENDA vendas) { // IMPRIMIR VENDAS REALIZADAS
    printf("\n\nCódigo Venda: %d\n", vendas.codigoVenda);
    printf("\nHorário: %2d:%2d:%2d\n"
    "Data: %2d/%2d/%2d\n", vendas.hora, vendas.minutos,
            vendas.segundos, vendas.dia, vendas.mes, vendas.ano);
    printf("\nVALOR\t\t\tR$ %.2f\n\n", vendas.preco_venda);
    printf("__________________________________________________");
}
//FIM VENDAS