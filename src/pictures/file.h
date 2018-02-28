#ifndef FILE_H
#define FILE_H

#include "types.h"
#include "define.h"

char filter(char c);
int write_config_map(state_t*, int*);
FILE* open_file(char*);
void init_map(state_t*, FILE*);
void init_spell(state_t*);
int manage_data(state_t*, char*);

#endif
