/*
6. Escreva um programa que leia uma matriz de 6x6 de números inteiros
e descubra se tem algum número que mais se repete.
*/
#include <stdio.h>

#define NLIN 2
#define NCOL 2

int main(void){
    int matriz[NLIN][NCOL] = {0}, maxFreq = 0, freq = -1,moda = 0, j = 0, i = 0, *m;

    printf("\n\tInforme os elementos da matriz\n\tOBS: Preencher somente com"
           "numeros inteiros.\n\n");
    for(int lin = 0; lin < NLIN; lin++){
        for(int col = 0; col < NCOL; col++){
           printf("\tElemento [%d][%d]: ", lin+1, col+1);
           scanf("%d%*c", &matriz[lin][col]);
        }
    }
    m = &matriz;
    printf("%d", *m);
    for(i = 0; i < NLIN * NCOL; i++){
        for(j = 0; j < NLIN * NCOL; j++){
            if(*(m+i) == *(m+j)){
                freq++;
            }
        }

        if(freq > maxFreq){
            maxFreq = freq;
            moda = *(m+i);
        }
        freq = -1;
    }

    (maxFreq == 0) ?  printf("\n\nNão existe numero que mais se repete\n\n") :
        printf("\n\nNumero que mais se repete: %d\n\n", moda);


    return 0;
}