#ifndef AROUCA_H
#define AROUCA_H

int** criar_matriz(int **mat, int lin, int col);
void imprimir(int **mat, int lin, int col);
int* som_lin(int **mat, int lin, int col);
int* som_col(int **mat, int lin, int col);
int diagonal_p(int **mat, int lin, int col);
int** c_trans(int **mat, int lin, int col);
int verifica_simetria(int **mat, int **mat2, int lin, int col);

//LISTA ENCADEADA

typedef struct lista_encadeada{
    int info;
    struct lista_encadeada *prox;
}LISTA;


LISTA* insere_ini(LISTA *ini, int n);
void insere_fim(LISTA *fim, int n);
LISTA* posicao(LISTA *fim);
LISTA* alocar_espaco();
LISTA* inicializar();
LISTA* ordenar(LISTA *ordem, int n);
LISTA* insere(LISTA *ordem, int n);
void imprimir_lista(LISTA *ordem);
LISTA* find(LISTA *ini, int n);
LISTA* insere_ini_rec(LISTA* vet, int n);
LISTA* insere_fim_rec(LISTA* ini, int n);

//OPERAÇÕES COM NÚMEROS

void tabuada(int x, int multiplicador);
int posicao_vet(int*vet, int tam, int n);



char* padronizar_nome(char* nome);
void insere_nome(char** nome);


#endif //AROUCA_H
