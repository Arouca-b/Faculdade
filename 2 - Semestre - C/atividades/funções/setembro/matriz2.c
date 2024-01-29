#include <stdio.h>
#include <stdlib.h>

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
    printf("\n\t\t\t\tMATRIZ CRIADA COM SUCESSO!!");
    printf("\n\t\t\tPressione qualquer tecla para continuar!!\n");
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

//desalocar memória
void desaloca_m(int **mat,int tam){
    for (int i = 0; i < tam; i++){
        free(mat[i]);
    }
    free(mat);
}


int main(){
    int **A, **B, linha, coluna, *soma_l, *soma_c;

    printf("\t\t\t\tCRIADOR DE MATRIZ \n\n");
    printf("Insira a largura da matriz: ");
    scanf("%d%*c", &linha);
    printf("Insira a altura da matriz: ");
    scanf("%d%*c", &coluna);

    A = criar_matriz(A, linha, coluna);
    B = c_trans(A, linha, coluna);
    soma_l = som_lin(A, linha, coluna);
    printf("\n\t\t\tSOMA LINHA\n\n");
    for ( int i = 0; i < linha; i++){
        printf("\t%dº Linha = %2d\n",i+1 ,  soma_l[i]);
    }
    soma_c = som_col(A, linha, coluna);
    printf("\n\t\t\tSOMA COLUNA\n\n");
    for (int i = 0; i < coluna; i++){
        printf("\t%dº coluna = %2d\n", i+1, soma_c[i]);
    }
    if (!diagonal_p(A, linha, coluna)){
        printf("\nDiagonal Principal: Não existe!!\n");
    }else{
        printf("\nDiagonal Principal = %2d\n", diagonal_p(A, linha, coluna));
    }
    
    printf("\nSimétrica: ");
    (verifica_simetria(A, B, linha, coluna) == -1) ? printf("MATRIZ NÃO É QUADRADA!!\n\n\n") : (verifica_simetria(A, B, linha, coluna) == 1) ? printf("SIM!!\n\n\n") : printf("NÃO!!\n\n\n");
    printf("\n\t\tMATRIZ A: \n\n");
    imprimir(A, linha, coluna);
    
    printf("\n\n\t\tMATRIZ B: \n\n");
    imprimir(B, coluna, linha);
    printf("\n\n\n");
    desaloca_m(B, coluna);
    desaloca_m(A,linha);
    free(soma_c);
    free(soma_l);
}