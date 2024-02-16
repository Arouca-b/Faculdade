
#include <stdio.h>
#include <stdlib.h>
#include "faturamento.h"
#include "vendas.h"
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

    if (*anos > 1){
        sistema = realocar_faturamento(sistema, (*anos) - 1);
    }
    fread(sistema, sizeof(FATURAMENTO) - sizeof(FATURAMENTO_MES*) , *anos, arquivo);
    fclose(arquivo);

    for(int i = 0; i < *anos; i++){
        sistema[i] = recuperar_mes(sistema[i]);
    }


    return sistema;
}

FATURAMENTO *verifica_datas(FATURAMENTO* sistema, int* anos){
    time_t currentTime;
    struct tm *localTime;
    currentTime = time(NULL);
    localTime = localtime(&currentTime);

    if (sistema[*anos].ano == 0 && sistema[*anos].mes_Inical == 0){
        sistema[*anos].ano = localTime->tm_year;
        sistema[*anos].mes_Inical = localTime->tm_mon;
    }else{
        if (sistema[*anos].ano != localTime->tm_year){
            (*anos)++;
            sistema = realocar_faturamento(sistema, *anos);
            sistema[*anos].ano = localTime->tm_year;
            sistema[*anos].meses_Em_Atividade = 0;
            sistema[*anos].faturamentoMes = alocar_faturamentoMes();
            sistema[*anos].mes_Inical = sistema[*anos].faturamentoMes[sistema[*anos].meses_Em_Atividade].mes = localTime->tm_mon;
        }

        if (sistema[*anos].faturamentoMes[sistema[*anos].meses_Em_Atividade].mes != localTime->tm_mon){
            sistema[*anos].meses_Em_Atividade++;
            sistema[*anos].faturamentoMes = realocar_faturamentoMes(sistema[*anos].faturamentoMes, sistema[*anos].meses_Em_Atividade);
            sistema[*anos].faturamentoMes[sistema[*anos].meses_Em_Atividade].mes = localTime->tm_mon;
            sistema[*anos].faturamentoMes[sistema[*anos].meses_Em_Atividade].qVendas_mes = 0;
        }
    }
    return sistema;
}

FATURAMENTO renda_anual(FATURAMENTO sistema, PRODUTO *lista_Produtos, int produtos_Em_Estoque){

    sistema.faturamentoMes[sistema.meses_Em_Atividade] = renda_mensal(sistema.faturamentoMes[sistema.meses_Em_Atividade], lista_Produtos, produtos_Em_Estoque);
    sistema.arrecadado_anual += sistema.faturamentoMes[sistema.meses_Em_Atividade].arrecadado_mensal;
    return sistema;
}

FATURAMENTO_MES renda_mensal(FATURAMENTO_MES mesAtual, PRODUTO *produtos, int produtos_em_estoque){
    mesAtual.vendas_mes = venda_de_produto(mesAtual.vendas_mes, &mesAtual.qVendas_mes, produtos, produtos_em_estoque);
    mesAtual.arrecadado_mensal += mesAtual.vendas_mes[mesAtual.qVendas_mes].preco_venda;
    mesAtual.qVendas_mes++;

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

FATURAMENTO recuperar_mes(FATURAMENTO sistema){
    FILE *arquivo;
    arquivo = fopen("dados_mensais.txt", "rb");
    sistema.faturamentoMes = realocar_faturamentoMes(sistema.faturamentoMes, sistema.meses_Em_Atividade-1);
    if (arquivo == NULL){
        system("clear||cls");
        printf("\n\nERRO AO RECUPERAR ARQUIVO MENSAL\n\n\n");
        exit(1);
    }

    fread(sistema.faturamentoMes, sizeof(FATURAMENTO_MES) - sizeof(VENDA*), sistema.meses_Em_Atividade, arquivo);

    for (int i = 0; i < sistema.meses_Em_Atividade; i++){
        sistema.faturamentoMes[i].vendas_mes = recupera_historico_vendas(sistema.faturamentoMes[i].vendas_mes, &sistema.faturamentoMes[i].qVendas_mes);
    }

    return sistema;
}
