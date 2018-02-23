#include "ai_bonus_penalty.h"

static int rand_max(const int max) {
	time_t t;
	int ret;

	srand((unsigned int) &t);
	ret = rand() % max;

	return ret;
}

int bonus_penalty_init() {
	int nb_monster;
	int choice;

	nb_monster = rand_max(10);
	if (nb_monster == 0)
		choice = 28;
	else if (nb_monster == 1)
		choice = 6;
	else if (nb_monster == 2)
		choice = 29;
	else if (nb_monster == 3)
		choice = 5;
	else if (nb_monster == 4)
		choice = 27;
	else if (nb_monster == 5)
		choice = 8;
	else if (nb_monster == 6)
		choice = 7;
	else if (nb_monster == 7)
		choice = 4;
	else if (nb_monster == 8)
		choice = 30;
	else
		choice = -1;

	return (choice);
}
