#include <stdio.h>

int main(){
    int num, num2, expo;
    float poten = 1;
    printf("\n\t\tInsira 2 números(base, expoente): ");
    scanf("%d %d", &num, &num2);
    expo = num2;
    if (num2 == 0)
    {
        printf("\t\t%d ^ %d = 1\n", num, num2);
    }else{
        while (expo != 0){
            if (expo > 0){
                poten = poten * num;
                expo = expo - 1; 
            }else if(expo < 0){
                poten = poten / num;
                expo = expo + 1; 
            }
        }
        printf("\t\t%d ^ %d = %.2f\n", num, num2, poten);
    }
    return 0;
}