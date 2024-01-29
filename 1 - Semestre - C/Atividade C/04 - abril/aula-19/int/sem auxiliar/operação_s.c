#include <stdio.h>

int main(){
    int num1, num2;

    printf("\n\tDigite 2 números: ");
    scanf("%d", &num1);
    scanf("%d", &num2);

    printf("\n\t%d + %d = %d\n", num1, num2, num1 + num2); 
    printf("\t%d - %d = %d\n", num1, num2, num1 - num2);
    printf("\t%d * %d = %d\n", num1, num2, num1 * num2);
    printf("\t%d / %d = %d\n", num1, num2, num1 / num2);
}