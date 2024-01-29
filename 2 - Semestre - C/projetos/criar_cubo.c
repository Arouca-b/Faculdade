#include <stdio.h>
#include <stdlib.h>
#define TAM 3
#define n_max 10
int matriz[TAM][TAM] = {0};

void imprimir_m(int *c_media){
    for (int linha = 0; linha < TAM; linha++){
        printf("\t\t| ");
        for (int coluna = 0; coluna < TAM; coluna++){
            *c_media += matriz[linha][coluna];
            printf(" %d |", matriz[linha][coluna]);
        }
        printf("\n");
    }
    printf("\n\n");
    *c_media/=9;
}

int verifica(){
    int soma_dp = 0, soma_ds = 0;
    
    for (int i = 0; i < TAM; i++) {
        soma_dp += matriz[i][i];
        soma_ds += matriz[i][TAM - 1 - i];
    }
    if (soma_dp != soma_ds) {
        return 0;
    }
    for (int linha = 0; linha < TAM; linha++) {
        int soma_linha = 0, soma_coluna = 0;
        for (int coluna = 0; coluna < TAM; coluna++) {
            soma_linha += matriz[linha][coluna];
            soma_coluna += matriz[coluna][linha];
        }
        if (soma_linha != soma_dp || soma_coluna != soma_dp) {
            return 0;
        }
    }
    return 1;
}

int main(){
    int quant_cubos = 0, media = 0, fixo = 0;
    
    do{
        media = 0;
        for (fixo=0; fixo < n_max; fixo++){
            if (matriz[0][0] == 9){
                matriz[0][1]++;
            }
            matriz[0][0] = fixo;
            for (int linha = 0; linha <TAM; linha++){
                for (int coluna = 0; coluna < TAM; coluna++){
                    if (linha && coluna==0){
                        if (matriz[linha - 1][coluna + 2] > 9){
                            matriz[linha][coluna]++;
                            matriz[linha - 1][coluna + 2] = 0;
                        }
                    }else if(coluna){
                            if(matriz[linha][coluna-1] > 9){
                                    matriz[linha][coluna-1] = 0;
                                    matriz[linha][coluna]++;
                            }
                        }
                }
            }
            if (verifica()){
                quant_cubos++;
                imprimir_m(&media);
            }
        }      
    }while (media != 9);

    printf("Quantidade de cubos magicos encontrados : %d\n\n", quant_cubos);

    return 0;
}