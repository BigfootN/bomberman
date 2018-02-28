#ifndef CHOICE_IP_WINDOW
#define CHOICE_IP_WINDOW

#include "types.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "kernel.h"

void create_tag(control_t*);
int choice_nb(int);
char* delete_data(control_t*, SDL_Event);
char* write_data(SDL_Event, char*);

#endif
