//
// Created by marc on 01/03/18.
//

#ifndef BOMBERMAN_LIBS_H
#define BOMBERMAN_LIBS_H

// string
typedef struct s_string {
    char *str;
    int size;
    int len;
} string_t;

int my_strcmp(const char *s1, const char *s2);
char *my_strdup(const char *s1);
size_t my_strlen(const char *s);
char *my_put_nbr(int n);
void my_putchar(char c);
int my_choicenumber(int c);
char *my_strcat(char *dest, const char *src);
void my_putstr(const char *str);
// rand
int my_way_rand(int nbre);
int my_rand(int nbre);
int my_rand_binaire();
void	my_bzero(void *s, size_t n);
void	*my_memset(void *b, int c, size_t len);

#endif //BOMBERMAN_LIBS_H
