/*  
    UNIVERSIDADE ESTADUAL DE SANTA CRUZ
    ALUNO: BRENO AROUCA
    DATA DE MOD: 14/10
    
*/

#include <stdio.h>
#include <stdlib.h>
#include "arouca.h"
//105 LISTA ENCADEADA


//função para criar uma matriz de n linha e m colunas
int** criar_matriz(int **mat, int lin, int col){
    int **mat2;
    mat2 = (int**) calloc(lin, sizeof(int*));

    for (int i = 0; i < lin; i++){
        mat2[i] = (int *) calloc(col, sizeof(int));
        for (int j = 0; j < col; j++){
            printf("\nInsira o valor para a posição [%d][%d]: ", i+1, j+1);
            scanf("%d%*c", &mat2[i][j]);
        }
    }
    system("clear||cls");
    printf("\n\t\t\tMATRIZ CRIADA COM SUCESSO!!");
    getchar();
    system("clear||cls");
    return mat2;
}

//Imprimir matrizes criadas
void imprimir(int **mat, int lin, int col){
    for (int i = 0; i < lin; i++){
        printf("\t\t\t|");
        for(int j = 0; j < col; j++){
            printf("  %2d  |", mat[i][j]);
        }
        printf("\n");
    }
}

//Soma das linhas da matriz e armazenar em vetor
int* som_lin(int **mat, int lin, int col){
    int *som_linha;
    som_linha = (int *) calloc(lin, sizeof(int));
    for (int i = 0; i < lin; i++){
        for (int j = 0; j < col; j++){
            som_linha[i] += mat[i][j];
        }   
    }
    return som_linha;
}

//Soma das colunas da matriz e armazenar em vetor
int* som_col(int **mat, int lin, int col){
    int *som_coluna;
    som_coluna = (int *) calloc(col, sizeof(int));    
    for (int i = 0; i < lin; i++){
        for (int j = 0; j < col; j++){
            som_coluna[j] += mat[i][j];
        }   
    }
    return som_coluna;
}

//soma da diagonal principal
int diagonal_p(int **mat, int lin, int col){
    int dp = 0;
    if (lin != col){
        return 0;
    }
    
    for (int i = 0; i < lin; i++){
        dp+= mat[i][i];
    }
    return dp;
}

//criar transposta da matriz
int** c_trans(int **mat, int lin, int col){
    int **mat2;
    mat2 = (int**) calloc(col, sizeof(int*));
    for ( int i = 0; i < col; i++){
        mat2[i] = (int*) calloc(lin, sizeof(int));
    }

    for (int i = 0; i < col; i++){
        for (int j = 0; j < lin; j++){
            mat2[i][j] = mat[j][i];
        }  
    }
    return mat2;
}

//verificar se a matriz é simétrica a uma outra matriz
int verifica_simetria(int **mat, int **mat2, int lin, int col){
    if (lin != col){
        return -1;
    }

    for ( int l = 0; l < lin; l++){
        for (int c = 0; c < col; c++){
            if (mat[l][c] != mat2[l][c]){
                return 0;
            }
        }
    }
    return 1;
}



                                            //LISTA ENCADEADA

void imprimir_lista(LISTA *ordem){
    printf("\n\n\t\t");
    for(LISTA *q = ordem; q != NULL; q = q->prox){
        printf("%d -> ", q->info);
    }
    printf("NULL\n\n");
}

LISTA* inicializar(){
    return NULL;
}

LISTA* alocar_espaco(){
    LISTA* l =  (LISTA*) malloc(sizeof(LISTA));
    if (l == NULL){
        exit(1);
    }
    return l;
}

//Insere ELemento
LISTA* insere_ini(LISTA *ini, int n){
    LISTA* novo = alocar_espaco();
    novo->info = n;
    novo->prox = ini;
    return novo;
}

LISTA* insere_ini_rec(LISTA* vet, int n){
    LISTA* ab = (LISTA*) malloc(sizeof(LISTA));
    if (ab != NULL){
        ab->info = n;
        ab->prox = vet;
    }else{
        exit(1);
    }
    return ab;
} 

void insere_fim(LISTA *fim, int n){
    LISTA* final = alocar_espaco();
    LISTA* anterior = posicao(fim);
    anterior->prox = final;
    final->info = n;
    final->prox = NULL;
}

LISTA* insere(LISTA *ordem, int n){
    LISTA *q = ordem;
    LISTA *ant = q;
    LISTA* posicao = alocar_espaco();

    if (q->info > n){
        return insere_ini(ordem, n);
    }
    
    while(q->info < n && q->prox != NULL){
        ant = q;
        q = q->prox;
    }
    
    if (q->info < n && q->prox == NULL){
        insere_fim(ordem, n);
        return ordem;
    }
    posicao->info = n;
    ant->prox = posicao;
    posicao->prox = q;
    return ordem;
}

LISTA* insere_fim_rec(LISTA* ini, int n){
    if (ini == NULL){
        LISTA* novo = (LISTA*) malloc(sizeof(LISTA));
        novo->info = n;
        novo->prox = ini;
        return novo;
    }else{
         ini->prox = insere_fim_rec(ini->prox, n);
         return ini;
    }
}//Fim insere elemento


//PROCURAR ELEMENTO

LISTA* find(LISTA* ini, int n){
    if (ini == NULL){
        return NULL;
    }
    if (ini->info == n){
        return ini;
    }
    return find(ini->prox, n);
}

LISTA* posicao(LISTA *fim){
    LISTA* POS = fim;
    for(; POS->prox != NULL; POS = POS->prox);
    return POS;
}

int posicao_vet(int*vet, int tam, int n){
    if (vet[tam-1] != n && tam == 0){
        return -1;
    }
    if (vet[tam-1] == n){
        return tam-1;
    }
    posicao_vet(vet, tam-1, n);
}//FIM

LISTA* ordenar(LISTA *ordem, int n){
    if (ordem == NULL){
        ordem = insere_ini(ordem, n);
    }else if(ordem->prox == NULL){
            if(ordem->info < n){
                insere_fim(ordem, n);
            }else{
                ordem = insere_ini(ordem, n);
            }
        }else{
            ordem = insere(ordem, n);
        }
    return ordem;
}



//                          TABUADA RECURSIVA

void tabuada(int x, int multiplicador){
    if (multiplicador < 10){
        tabuada(x, multiplicador+1);
    }
    printf("%d * %d = %d\n", x, multiplicador, x*multiplicador);
}