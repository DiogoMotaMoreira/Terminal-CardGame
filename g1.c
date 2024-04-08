#include <stdio.h>
#include <wchar.h>
#include <math.h>
#include <string.h>
#include <assert.h>
#include <locale.h>

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
        else return -1;
    }

    return count;
}


int f2 (wchar_t x[]){
    VALOR v = valor(x[0]);
    int n = 0;
    int a = 0;
    int resultado = -1;

    for(int i = 1; x[i] != '\0';i++)
    {
        if(x[a+1] == '\0' && n < 3 && i == a){
            resultado = 0;
            break;
        }
        else if(valor(x[i]) == (VALOR)(v+1))
        {
            v = valor(x[i]);
            i = 0;
            n++;
        }
        else if(x[i+1] == '\0' && n<3){
            n = 0;
            i = 0;
            a++;
            v = x[a];        
        } else if (x[i+1] == '\0' && n >= 3){
            resultado = n;
                    break;
                }
            }
    return resultado;
}

void remove_newline(wchar_t *str) {
    wchar_t *p = str;
    while (*p != L'\0') {
        if (*p == L'\n') {
            *p = L'\0'; 
            break;     
        }
        p++;
    }
}

wchar_t cartaMAlta (wchar_t x[]){
    int i;
    wchar_t max = L'🃑'; //A carta mais baixa e o AS de PAUS
    for (i = 0; x[i] != '\0'; i++){
        if (valor (max) == valor(x[i]) && naipe(max) < naipe (x[i])) max = x[i];
        if (valor (max) < valor (x[i])) max = x[i];
    }
    return max;

}

void resultado(wchar_t x[]){
    if (f2(x) != 0) wprintf (L"dupla sequência com %d cartas onde a carta mais alta é %lc", f2(x), cartaMAlta(x)); // change to f3
    else if (f2(x) != 0) wprintf (L"sequência com %d cartas onde a carta mais alta é %lc", f2(x), cartaMAlta(x));
    else if (f1(x) != 0) wprintf(L"conjunto com %d cartas onde a carta mais alta é %lc", f1(x), cartaMAlta(x));
    else printf ("Nada!\n");

}

int main() {
    setlocale(LC_CTYPE, "C.UTF-8");
    
    int i = 0;
    scanf ("%d", &i);
    //for (; i>0; i--){
    wchar_t output[BUFSIZ]; //wchar_t output[BUFSIZ] = {};
    fgetws (output, sizeof(output), stdin);
    remove_newline(output);
    printf("%d", f2(output));
        //resultado(output);

    return 0;
}
