#include <stdio.h>

float somatorio(int n);

int main(){
    int n = 5;
    printf("Somatório: %.2f\n\n", somatorio(n));
}

float somatorio(int n){
    if (n==1){
        return n;
    }
    return (float)1/n + somatorio(n-1);
}