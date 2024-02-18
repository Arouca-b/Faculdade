
#include <stdio.h>
#include <stdlib.h>
#include "faturamento.h"
#include "vendas.h"
#include "mensagens.h"
#include <time.h>

FATURAMENTO *alocar_faturamento(){
    FATURAMENTO* fat = (FATURAMENTO*) calloc(1,sizeof(FATURAMENTO));
    if (fat == NULL){
        exit(1);
    }
    fat->faturamentoMes = alocar_faturamentoMes();
    return fat;
}

FATURAMENTO *realocar_faturamento(FATURAMENTO *fat, int anos) {
    fat = realloc(fat, (anos + 1) * sizeof(FATURAMENTO));
    if (fat == NULL) {
        exit(1);
    }
    return fat;
}

void salvar_dados_sistema(FATURAMENTO *sistema, int anos){
    //SALVA DADOS DA LISTA DE PRODUTOS
    FILE *arquivo;
    arquivo = fopen("sistema.txt", "wb");

    fwrite(&anos, sizeof(int), 1, arquivo);    //quantidade de protudos no BD
    for(int i = 0; i <= anos && sistema[i].mes_Inical > 0 ; i++){
        fwrite(&sistema[i], sizeof(FATURAMENTO) - sizeof(FATURAMENTO_MES*), anos, arquivo); //produtos
        salvar_faturamento_mes(sistema[i].faturamentoMes, sistema[i].meses_Em_Atividade);
    }
    fclose(arquivo);
}

void salvar_faturamento_mes(FATURAMENTO_MES *sistema, int meses){
    FILE *arquivo;
    arquivo = fopen("sistema_mensal.txt", "wb");
    
    for(int i = 0; i <= meses && sistema[i].qVendas_mes; i++){
        fwrite(&sistema[i], sizeof(FATURAMENTO_MES) - sizeof(VENDA*), 1, arquivo); //produtos
        salva_venda(sistema[i].vendas_mes, sistema[i].qVendas_mes);
    }
    fclose(arquivo);
}

FATURAMENTO *recuperar_dados_sistema(FATURAMENTO* sistema, int* anos){
    // RECUPERAR DADOS DA LISTA DE PRODUTOS
    FILE *arquivo;
    sistema = alocar_faturamento();
    arquivo = fopen("sistema.txt", "rb");
    if (arquivo == NULL){
        remove("sistema.txt");
        return sistema;
    }

    fread(anos, sizeof(int), 1, arquivo);//quantidade de produtos

    if (*anos > 0){
        sistema = realocar_faturamento(sistema, (*anos) - 1);
    }

    for (int i = 0; i < (*anos) + 1; i++){

        fread(&sistema[i], sizeof(FATURAMENTO) - sizeof(FATURAMENTO_MES*) , 1, arquivo);
        fclose(arquivo);

        for(int i = 0; i < *anos; i++){
            sistema[i].faturamentoMes = recuperar_mes(sistema[i].faturamentoMes, sistema[i].meses_Em_Atividade);
        }
    }
    
    return sistema;
}

FATURAMENTO *verifica_datas(FATURAMENTO* sistema, int* anos){
    time_t currentTime;
    struct tm *localTime;
    currentTime = time(NULL);
    localTime = localtime(&currentTime);

    if (sistema[*anos].ano == 0 && sistema[*anos].mes_Inical == 0){
        sistema[*anos].ano = localTime->tm_year + 1900;
        sistema[*anos].mes_Inical = localTime->tm_mon + 1;
    }else{
        if (sistema[*anos].ano != localTime->tm_year + 1900){
            (*anos)++;
            sistema = realocar_faturamento(sistema, *anos);
            sistema[*anos].ano = localTime->tm_year + 1900;
            sistema[*anos].meses_Em_Atividade = 0;
            sistema[*anos].faturamentoMes = alocar_faturamentoMes();
            sistema[*anos].mes_Inical = sistema[*anos].faturamentoMes[sistema[*anos].meses_Em_Atividade].mes = localTime->tm_mon + 1;
        }

        if (sistema[*anos].faturamentoMes[sistema[*anos].meses_Em_Atividade].mes != localTime->tm_mon + 1){
            sistema[*anos].meses_Em_Atividade++;
            sistema[*anos].faturamentoMes = realocar_faturamentoMes(sistema[*anos].faturamentoMes, sistema[*anos].meses_Em_Atividade);
            sistema[*anos].faturamentoMes[sistema[*anos].meses_Em_Atividade].mes = localTime->tm_mon + 1;
            sistema[*anos].faturamentoMes[sistema[*anos].meses_Em_Atividade].qVendas_mes = 0;
        }
    }
    return sistema;
}

