#include <stdio.h>
#include <wchar.h>
#include <math.h>
#include <string.h>

typedef enum {
    PAUS,
    OUROS,
    COPAS,
    ESPADAS,

} NAIPE;

typedef enum {
    AS,
    DOIS,
    TRES,
    QUATRO,
    CINCO,
    SEIS,
    SETE,
    OITO,
    NOVE,
    DEZ,
    VALETE,
    C,
    DAMA,
    REI,

} VALOR;

int f1(wchar_t x[]){
    VALOR v = valor(x[0]);
    int count = 0;

    // ciclo for com funções valor e naipe feitas por DANI
    for(int i = 0; x[i] != '\0'; i++)
    {
        if(valor(x[i])==v) count++;
        else return 0;
    }

    return count;
}

