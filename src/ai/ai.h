#ifndef AI_H
#define AI_H

#include "types.h"
#include "ai_piece.h"
#include "ai_blast.h"
#include "ai_counter.h"
#include "ai_map.h"
#include "ai_msg.h"
#include <pthread.h>
#include "inits.h"
#include "network.h"

void* central_ai(void*);
int ai_loop();
void* ai_main();

#endif	/* ifndef AI_H */
