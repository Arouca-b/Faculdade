#include <stdio.h>

int main(){
    int num[10], cont;
    printf("insira os valores para armazenar: ");
    for(cont = 0; cont<10; cont++){
        scanf("%d", &num[cont]);
    }
    printf("\n");
    for(cont = 9;cont>=0; --cont){
        printf("%d ", num[cont]);
    }
    printf("\n");
}
