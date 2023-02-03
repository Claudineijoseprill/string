typedef struct{
    size_t size, len;
    char *c, *tm;
} str_t;

str_t *str_new(char const *str);
str_t *str_new_size(size_t size);
str_t *str_cat_str(str_t *d, str_t const *da);
str_t *str_cat(str_t *d, char const *da);
str_t *str_cat_int_a(str_t *d, long long const da, int apartir);
str_t *str_cat_n(str_t *d, char const *da, int n);
str_t *str_cat_char(str_t *d, char da);
void caSet(str_t *d, char const *da);
str_t *str_cat_int(ca_t *d, long long da);
str_t *str_cat_bol(str_t *d, u_char da);
str_t *str_cat_dou(str_t *d, double da);
str_t *str_n_del(str_t *d, u_short del);
str_t *str_free(str_t *d);
int *str_fnd(str_t *ca, char const *fn);
str_t *str_set_size(str_t *d, size_t size);
str_t *str_clear(str_t *d);
str_t *str_clon(str_t const *d);
