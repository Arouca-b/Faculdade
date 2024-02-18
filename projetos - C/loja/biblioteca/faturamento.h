#ifndef FATURAMENTO_H
#define FATURAMENTO_H
#include "dados.h"

FATURAMENTO *recuperar_dados_sistema(FATURAMENTO* sistema, int* anos);
FATURAMENTO *alocar_faturamento();
FATURAMENTO *realocar_faturamento(FATURAMENTO *fat, int anos);
FATURAMENTO *verifica_datas(FATURAMENTO* sistema, int* anos);
FATURAMENTO renda_anual(FATURAMENTO sistema, PRODUTO *lista_Produtos, int produtos_Em_Estoque);
FATURAMENTO_MES renda_mensal(FATURAMENTO_MES mesAtual, PRODUTO *produtos, int produtos_em_estoque);
FATURAMENTO_MES *alocar_faturamentoMes();
FATURAMENTO_MES *realocar_faturamentoMes(FATURAMENTO_MES *fat_m, int meses);
FATURAMENTO_MES* recuperar_mes(FATURAMENTO_MES* sistema, int quantidade_meses);
void relatorio_Financeiro(FATURAMENTO *sistema, int anos);
void imprimir_relatorios_anuais(FATURAMENTO *sistema, int anos_atuacao);
void salvar_dados_sistema(FATURAMENTO *sistema, int anos);
void salvar_faturamento_mes(FATURAMENTO_MES *sistema, int meses);

#endif // FATURAMENTO_H
