//
// Created by marc on 01/03/18.
//

#ifndef BOMBERMAN_LIBS_H
#define BOMBERMAN_LIBS_H

#ifdef IS_WINDOWS
#include <Windows.h>
#else
#include <pthread.h>
#endif

#include <stdio.h>
#include <stdlib.h>

// string
typedef struct s_string {
	char* str;
	int size;
	int len;
} string_t;

int my_strcmp(const char* s1, const char* s2);
char* my_strdup(const char* s1);
size_t my_strlen(const char* s);
char* my_put_nbr(int n);
void my_putchar(char c);
int my_choicenumber(int c);
char* my_strcat(char* dest, const char* src);
void my_putstr(const char* str);
// rand
int my_way_rand(int nbre);
int my_rand(int nbre);
int my_rand_binaire();

#ifdef IS_WINDOWS
typedef HANDLE WINAPI Thread;
#else
typedef pthread_t* Thread;
#endif

#ifdef IS_WINDOWS
Thread thread_create(LP_THREAD_START_ROUTINE, LPVOID);
#else
Thread thread_create(void* (*fct)(void*), void*);
#endif

void thread_join(Thread);

#endif	//BOMBERMAN_LIBS_H
