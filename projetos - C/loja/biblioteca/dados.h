#ifndef DADOS_H
#define DADOS_H
//PRODUTO
typedef struct {
    int cod, estoque;
    char desc[100];
    float preco;
    float preco_estoque;
} PRODUTO;

//VENDAS

typedef struct {
    int quantidade_produtos;
    int codigoVenda;
    int dia;
    int mes;
    int ano;
    int hora;
    int minutos;
    int segundos;
    float preco_venda;
    PRODUTO *itemvenda;
} VENDA;

#endif // BIBLIOTECA_LOJA_H