#include <stdio.h>
#define MAX 2
int main(){
    float sal_min,sal[MAX], n_sal[MAX], per[MAX], folha = 0, n_folha = 0;
    char nome[MAX][30];
    
    printf("Digite o valor do salário mínimo: R$");
    scanf("%f", &sal_min);

    for(int i = 0; i < MAX; i++){
        printf("\nNome funcionário: ");
        scanf("%s", nome[i]);
        printf("Salário do cliente: R$");
        scanf("%f", &sal[i]);
        folha = folha + sal[i];

        if ( 3*sal_min > sal[i])
        {
            n_sal[i] = sal[i] * 1.5; 
            per[i]=50;
        }else if (sal[i] >= 3*sal_min && sal[i]<= 10*sal_min)
        {
            n_sal[i] = sal[i] * 1.2;
            per[i]=20;
        }else if (sal[i] > 10*sal_min && sal[i] <= 20*sal_min)
        {
            n_sal[i] = sal[i] * 1.15;
            per[i]=15;
        }else{
            n_sal[i] = sal[i] * 1.1;
            per[i]=10;
        }
        n_folha = n_folha + n_sal[i];
    }
    system("clear");
    
    n_folha = (n_folha/folha)*100;
    printf("\t\tAumento percentual da folha: %.1f%%\n", n_folha - 100);
    for(int i = 0; i < MAX; i++){
        printf("\nNome funcionário: %s", nome[i]);
        printf("\nSalário: R$%.2f", sal[i]);
        printf("\nNovo Salário: R$ %.1f", n_sal[i]);
        printf("\nAumento percentual: %.1f%%\n", per[i]);
    }

}