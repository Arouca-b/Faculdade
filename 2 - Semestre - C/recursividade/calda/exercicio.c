#include <stdio.h>
#include <stdlib.h>

//SEM CALDA

int resul_som(int a, int b){
    if (b == 1){
        return a;
    }
    return a + resul_som(a, b-1);
}

int Max_s(int *vet, int tam){
    if (tam == 1){
        return vet[0];
    }else{
        if(vet[tam-1] >= Max_s(vet, tam-1)){
            return vet[tam-1];
        }
        return Max_s(vet, tam-1);
    }   
}
//FIM SEM CALDA

//COM CALDA
int mult_soma_aux(int a, int b, int soma){
    if (!b){
        return soma;
    }
    return mult_soma_aux(a,b-1,soma += a);
}

int mult_soma(int a, int b){
    return mult_soma_aux(a,b,0);
}

int patinho_feio(int *vet, int num, int tam){
    if(vet[tam-1] == num ){
        return 1;
    }
    if (tam-1 == 0){
        return 0;
    }
    return patinho_feio(vet, num, tam-1);
}

int Max_aux(int *vet, int tam, int maior){
    if (vet[tam] >= maior){
        maior = vet[tam];
        return Max_aux(vet, tam-1, maior);
    }
    return maior;
}

int Max(int *vet, int tam){
    return Max_aux(vet, tam-1, 0);
}
//FIM COM CALDA
int main(){
    int vet[5] = {1,2,3,4,5};
    printf("SEM CALDA\t\t%d * %d = %d\n\n", 5,5,resul_som(5,5));
    printf("COM CALDA\t\t%d * %d = %d\n\n", 5,5,mult_soma(5,5));
    printf("EXISTE: %s \n\n", (patinho_feio(vet, 5, 5) == 0 )? "NÃO":"SIM");
    printf("CALDA - MAIOR ELEMENTO: %d\n\n", Max(vet, 5));
    printf("SEM CALDA - MAIOR ELEMENTO: %d\n\n", Max_s(vet, 5));
}