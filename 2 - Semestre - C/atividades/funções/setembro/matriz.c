#include <stdio.h>
#include <stdlib.h>

int **criarMatriz(int a, int l);
int **criarTransposta(int **mat, int a, int l); // Declara a função criarMatriz
void imprimir(int **mat, int alt, int lar);
void maiorNum(int **mat, int alt, int lar);

int main() {
    int **matriz, **transposta, m, n;

    printf("Insira a altura da matriz: ");
    scanf("%d%*c", &m); 
    printf("Insira a largura da matriz: ");
    scanf("%d%*c", &n);
    
    printf("\t\t\tMATRIZ\n\n");
    matriz = criarMatriz(m, n);

    printf("\n\n\t\t\tMATRIZ\n\n");
    imprimir(matriz, m, n);
    maiorNum(matriz, m, n);
    printf("\n\n\t\t\tMATRIZ TRANSPOSTA\n\n");
    transposta = criarTransposta(matriz, n, m);
    imprimir(transposta, n, m);

    for (int i = 0; i < m; i++) {
        free(matriz[i]);
    }

    for (int i = 0; i < n; i++) {
        free(transposta[i]);
    }
    printf("\n\n");

    free(transposta);
    free(matriz);
    return 0;
}

int **criarMatriz(int a, int l) {
    int **matriz = calloc(a , sizeof(int *));
    for (int i = 0; i < a; i++) {
        matriz[i] = (int *)calloc(l , sizeof(int));
    }

    for (int i = 0; i < a; i++) {
        for (int j = 0; j < l; j++) {
            printf("Insira uma valor para a posição [%d][%d]: ", i+1, j+1);
            scanf("%d%*c", &matriz[i][j]);
        }
    }
    return matriz; // Retorna o ponteiro para a matriz alocada
}

int **criarTransposta(int **mat, int a, int l) {
    int **matriz = calloc(a , sizeof(int *));
    for (int i = 0; i < a; i++) {
        matriz[i] = (int *)calloc(l , sizeof(int));
    }

    for (int i = 0; i < a; i++) {
        for (int j = 0; j < l; j++) {
            matriz[i][j] = mat[j][i];
        }
    }
    return matriz; // Retorna o ponteiro para a matriz alocada
}

void imprimir(int **mat, int alt, int lar){
    for (int i = 0, a = 0; i < alt; i++) {
        printf("|");
        for (int j = 0; j < lar; j++) {
            printf(" %2d  |", mat[i][j]);
        }
        printf("\n");
    }
}

void maiorNum(int **mat, int alt, int lar){
    int *maior;
    maior = (int *) calloc(3, sizeof(int));
    for(int i = 0; i < alt; i++){
        for(int j = 0; j < lar; j++){
            for(int cont = 0; cont < 3; cont++){
                if(mat[i][j]>maior[cont]){
                    if (maior[cont+1]){
                        for (int p = 2; p > cont; p--){
                            maior[p] = maior[p-1];
                        }
                    }else{
                        maior[cont+1] = maior[cont];
                        maior[cont] = mat[i][j];
                    }
                    maior[cont] = mat[i][j];
                    break;
                }
            }
        }
    }

    for(int i = 0; i < alt; i++){
        for(int j = 0; j < lar; j++){
            for (int cont = 0; cont < 3; cont++){
                if(maior[cont] == mat[i][j]){
                    printf("Maior [%d][%d]: %d\n", i+1, j+1, mat[i][j]);
                }
            }
        }
    }
} 