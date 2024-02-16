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
FATURAMENTO recuperar_mes(FATURAMENTO sistema);

#endif // FATURAMENTO_H
