#include <stdio.h>
#include <string.h>

struct Horario {
    int hora;
    int minutos;
    int segundos;
};

struct Data {
    int dia;
    int mes;
    int ano;
};

struct Compromisso {
    struct Data data;
    struct Horario horario;
    char descricao[50];
};

int main() {
    struct Compromisso compromisso1;
    struct Data data = {01, 12, 2012};
    struct Horario horario = {12, 11, 10};

    compromisso1.data = data;
    compromisso1.horario = horario;
    strcpy(compromisso1.descricao, "hora de la muerte");

    printf("Compromisso 1:\n\
            \nData: %d/%d/%d\
            \nHorário: %d:%d:%d\
            \nDescrição: %s\n",
           compromisso1.data.dia, compromisso1.data.mes, compromisso1.data.ano,
           compromisso1.horario.hora, compromisso1.horario.minutos, compromisso1.horario.segundos,
           compromisso1.descricao);

    return 0;
}
