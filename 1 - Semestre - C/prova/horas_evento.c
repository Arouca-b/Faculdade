//calcular o tempo de um evento em horas, minutos e segundos

#include <stdio.h>

int main(){
    int time, hours, minuts, seconds;

    printf("\n\tDigite o tempo em secundos: ");
    scanf("%d", &time);
    hours = time/3600;
    minuts = (time%3600)/60;
    seconds = (time%3600)%60;
    printf("\tO evento durou cerca de: %d Horas, %d minutos e %d segundos!!\n\n", hours, minuts, seconds);
    return 0;
}