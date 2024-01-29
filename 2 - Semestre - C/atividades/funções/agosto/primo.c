#include <stdio.h>
#include <stdlib.h>

int primo(int num){
    
    for (int i = 2; i < num; i++){
        if (num % i == 0){
            return 0;
        }
    }
    return 1;
}

int main(){
    int number;

    printf("Insira um valor: ");
    scanf("%d%*c", &number);
    
    (primo(number)) ? printf("Número é primo!!\n\n"):printf("Número não é primo!!\n\n");
}