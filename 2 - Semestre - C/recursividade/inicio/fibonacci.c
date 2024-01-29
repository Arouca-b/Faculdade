#include <stdio.h>
#include <stdlib.h>

int fib(int n){
    if (n == 0){
        return 0;
    }else{
        if(n-2 >=0){
            return fib(n-1) + fib(n-2);    
        }else{
            return 1;
        }
    }
}

void mostrar_fib(int n){
    if(n == 0){
        printf("0 ");
    }else{
        mostrar_fib(n-1);
        if(n-2 >=0){
            printf("%d ", fib(n-1) + fib(n-2));    
        }else{
            printf("1 ");
        }
    }
}

int main(){
    printf("\n\nfib: %d\n\n", fib(10));
    mostrar_fib(10);
    printf("\n\n");
}