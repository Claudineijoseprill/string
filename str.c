
str_t *str_new(char const *str){
    str_t *re = (str_t*)calloc(sizeof(str_t), 1);
    re->size = STR_DEFAULT_SIZE;
    re->c = (char*)calloc(sizeof(char), re->size);
    re->len = 0;

    str_cat(re, str);
    return re;
}
str_t *str_new_size(size_t size){
    str_t *re = (str_t*)calloc(sizeof(str_t), 1);
    re->size = size;
    re->len = 0;
    re->c = (char*)calloc(sizeof(char), re->size);
    return re;
}
str_t *str_cat_str(str_t *d, str_t const *da){
    str_cat(d, da->c);
    return d;
}
str_t *str_cat(str_t *d, char const *da){
    if(d == NULL || da == NULL) return d;

    lo_t i, e, s=d->size-1;
    for(i=d->len, e=0; da[e]!=0; i++,e++){
        if(i == s){
            d->size += (d->size*10)/100;// mas 10%
            s = d->size-1;

            char *tmp = (char*)calloc(sizeof(char), d->size);

            strcpy(tmp, d->c);
            free(d->c);
            d->c = tmp;
        }
        d->c[i] = da[e];
    }
    d->len = i;
    d->c[i] = 0;
    return d;
}
str_t *str_cat_int_a(str_t *d, lo_t const da, lo_t apartir){
    if(apartir < d->len){

        d->len = apartir;
        d->c[d->len] = 0;

    }

    str_cat_int(d, da);
    return d;
}
str_t *str_cat_n(str_t *d, char const *da, lo_t n){
    if(d == NULL || da == NULL) return d;
    lo_t i, e, s=d->size-1;

    for(i=d->len, e=0; e<n&&da[e]!=0; i++,e++){
        if(i == s){
            d->size += (d->size*10)/100;// mas 10%
            s = d->size-1;

            char *tmp = (char*)calloc(sizeof(char), d->size);

            strcpy(tmp, d->c);
            free(d->c);
            d->c = tmp;
        }
        d->c[i] = da[e];
    }
    d->len = i;
    d->c[i] = 0;
    return d;
}
str_t *str_cat_char(str_t *d, char da){
    if(d != NULL && da != 0){

        if(d->len+1 >= d->size){
            d->size += (d->size*10)/100;// mas 10%
            
            char *tmp = (char*)calloc(sizeof(char), d->size);

            strcpy(tmp, d->c);
            free(d->c);
            d->c = tmp;
        }
        d->c[d->len] = da;
        d->len++;
        d->c[d->len] = 0;
    }
    return d;
}
str_t *str_set(str_t *d, char const *da){
    str_clear(d);
    str_cat(d, da);
    return d;
}
str_t *str_cat_int(str_t *d, lo_t da){
    if(d->size - d->len < 128){

        d->size += 128;
        char *tmp = (char*)calloc(sizeof(char), d->size);

        strcpy(tmp, d->c);
        free(d->c);
        d->c = tmp;
    }
    char *t = d->c+(d->len+64);
    sprintf(t, "%lld", da);
    str_cat(d, t);
    t[0] = 0;
  
    return d;
}
str_t *str_cat_bol(str_t *d, unsigned char da){
    if(da) str_cat(d, "true");
    else str_cat(d, "false");
  
    return d;
}
str_t *str_cat_dou(str_t *d, double da){
    if(d->size - d->len < 128){

        d->size += 128;
        char *tmp = (char*)calloc(sizeof(char), d->size);

        strcpy(tmp, d->c);
        free(d->c);
        d->c = tmp;
    }
    char *t = d->c+(d->len+64);
    sprintf(t, "%f", da);
    str_cat(d, t);
    t[0] = 0;
  
    return d;
}
str_t *str_n_del(str_t *d, lo_t del){
    d->len -= del;
    d->c[d->len] = 0;
  
    return d;
}
str_t *str_free(str_t *d){
    if(d != NULL){
        free(d->c);
        free(d);
    }
    d = NULL;
    return d;
}
lo_t *str_fnd(str_t *ca, char const *fn){
    lo_t static re[100] = {-1};
    lo_t i, e,
    pos = 1,
    slen = strlen(fn);
    for(e=0; e<ca->len; e++){
        for(i=0; i<slen; i++){
            if(strncmp(ca->c+e, fn, slen) == 0){
                re[pos++] = e;
                e += slen;
                break;
            }
        }
    }
    re[0] = pos-1;
    return re;
}
str_t *str_set_size(str_t *d, size_t size){
    if(d != NULL && size > d->len){

        lo_t i;
        d->tm = (char*)calloc(sizeof(char), size);
        for(i=0; i<d->len; i++) d->tm[i] = d->c[i];
        d->tm[i] = 0;

        d->size = size;
        d->c = d->tm;

    }
    return d;
}
str_t *str_clear(str_t *d){
    d->c[0] = 0;
    d->len = 0;
    return d;
}
str_t *str_clon(str_t const *d){
    if(d){
        str_t *re = str_new_size(d->len+10);
        strcpy(re->c, d->c);
        re->len = d->len;
        return re;
    }
    return NULL;
}
