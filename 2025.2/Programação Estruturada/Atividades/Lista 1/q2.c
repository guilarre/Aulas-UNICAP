#include <stdio.h>
int main() {
    unsigned int tempo = 0;
    unsigned int tempo_horas = 0;
    unsigned int tempo_minutos = 0;
    unsigned int tempo_segundos = 0;

    printf("Digite um valor inteiro positivo em segundos: \n");
    scanf("%d", &tempo);
    
    // Versão 1 (mostra o mesmo tempo em unidades diferentes)

    // Tempo em horas
    // tempo_horas = tempo/3600;

    // Tempo em minutos
    // tempo_minutos = tempo/60;
    
    // Tempo em segundos
    // tempo_segundos = tempo;

    // printf("\n%d = %dh, ou %dm, ou %ds\n", tempo, tempo_horas, tempo_minutos, tempo_segundos);


    // Versão 2 (mostra o tempo em segundos no formato hh:mm:ss)

    unsigned int tempo_resto = 0;

    //input: 60601
    //output esperado: 60601 = 16h, 50m, 1s
    tempo_horas = tempo/3600;//16h
    tempo_resto = tempo%3600;//3001

    if (tempo_resto > 0) {
        tempo_minutos = tempo_resto/60;//50m
        tempo_resto = tempo_resto%60;//1
    }
    if (tempo_resto > 0) {
        tempo_segundos = tempo_resto;
    }
    printf("\n%ds = %02d:%02d:%02d\n", tempo, tempo_horas, tempo_minutos, tempo_segundos);
    return 0;
}