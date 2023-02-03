
/*  
    *compile
        clear; clear; gcc main.c -o main;
*/
#ifndef STR_H_FILE
#define STR_H_FILE
#define STR_DEFAULT_SIZE 64

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

typedef long long lo_t;
typedef struct{
    lo_t size, len;
    char *c, *tm;
} str_t;

str_t *str_new(char const *str);
str_t *str_new_size(size_t size);
str_t *str_cat_str(str_t *d, str_t const *da);
str_t *str_cat(str_t *d, char const *da);
str_t *str_cat_int_a(str_t *d, lo_t const da, lo_t apartir);
str_t *str_cat_n(str_t *d, char const *da, lo_t n);
str_t *str_cat_char(str_t *d, char da);
void caSet(str_t *d, char const *da);
str_t *str_cat_int(str_t *d, lo_t da);
str_t *str_cat_bol(str_t *d, unsigned char da);
str_t *str_cat_dou(str_t *d, double da);
str_t *str_n_del(str_t *d, lo_t del);
str_t *str_free(str_t *d);
lo_t *str_fnd(str_t *ca, char const *fn);
str_t *str_set_size(str_t *d, size_t size);
str_t *str_clear(str_t *d);
str_t *str_clon(str_t const *d);

#endif
