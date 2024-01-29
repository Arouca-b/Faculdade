/*Você foi contratado para desenvolver um programa em linguagem C para um instituto de pesquisa e estatística. Eles intencionam com a sua contratação acelerar a análise dos dados, através da automatização dos cálculos da moda. Definição de Moda: é o valor que mais aparece num conjunto de dados; considerando este conjunto de entradas como exemplo {12, 11, 12, 13, 12, 11, 13, 12, 12, 11, 14, 13, 13, 12, 11, 12}, a moda é 12, pois é o valor que aparece mais vezes no conjunto. Considerar amostras de 14 elementos inteiros*/

#include <stdio.h>

int main(){
    int val[16] = {12, 11, 12, 13, 12, 11, 13, 12, 12, 11, 14, 13, 13, 12, 11, 12}, moda = 0, pete = 0, repete = 0;

    /*for (int i = 0; i < 16; i++){
        printf("Insira um valor para o elemento [%d]: ", i);
        scanf("%d%*c", &val[i]);
    }*/


    //navegar pelo vetor
    for (int i = 0; i < 16; i++){
        /*fazer comparação com todos os elementos do mesmo vetor
        nesse caso eu vou travar um elemento e ir fazendo a comparação com todos os outros*/

        for (int j = 0; j < 16; j++){
            /*se os dois valores forem iguais, ele vai dizer que o número repete e vai somar +1 para indicar a quantidade de vezes que ele repete*/

            if (val[i] == val[j]){
                pete++;
            }
        }
        
        /*ele vai sair do segundo for e fazer a comparação para achar a maior quantidade de repetições

        ex: 11 repetiu 4 vezes
               pete = 4; 
               repete = pete;
               moda = val[i](11) 
               moda vai pegar o número que repete 4x*/ 

        // moda só vai ser diferente de 11 caso pete >= repete, algum número repite 4 ou mais vezes
        if (pete>repete){
            repete = pete;
            moda = val[i];
        }
        /*aqui é para quando for passar para o próximo elemento do primeiro for, após comparar 1 elemento com todos os outros ele passa para o próximo elemento e a gente zera para repetir o processo*/
        pete = 0;
    }
    printf("Moda: %d\n\n", moda);
}