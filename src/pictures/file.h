#ifndef FILE_H
#define FILE_H

#include "types.h"
#include "define.h"

char filter(char);
int write_config_map(state_t*, int*);
int manage_data(state_t*, char*);
FILE *open_file(char *name);
void init_map(state_t *, FILE *);
void init_spell(state_t*);

#endif
