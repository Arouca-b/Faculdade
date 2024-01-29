// 7. Escreva uma função recursiva para encontrar o comprimento de uma string (utilizando ponteiros).
/*    Implemente uma função recursiva para calcular a sequência de Fibonacci.
    Crie uma função recursiva para verificar se uma string é um palíndromo.*/
#include <stdlib.h>
#include <stdio.h>

int tam_string(char *text, int n){
    if (text[n] == '\0'){
        return n;
    }
    return tam_string(text, n+1);
}

int fibb(int num){
    if (num == 0 || num < 0){
        return 0;
    }else{
        if (num-2 >=0){
            return fibb(num-2) + fibb(num-1); 
        }else{
            return 1;
        }
    }
    
}

int verifica_palindromo(char *text, int tam, int inicio, int valid){
    if (tam <= inicio){
        return 1;
    }
    if((text[tam-1] == text[inicio])){
        return verifica_palindromo(text, tam-1, inicio+1, valid);
    }else{
        return 0;        
    }
}

int main(){
    char *mat = (char*) malloc(20 * sizeof(char));
    printf("Insira texto: ");
    scanf("%[^\n]%*c", mat);
    int n = tam_string(mat,0);
    printf("Tam string: %d\n\n", n);
    if (verifica_palindromo(mat, n, 0, 1) == 1){
        printf("%s é um palíndromo!!\n\n", mat);
    }else{
        printf("%s não é um palíndromo!!\n\n", mat);
    }   
}