/*Um escritório de contabilidade tem 3 funcionários:
secretária(o), contadora(o) e estagiária(o). A ficha
de todos têm a s mesmas informações: nome,
endereço, salário, sexo biológico, CPF e telefone.
Faça um programa que leia todas essas
informações, e as imprima em forma de tabela
ordenada crescente por salário*/

#include <stdio.h>
#include <stdlib.h>

struct escritorio{
    char nome[100], sexo, endereco[200], cpf[15], telefone[30];
    float salario; 
};

int main(){
    struct escritorio secretaria, contadora, estagiario;
    float ordem[3];
    printf("\n\n\t\tSecretária!!\n\n");
    printf("Nome: ");
    scanf("%[^\n]%*c", secretaria.nome);
    printf("Endereço: ");
    scanf("%[^\n]%*c", secretaria.endereco);
    printf("Salário: R$ ");
    scanf("%f%*c", &secretaria.salario);
    printf("Sexo (M ou F): ");
    scanf("%c%*c", &secretaria.sexo);
    while (secretaria.sexo != 'f' && secretaria.sexo != 'F' && secretaria.sexo != 'm' && secretaria.sexo != 'M' ){
        system("clear||cls");
        printf("\n\n\t\t secretaria!!\n\n");
        printf("Nome: %s\n", secretaria.nome);
        printf("Endereço: %s\n", secretaria.endereco);
        printf("Salário: R$ %.2f\n", secretaria.salario);
        printf("Sexo (M ou F): ");
        scanf("%c%*c", &secretaria.sexo);
    }
    
    printf("CPF (apenas números): ");
    scanf("%[^\n]%*c", &secretaria.cpf);
    printf("Telefone (apenas número): ");
    scanf("%[^\n]%*c", &secretaria.telefone);

    printf("\n\n\t\tContadora!!\n\n");
    printf("Nome: ");
    scanf("%[^\n]%*c", contadora.nome);
    printf("Endereço: ");
    scanf("%[^\n]%*c", contadora.endereco);
    printf("Salário: R$ ");
    scanf("%f%*c", &contadora.salario);
    printf("Sexo (M ou F): ");
    scanf("%c%*c", &contadora.sexo);
    while (contadora.sexo != 'f' && contadora.sexo != 'F' && contadora.sexo != 'm' && contadora.sexo != 'M' ){
        system("clear||cls");
        printf("\n\n\t\t secretaria!!\n\n");
        printf("Nome: %s\n", contadora.nome);
        printf("Endereço: %s\n", contadora.endereco);
        printf("Salário: R$ %.2f\n", contadora.salario);
        printf("Sexo (M ou F): ");
        scanf("%c%*c", &contadora.sexo);
    }
    printf("CPF (apenas números): ");
    scanf("%[^\n]%*c", &contadora.cpf);
    printf("Telefone (apenas número): ");
    scanf("%[^\n]%*c", &contadora.telefone);

    printf("\n\n\t\tEstagiario!!\n\n");
    printf("Nome: ");
    scanf("%[^\n]%*c", estagiario.nome);
    printf("Endereço: ");
    scanf("%[^\n]%*c", estagiario.endereco);
    printf("Salário: R$ ");
    scanf("%f%*c", &estagiario.salario);
    printf("Sexo (M ou F): ");
    scanf("%c%*c", &estagiario.sexo);
    while (contadora.sexo != 'f' && contadora.sexo != 'F' && contadora.sexo != 'm' && contadora.sexo != 'M' ){
        system("clear||cls");
        printf("\n\n\t\t secretaria!!\n\n");
        printf("Nome: %s\n", estagiario.nome);
        printf("Endereço: %s\n", estagiario.endereco);
        printf("Salário: R$ %.2f\n", estagiario.salario);
        printf("Sexo (M ou F): ");
        scanf("%c%*c", &estagiario.sexo);
    }
    printf("CPF (xxx.xxx.xxx-xx): ");
    scanf("%[^\n]%*c%*c", &estagiario.cpf);
    printf("Telefone (apenas número): ");
    scanf("%[^\n]%*c", &estagiario.telefone);

    system("clear||cls");

    if(estagiario.salario > contadora.salario && estagiario.salario > secretaria.salario){}
    printf("\n\n\t\tEstagiario!!\n\n");
    printf("Nome: %s\n", estagiario.nome);
    printf("Endereço: %s\n", estagiario.endereco);
    printf("Salário: R$ %.2f\n", estagiario.salario);
    printf("Sexo: %c\n", estagiario.sexo);
    printf("CPF: %d\n", estagiario.cpf);
    printf("Telefone: %d\n\n", estagiario.telefone);

    printf("\n\n\t\t Contadora!!\n\n");
    printf("Nome: %s\n", contadora.nome);
    printf("Endereço: %s\n", contadora.endereco);
    printf("Salário: R$ %.2f\n", contadora.salario);
    printf("Sexo: %c\n", contadora.sexo);
    printf("CPF: %d\n", contadora.cpf);
    printf("Telefone: %d\n\n", contadora.telefone);

    printf("\n\n\t\t secretaria!!\n\n");
    printf("Nome: %s\n", secretaria.nome);
    printf("Endereço: %s\n", secretaria.endereco);
    printf("Salário: R$ %.2f\n", secretaria.salario);
    printf("Sexo: %c\n", secretaria.sexo);
    printf("CPF: %d\n", secretaria.cpf);
    printf("Telefone: %d\n\n", secretaria.telefone);
}