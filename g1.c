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

int f2 (wchar_t x[]){
    VALOR v = x[0];
    int n,a = 0;

    for(int i = 0; x[i] != '\0';i++)
    {
        if(x[a+1] == '\0' && n < 3 && i == a) return 0;
        if(valor(x[i]) == v+1)
        {
            v = valor(x[i]);
            i = 0;
            n++;
        }
        if(x[i+1] == '\0' && n<3){
            n = 0;
            i = 0;
            a++;
            v = x[a];        
        } else if (x[i+1] == '\0' && n >= 3){
            return n;
        }
    }
    return 0;
}

//retirar \n
void remove_newline(wchar_t *str) {
    wchar_t *p = str;
    while (*p != L'\0') {
        if (*p == L'\n') {
            *p = L'\0'; // Replace newline with null terminator
            break;      // Exit loop after removing the first newline
        }
        p++;
    }
}

int main() {
    setlocale(LC_CTYPE, "C.UTF-8");
    wchar_t output[BUFSIZ]; //wchar_t output[BUFSIZ] = {};
    fgetws (output, sizeof(output), stdin);
    remove_newline(output);
    printf("%d", f2(output));

    return 0;
}
