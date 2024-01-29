#include <stdio.h>

int main(){
    float tam_a, vel_bit, t;

    printf("Insira o tamanho do arquivo(bits): ");
    scanf("%f", &tam_a);
    printf("Insira a velocidade da sua conexão(bits): ");
    scanf("%f", &vel_bit);

    t = tam_a/vel_bit;
    printf("Vai demorar cerca de %.2f segundos para baixar o arquivo\n", t);
}