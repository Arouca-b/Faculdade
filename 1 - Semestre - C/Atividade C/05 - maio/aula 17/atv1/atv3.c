z#include <stdio.h>

int main(){
    int poltrona, fileira = 0, localizacao=0;
    printf("\tDigite o numero da poltrona: ");
    scanf("%d", &poltrona);

    //validação de entrada
    for (; poltrona > 52 || poltrona < 1 ;)
    {
        printf("\n\t\t-------------------------\n");
        printf("\t\t|  POLTRONA INVÁLIDA!!  |");
        printf("\n\t\t-------------------------\n");
        printf("\n\tDigite o numero da poltrona (1 - 52): ");
        scanf("%d", &poltrona);
    }
    /*verificar a fileira da poltrona, as poltronas são divididas em 4 colunas, o resto da divisão indica a posição das colunas (resto == 0 indica a 4º coluna)*/
    if (poltrona % 4 == 1 || poltrona % 4 == 2){
        fileira = 1;
        //verificar se é na janela ou no corredor

        

        if(poltrona % 2 == 0){
            localizacao = 0; //corredor
        } else {
            localizacao = 1; //janela
        }
    }else {
        fileira = 2;
        //verificar se é na janela ou no corredor
        if(poltrona % 2 == 0){
            localizacao = 1;    //janela
        } else {
            localizacao = 0;    //corredor
        }
    }

    printf("\n\tPoltrona: %d\n", poltrona);
    printf("\tFileira: %dº\n", fileira);
    printf("\tLado: %s\n", fileira == 1 && (localizacao == 1 || localizacao == 0)  ? "Direito": "Esquerdo");
    printf("\tPosição: %s\n", fileira == 1 && localizacao == 1 ? "Janela": fileira == 1 && localizacao == 0 ? "Corredor" : fileira==2 && localizacao == 1 ? "Janela" : "Corredor");

    printf("\n\t\t----------------------------------------------------------------------------------\n");
    printf("\t\t|  As direções estão relacionadas a percepção do passageiro ao entrar no busão!! |");
    printf("\n\t\t----------------------------------------------------------------------------------\n\n");
}