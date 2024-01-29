#include <stdio.h>
#include <stdlib.h>

void main(){
    int *valores = 0, *vet_impar = 0, *vet_par = 0, q_impar = 0, q_par = 0, quant = 0;

    printf("Insira a quantidade de números a serem inseridos: ");
    scanf("%d%*c", &quant);
    valores = malloc(quant * sizeof(int));
    if (!valores){
        printf("\t\tFalhar ao alocar memória!!!\n\n");
        exit(1);
    }
    
    for (int i = 0; i < quant; i++){
        printf("Insira %dº número: ", i+1);
        scanf("%d%*c", &valores[i]);
        if (valores[i]%2 == 0){
            q_par++;
        }else{
            q_impar++;
        }
    }
    vet_impar = malloc(q_impar * sizeof(int));
    vet_par = malloc(q_par * sizeof(int));
    
    printf("\n\n\t\t\tVALORES DIGITADOS\n\n");
    for (int i = 0, q_par = q_impar = 0; i < quant; i++){
        printf("\t\tNUM: %d\n", valores[i]);

        if (valores[i]%2 == 0){
            vet_par[q_par] = valores[i];
            q_par++;
        }else{
            vet_impar[q_impar] = valores[i];
            q_impar++;
        }
    }
    printf("\n\n\t\t\tNUMEROS PARES\n\n");
    for (int i = 0; i < q_par; i++){
        printf("\t\tNUM: %d\n", vet_par[i]);
    }

    printf("\n\n\t\t\tNUMEROS IMPARES\n\n");
    for (int i = 0; i < q_impar; i++){
        printf("\t\tNUM: %d\n", vet_impar[i]);
    }
    free(valores);
    free(vet_impar);
    free(vet_par);   
}