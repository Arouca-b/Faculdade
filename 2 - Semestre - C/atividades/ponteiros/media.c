#include <stdio.h>
#include <stdlib.h>

int main() {
    float *nota, media = 0.0;
    int quant = 0;

    printf("Insira a quantidade de notas: ");
    scanf("%d%*c", &quant);

    nota = (float *) malloc(quant*sizeof(float));
    
    for (int i = 0; i < quant; i++){
        printf("Insira %d° nota: ", i+1);
        scanf("%f%*c", &nota[i]);
        media+=nota[i];
    }
    
    system("clear||cls");
    if (quant!=0){
        media/=quant;
        printf("\n\n\t\tNOTAS ABAIXO DA MÉDIA");
        printf("\n\tMédia = %.2f\n\n", media);
        for (int i = 0; i < quant; i++){
            if (nota[i] < media){
                printf("\tNota: %.1f\n", nota[i]);
            }
        }
    }else{
        printf("\t\tInsira uma quantidade válida!!\n\n\n");
    }
    free(nota);
    return 0;
}