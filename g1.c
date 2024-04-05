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

NAIPE naipe (wchar_t carta) {
    NAIPE resultado = 0;
    if (carta >= 0x1F0A1 && carta <= 0x1F0AE) resultado = ESPADAS;
    else if (carta >= 0x1F0B1 && carta <= 0x1F0BE) resultado = COPAS;
    else if (carta >= 0x1F0C1 && carta <= 0x1F0CE) resultado = OUROS;
    else resultado = PAUS;

    return resultado;
}

VALOR valor (wchar_t carta){
    VALOR resultado = 0;
    wchar_t i;
    int j = 0;
    if (naipe(carta) == ESPADAS) for (i = 0x1F0A1; i<= 0x1F0AE; i++) {if (carta == i) resultado = j; j++;}
    else if (naipe(carta) == COPAS) for (i = 0x1F0B1; i<= 0x1F0BE ; i++) {if (carta == i) resultado = j; j++;}
    else if (naipe(carta) == OUROS) for (i = 0x1F0C1; i<= 0x1F0CE; i++) {if (carta == i) resultado = j; j++;}
    else for (i = 0x1F0D1; i<= 0x1F0DE; i++) {if (carta == i) resultado = j; j++;}

    return resultado;
}

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

