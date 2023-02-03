/*
    Con esta simples heramienta podes concatenar textos, numeros, boleano, double, float, etc infinitamente sin
    preocuparte en sobreapasar el tamanho del char array
*/

#include <unistd.h>

#include "str.h"
#include "str.c"

int main(){

    str_t *texto = str_new("Inicio\n");
    for(int i=0; texto->len<500000; i++){
        str_cat(texto, "esta es la linea ");
        str_cat_int(texto, i);
        str_cat_char(texto, '\n');
    }

    printf("texto %s tamanho %lld\n", texto->c, texto->len);

    sleep(2);
    printf("freeee\n");
    str_free(texto);   // nunca se olviden de limpiar la variable creada con str_new
    sleep(2);

    printf("Exit\n");
    return 0;
}