FATURAMENTO renda_anual(FATURAMENTO sistema, PRODUTO *lista_Produtos, int produtos_Em_Estoque){
    if (sistema.ano == 0){
        time_t currentTime;
        struct tm *localTime;
        currentTime = time(NULL);
        localTime = localtime(&currentTime);
        sistema.ano = localTime->tm_year + 1900;
    }

    sistema.faturamentoMes[sistema.meses_Em_Atividade] = renda_mensal(sistema.faturamentoMes[sistema.meses_Em_Atividade], lista_Produtos, produtos_Em_Estoque);
    sistema.arrecadado_anual += sistema.faturamentoMes[sistema.meses_Em_Atividade].vendas_mes[sistema.faturamentoMes[sistema.meses_Em_Atividade].qVendas_mes-1].preco_venda;
    return sistema;
}

FATURAMENTO_MES renda_mensal(FATURAMENTO_MES mesAtual, PRODUTO *produtos, int produtos_em_estoque){
    if (mesAtual.mes <= 0 || mesAtual.mes > 12){
        time_t currentTime;
        struct tm *localTime;
        currentTime = time(NULL);
        localTime = localtime(&currentTime);
        mesAtual.mes = localTime->tm_mon + 1;
    }
    mesAtual.vendas_mes = venda_de_produto(mesAtual.vendas_mes, &mesAtual.qVendas_mes, produtos, produtos_em_estoque);
    mesAtual.arrecadado_mensal += mesAtual.vendas_mes[mesAtual.qVendas_mes-1].preco_venda;

    return mesAtual;
}


//FATURAMENTO MENSAL
FATURAMENTO_MES *alocar_faturamentoMes(){
    FATURAMENTO_MES* fat = (FATURAMENTO_MES*) calloc(1,sizeof(FATURAMENTO_MES));
    if (fat == NULL){
        exit(1);
    }
    fat->vendas_mes = alocar_espaco_vendas();
    return fat;
}

FATURAMENTO_MES *realocar_faturamentoMes(FATURAMENTO_MES *fat_m, int meses) {
    fat_m = realloc(fat_m, (meses + 1) * sizeof(FATURAMENTO_MES));
    if (fat_m == NULL) {
        exit(1);
    }
    return fat_m;
}

FATURAMENTO_MES* recuperar_mes(FATURAMENTO_MES* sistema, int quantidade_meses){
    FILE *arquivo;
    arquivo = fopen("dados_mensais.txt", "rb");
    sistema = realocar_faturamentoMes(sistema, quantidade_meses+1);
    if (arquivo == NULL){
        system("clear||cls");
        printf("\n\nERRO AO RECUPERAR ARQUIVO MENSAL\n\n\n");
        exit(1);
    }

    for (int i = 0; i < quantidade_meses + 1; i++){
        fread(&sistema[i], sizeof(FATURAMENTO_MES) - sizeof(VENDA*), 1, arquivo);
        sistema[i].vendas_mes = recupera_historico_vendas(sistema[i].vendas_mes, sistema[i].qVendas_mes);
    }
    return sistema;
}


void relatorio_Financeiro(FATURAMENTO *sistema, int anos){
    system("clear||cls");
    printf("\n\t\t\t\t\tSISTEMA FINANCEIRO\n\n");
    imprimir_relatorios_anuais(sistema, anos);
}

void imprimir_relatorios_anuais(FATURAMENTO *sistema, int anos_atuacao){
    printf("\t\t--------------------------------------------------------\n\t\t");
    printf("|%7s| ", "Ano  ");
    printf("%16s", " Meses atuando |");
    printf("%14s|", "  Arrecadado  ");
    printf(" %14s", "Media/mes   |");
    for (int i = 0; i <= anos_atuacao; i++) {
        printf("\n\t\t|%6d |", sistema[i].ano);
        printf("       %2d       |", sistema[i].meses_Em_Atividade);
        printf("  %10.2f  |", sistema[i].arrecadado_anual);
        printf("  %10.2f  |", (float) (sistema[i].arrecadado_anual/(sistema[i].meses_Em_Atividade+1)));
    }
    printf("\n\t\t--------------------------------------------------------\n\n");
    pausa();
}
