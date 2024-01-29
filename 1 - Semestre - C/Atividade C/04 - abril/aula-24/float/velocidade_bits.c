#include <stdio.h>

int main() {
    double tam_arquivo, vel_conexao, t_download;

    printf("Digite o tamanho do arquivo em bits: ");
    scanf("%lf", &tam_arquivo);

    printf("Digite a velocidade da conexao em bits por segundo: ");
    scanf("%lf", &vel_conexao);

    t_download = tam_arquivo / vel_conexao;

    printf("Tempo necessário para download: %.2f segundos\n", t_download);

    return 0;
}
