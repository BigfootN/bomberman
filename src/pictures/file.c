#include "file.h"

char filter(char c)
{
	if ((c >= 97 && 122 <= c) || (c >= 65 && 90 <= c))
		return c;
	else if (c == 95)
		return ' ';
	else
		return '\0';
}

int write_config_map(state_t* state, int *list)
{
	int index;

	state->map_info = (clmap_t*) malloc(sizeof (clmap_t));
	state->map_info->nbreTiles.x = list[0];
	state->map_info->nbreTiles.y = list[1];
	state->map_info->nbreTiles.w = list[2];
	state->map_info->pos.x = list[3];
	state->map_info->pos.y = list[4];

	state->map_info->pos.h = HEIGHT_TILE * state->map_info->pos.x;
	state->map_info->pos.w = WIDTH_TILE * state->map_info->pos.y;
	state->map_info->wall = (int*) malloc(sizeof (int) * list[2]);
	index = 0;
	while (index < list[2])
	{
		state->map_info->wall[index] = 0;
		index++;
	}
	state->map_info->wall[list[5]] = 1;
	state->map_info->wall[list[6]] = 1;
	state->map_info->wall[list[7]] = 1;
	return (1);
}

int manage_data(state_t* state, char* name)
{
	char *title_brut;
	int index;
	int *list;
	FILE *fp;

	if ((fp = open_file(name)) != NULL)
	{
		state->map_info = (clmap_t*) malloc(sizeof (clmap_t));

		state->map_info->file_name = (char*) malloc(sizeof (char) * 64);
		state->map_info->sprite_name = (char*) malloc(sizeof (char) * 64);
		state->map_info->title = (char*) malloc(sizeof (char) * 64);

		title_brut = (char*) malloc(sizeof (char) * 64);
		list = (int*) malloc(sizeof (int) * 8);

		fscanf(fp, "%s", title_brut);
		index = 0;
		while (title_brut[index] != '\0')
		{
			state->map_info->title[index] = filter(title_brut[index]);
			index++;
		}

		fscanf(fp, "%s", state->map_info->file_name);
		fscanf(fp, "%s", state->map_info->sprite_name);
		fscanf(fp, "%d %d %d", &list[0], &list[1], &list[2]);
		fscanf(fp, "%d %d", &list[3], &list[4]);
		fscanf(fp, "%d %d %d", &list[5], &list[6], &list[7]);

		if (list[0] != 0 && list[1] != 0 && list[2] != 0 && list[3] != 0 && list[4] != 0)
		{
			write_config_map(state, list);
			init_map(state, fp);
			init_spell(state);
			fclose(fp);
			return (1);
		}
		fclose(fp);
	}
	return (0);
}

FILE *open_file(char *name)
{
	FILE *fp;
	char *text;

	text = (char*) malloc(sizeof (char) * strlen("map/"));
	bzero(text, strlen("map/"));
	text = strcat(text, "map/");
	text = strcat(text, name);

	if ((fp = fopen(text, "r")) == NULL)
	{
		printf("fichier ");
		printf("%s", name);
		printf(" maquant !\n");
		SDL_Quit();
		return NULL;
	}
	return (fp);
}

// les maps map et hidebonus

void init_map(state_t *state, FILE *fp)
{
	int indexX;
	int indexY;

	indexX = 0;
	state->map_info->real_map = (int**) malloc(sizeof (int*) * state->map_info->pos.x); //11
	state->map_info->action_map = (int**) malloc(sizeof (int*) * state->map_info->pos.x);
	while (indexX < state->map_info->pos.x)
	{
		state->map_info->real_map[indexX] = (int*) malloc(sizeof (int) * state->map_info->pos.y); //15
		state->map_info->action_map[indexX] = (int*) malloc(sizeof (int) * state->map_info->pos.y);
		indexY = 0;
		while (indexY < state->map_info->pos.y)
		{
			state->map_info->real_map[indexX][indexY] = 0;
			state->map_info->action_map[indexX][indexY] = -1;
			fscanf(fp, "%d", &state->map_info->real_map[indexX][indexY]);
			indexY++;
		}
		indexX++;
	}
}

void init_spell(state_t *state)
{
	int indexX;
	int indexY;

	indexX = 0;
	state->map_info->penalty_bonus_map = (int**) malloc(sizeof (int*) * state->map_info->pos.x);
	while (indexX < state->map_info->pos.x)
	{
		state->map_info->penalty_bonus_map[indexX] = (int*) malloc(sizeof (int) * state->map_info->pos.y);
		indexY = 0;
		while (indexY < state->map_info->pos.y)
		{
			state->map_info->penalty_bonus_map[indexX][indexY] = -1;
			indexY++;
		}
		indexX++;
	}
}
