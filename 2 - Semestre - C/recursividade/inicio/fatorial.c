#include <stdio.h>
#include <stdlib.h>

int somatorio(int n){
    if(n == 1){
        return n;
    }
    return n*n + somatorio(n-1);
}

int main(){
    
    printf("\n\nSomatório: %d\n\n", somatorio(4));
    printf("\n\n");
}