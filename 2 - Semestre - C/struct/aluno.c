#include <stdlib.h>
#include <stdio.h>
#include "arouca.h"

LISTA* excluir_ele(LISTA* aluno, int valor, int *erro);
void mensagem_lista(int x);
LISTA* retira_ini(LISTA *aluno);
LISTA* excluir_ele(LISTA* aluno, int valor, int *erro);

int main(){
    int n = 0, op = 0, erro = 0;
    LISTA *princ = inicializar();

    do{
        printf("\t\t\tESCOLHA\n\n");
        printf("1 - Inserir valores\n");
        printf("2 - Imprimir\n");
        printf("3 - Excluir\n");
        printf("\n0 - SAIR\n");

        printf("\nEscolha: ");
        scanf("%d%*c", &op);

        switch(op){
            case 1: 
                do{
                    printf("Insira valores (0 = Sair): ");
                    scanf("%d%*c", &n);
                    if (n != 0){
                        princ = ordenar(princ, n);
                    }
                }while(n!= 0);
                break;

            case 2:
                imprimir_lista(princ);
                break;

            case 3:
                printf("Insira valor que deseja excluir: ");
                scanf("%d%*c", &n);
                princ = excluir_ele(princ, n, &erro);
                mensagem_lista(erro);
                break;
        }
    } while (op != 0);
}

LISTA* retira_ini(LISTA *aluno){
    LISTA *p = aluno;
    aluno = aluno->prox;
    free(p);
    return aluno;
}

LISTA* procura(LISTA *aluno, int n){
    LISTA *ant = aluno, *p = aluno;
    while(p->info != n && p->prox != NULL){
        ant = p;
        p = p->prox;
    }
    if (p->info == n){
        return ant;
    }
    return NULL;
}

LISTA* excluir_ele(LISTA* aluno, int valor, int *erro){
    LISTA *ant, *p;
    if (aluno->info == valor){
        (*erro) = 1;
        return retira_ini(aluno);
    }else{
        if (ant = procura(aluno, valor)){
            p = ant->prox;
            ant->prox = p->prox;
            free(p);
            (*erro) = 1;
            return aluno;
        }else{
            (*erro) = 0;
            return aluno;
        }
    }
}

void mensagem_lista(int x){
    switch (x){
    case 0:
        printf("\nNão encontrado, insira certo!!\n");
        break;
    case 1:
        printf("\nLista atualizada, faz o L!!\n");
        break;
    }
}