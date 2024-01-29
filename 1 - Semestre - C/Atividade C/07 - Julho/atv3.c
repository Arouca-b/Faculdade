/*Criar um registro do tipo data, com os campos
dia,mês e ano. Criar um registro do tipo dados
com campos nome, sexo e salario, e registros
aninhados do tipo data para armazenar a data
de nascimento e data de admissão. Criar
variáveis gerente e vendedor do tipo dados, e
hoje do tipo data. Ler a data de hoje, os dados
do gerente e do vendedor e informá-los na tela
juntamente com as seguintes informações:
quem recebe o maior salário, e quanto tempo
em anos de contribuição cada um tem, em
anos e meses*/

#include <stdio.h>
#include <stdlib.h>

struct data
{
    int dia, mes, ano;
};

struct dados
{
    char nome[100], sexo;
    float salario;
    struct data dataNasci;
    struct data dataAdmissao;
};


int main(){
    struct data hoje;
    struct dados gerente, vendedor;

    printf("\n\nInsira a data de hoje: ");
    scanf("%d%*c%d%*c%d%*c", &hoje.dia, &hoje.mes, &hoje.ano);
    printf("\n\n\t\t Vendedor!\n\n");
    printf("Nome: ");
    scanf("%[^\n]%*c", vendedor.nome);
    printf("Sexo (F ou M): ");
    scanf("%c%*c", &vendedor.sexo);
    printf("Salário: ");
    scanf("%f%*c", &vendedor.salario);
    printf("Data Nascimento: ");
    scanf("%d%*c%d%*c%d%*c", &vendedor.dataNasci.dia, &vendedor.dataNasci.mes, &vendedor.dataNasci.ano);
    printf("Data Admissão: ");
    scanf("%d%*c%d%*c%d%*c", &vendedor.dataAdmissao.dia, &vendedor.dataAdmissao.mes, &vendedor.dataAdmissao.ano);

    printf("\n\n\t\t Gerente!\n\n");
    printf("Nome: ");
    scanf("%[^\n]%*c", gerente.nome);
    printf("Sexo (F ou M): ");
    scanf("%c%*c", &gerente.sexo);
    printf("Salário: ");
    scanf("%f%*c", &gerente.salario);
    printf("Data Nascimento: ");
    scanf("%d%*c%d%*c%d%*c", &gerente.dataNasci.dia, &gerente.dataNasci.mes, &gerente.dataNasci.ano);
    printf("Data Admissão: ");
    scanf("%d%*c%d%*c%d%*c", &gerente.dataAdmissao.dia, &gerente.dataAdmissao.mes, &gerente.dataAdmissao.ano);
    printf("Maior Salário: ");
    if (gerente.salario > vendedor.salario)
    {
        printf("Gerente\n");
    }else if(gerente.salario < vendedor.salario){
        printf("Vendedor\n");
    }else{
        printf("Os dois tem o mesmo salário;");
    }

    system("clear||cls");
    printf("\n\n\t\t Vendedor!\n\n");
    printf("Nome: %s\n", vendedor.nome);
    printf("Sexo (F ou M): %c\n", vendedor.sexo);
    printf("Salário: %.2f\n", vendedor.salario);
    printf("Data Nascimento: %d/%d/%d\n", vendedor.dataNasci.dia, vendedor.dataNasci.mes, vendedor.dataNasci.ano);
    printf("Data Admissão: %d/%d/%d\n", vendedor.dataAdmissao.dia, vendedor.dataAdmissao.mes, vendedor.dataAdmissao.ano);
    printf("Tempo de trabalho: %d ano %d meses\n\n", (hoje.ano - vendedor.dataAdmissao.ano),(hoje.mes - vendedor.dataAdmissao.mes));


    printf("\n\n\t\t Gerente!\n\n");
    printf("Nome: %s\n", gerente.nome);
    printf("Sexo (F ou M): %c\n", gerente.sexo);
    printf("Salário: %.2f", gerente.salario);
    printf("Data Nascimento: %d/%d/%d\n", gerente.dataNasci.dia, gerente.dataNasci.mes, gerente.dataNasci.ano);
    printf("Data Admissão: %d/%d/%d\n", gerente.dataAdmissao.dia, gerente.dataAdmissao.mes, gerente.dataAdmissao.ano);
    printf("Tempo de trabalho: %d ano %d meses\n\n", (hoje.ano - gerente.dataAdmissao.ano ),( hoje.mes - gerente.dataAdmissao.mes));
}