#include <stdio.h>
#include <stdlib.h>

int fatorialAux(int num, int fat){
    if(num==1 || num == 0){
        return fat;
    }
    fat *= num;
    return fatorialAux(num-1, fat); 
}

int fatorial(int n){
    return fatorialAux(n,1);
}

int main(){
    int n = 0;
    printf("Fatorial: %d\n\n", fatorial(n));
}