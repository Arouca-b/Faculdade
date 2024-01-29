#include <stdio.h>

int main(void) {
    float f;
    printf("Digite um número real: ");
    scanf("%f", &f);
   	printf("\nParte Inteira : %d",(int) f);
   	printf("\nParte Decimal : %.2f\n", f - (int) f);
}