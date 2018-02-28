#ifndef ANNEXE_H
#define ANNEXE_H

// string

typedef struct s_string {
    char *str;
    int size;
    int len;
} string_t;

// ressources
int my_strcmp(const char *s1, const char *s2);
char *my_strdup(const char *s1);
size_t my_strlen(const char *s);
char *my_put_nbr(int n);
void my_putchar(char c);
int my_choicenumber(int c);
char *my_strcat(char *dest, const char *src);
void my_putstr(const char *str);
// string
//void string_ajout(string_t * str, const char *str2);
//void string_free(string_t * str);
//string_t *string_new(void);
//void *my_memcpy(void *s1, const void *s2, size_t n);
// rand
int my_way_rand(int nbre);
int my_rand(int nbre);
int my_rand_binaire();


#endif /* ANNEXE_H */

