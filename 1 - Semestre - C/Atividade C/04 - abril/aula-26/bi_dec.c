#include <stdio.h>
int main(void){
    int potenc = 1, dec = 0, bin=0;
    printf("Digite um número binário: ");
    scanf("%d", &bin);
    while(bin>0){
        dec = dec + bin%10 * potenc;
        potenc = potenc * 2;
        bin = bin/10;
    }
    printf("Decimal: %d\n", dec);
    return 0;
}