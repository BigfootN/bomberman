#include "headers.h"
#include "ai_blast.h"
#include "linked_list.h"
#include "ai_piece.h"


static int check_wall(int answer, int tile, int piece) {
	int choice;

	if (answer == 0 && (piece >= 23 && piece <= 26))
		// les players
		choice = piece;
	if (answer == 0 && (piece >= 27 && piece <= 30))
		// les autres monstres
		choice = piece;
	if (answer == 0 && (piece >= 4 && piece <= 8))
		// les bonus malus
		choice = piece;
	if (answer == 1)
		// si mur on desis_activ
		choice = 1;
	if (answer == 0 || tile == 20)
		// si chemin libre
		choice = tile;

	return (choice);
}

void init_bomb_map(state_t* state) {
	int idx_x;
	int idx_y;
	SDL_Rect pos;
	SDL_Rect posMap;
	int** tab;

	idx_x = 0;
	idx_y = 0;
	while (idx_x < state->map_info->pos.x) {
		pos.x = idx_x;
		idx_y = 0;
		while (idx_y < state->map_info->pos.y) {
			pos.y = idx_y;
			int tile = state->map_info->penalty_bonus_map[idx_x][idx_y];
			if (tile == 40) {
				posMap.x = idx_x;
				posMap.y = idx_y;
				tab = init_grid_fire(state, posMap);
				display_fire(state, pos, tab);
				state->map_info->penalty_bonus_map[idx_x][idx_y] = 41;
			} else if (tile >= 41 && tile <= 50) {
				// temps explosion
				state->map_info->penalty_bonus_map[idx_x][idx_y] += 1;
				/* on detruit definitevement l'exlosion*/
				if (state->map_info->penalty_bonus_map[idx_x][idx_y] >= 50) {
					state->map_info->penalty_bonus_map[idx_x][idx_y] = -1;
					blast_clean(state, idx_x, idx_y);
				}
			}
			idx_y++;
		}
		idx_x++;
	}
}

// nettoyage explosion
// ce deplace en haut a gauche du point pour faire tout les 9 tuples
// et desis_activ les sprite explosion
void blast_clean(state_t* state, int row, int col) {
	int idx_x;
	int idx_y;
	SDL_Rect pos;

	idx_x = row - 2;
	while (idx_x < row + 3) {
		if (0 <= idx_x && (state->map_info->pos.x) > idx_x) {
			idx_y = col - 2;
			while (idx_y < col + 3) {
				if (0 <= idx_y && (state->map_info->pos.y) > idx_y) {
					int tile = state->map_info->action_map[idx_x][idx_y];
					int mur = state->map_info->real_map[idx_x][idx_y];
					if (tile >= 9 && tile <= 17) {
						// tue ceux qui sont dedans
						state->map_info->action_map[idx_x][idx_y] = -1;
						// mettre les morts et désis_activr les players
					}
					if (mur == 19) {
						state->map_info->real_map[idx_x][idx_y] = 18;
						if (idx_x - 1 >= 0 && state->map_info->real_map[idx_x - 1][idx_y] == 21)
							state->map_info->real_map[idx_x][idx_y] = 22;
						int sort = bonus_penalty_init();
						// ici mettre le bonus voulue
						// action car un joueur ou un monstre ne peut pas y etre ne meme temps dans lorsque qu'ils se rencontre l'un
						// ou l'autre reste et un bonus ou un malus apparait pour le monstre ou le joueur concerné
						// si sort le sort est donné au joueur ou au monstre et disparait
						if (sort >= 27 && sort <= 30) {
							state->map_info->action_map[idx_x][idx_y] = sort;
							//piece_t *addItemPions(state_t *state, int type, SDL_Rect realpos,   SDL_Rect map_pos)
							pos.x = idx_x;
							pos.y = idx_y;
							piece_t* piece = add_pieces(state,  pos);
							// pour la suppression chercher aussi les emplacements x y lorsque un est trouvé
							piece->is_activ = 1;
							piece->life = 5;
							piece->requesstate_t = 1;
							if (sort >= 27 && sort <= 30)
								piece->request_1 = 3;
							else
								piece->request_1 = 4;
							piece->type = sort;
						} else
							// pour les sorts simple
							state->map_info->penalty_bonus_map[idx_x][idx_y] = sort;
					}
				}
				idx_y++;
			}
		}
		idx_x++;
	}
}

// fait la meme chose pour l'explosion, que la bombe
// donne un effet de souffle

void display_fire(state_t* state, SDL_Rect lpos, int** arr) {
	int indexX;
	int indexY;
	int flag;
	SDL_Rect pos;
	int col, row;

	indexX = 0;
	flag = 0;
	while (indexX < 5) {
		indexY = 0;
		while (indexY < 5) {
			if (arr[indexX][indexY] != 1) {
				col = 0;
				row = 0;
				flag = -1;
				pos = lpos;

				if (indexX == 0 && indexY == 2) {
					// pointe haut
					pos.x -= 2;
					flag = 9;
				} else if (indexX == 1 && indexY == 2) {
					// centre haut
					pos.x -= 1;
					flag = 10;
				} else if (indexX == 2 && indexY == 0) {
					// pointe milieu gauche
					pos.y -= 2;
					flag = 11;
				} else if (indexX == 2 && indexY == 1) {
					// bras milieu gauche
					pos.y -= 1;
					flag = 12;
				} else if (indexX == 2 && indexY == 2) {
					flag = 13;
				} else if (indexX == 2 && indexY == 3) {
					// bras centre droit
					pos.y += 1;
					flag = 14;
				} else if (indexX == 2 && indexY == 4) {
					// pointe centre droit
					pos.y += 2;
					flag = 15;
				} else if (indexX == 3 && indexY == 2) {
					// bras bas
					pos.x += 1;
					flag = 16;
				} else if (indexX == 4 && indexY == 2) {
					// pointe bas
					pos.x += 2;
					flag = 17;
				}
				col = pos.y;
				row = pos.x;

				if (flag != -1) {
					// couloirs vides
					if (arr[indexX][indexY] == 18 || arr[indexX][indexY] == 22)
						state->map_info->action_map[row][col] = flag;
					else if (arr[indexX][indexY] == 20)
						/* mur fractionnable*/
						state->map_info->real_map[row][col] = 19;
					/* change sur la carte de decor un object */
					else if (arr[indexX][indexY] >= 23 && arr[indexX][indexY] <= 26) {
						/* player */
						int player = state->map_info->action_map[row][col];
						state->map_info->action_map[row][col] = flag;
						/* on mets l'explosion */
						// dire detruit avant de le supprimer
						//deactivate_players(state, 1);
						piece_t* piece = search_player(state, player);
						piece->is_activ = 0;
						piece->life = 0;
					} else if ((arr[indexX][indexY] >= 27 && arr[indexX][indexY] <= 30) ||
							   (arr[indexX][indexY] >= 0 && arr[indexX][indexY] <= 8)) {
						int player = state->map_info->action_map[row][col];
						// supprimer immediatement
						state->map_info->action_map[row][col] = flag;
						/* on mets l'explosion */
						deactivate_players(state, player);
						/* supprime immediatement du jeux */
					}

				}
				//printf("%d", control->map_info->hidebonus[row][col]);
			}
			indexY++;
		}
		//printf("\n");
		indexX++;
	}
}

int** checkArray() {
	int index;
	int index2;
	int** tab;

	index = 0;
	tab = (int**) malloc(sizeof (int*) * 5);
	if (tab == NULL)
		return  (NULL);
	while (index < 5) {
		tab[index] = (int*) malloc(sizeof (int) * 5);
		if (tab[index] == NULL)
			return (NULL);
		index2 = 0;
		while (index2 < 5) {
			tab[index][index2] = 1;
			index2++;
		}
		index++;
	}
	return (tab);
}

// repere les tiles murs et non amovibles

int check_tuple(state_t* state, int tile) {
	if (state->map_info->wall[tile] == 1)
		//  && tile != 20
		return 1;
	else
		return 0;
}

int** init_grid_fire(state_t* state, SDL_Rect pos) {
	int index;
	int** tab;
	int answer;

	tab = checkArray();
	answer = 0;
	index = pos.x;
	while (index < pos.x + 3) {
		// to bottom
		if (0 <= index && (state->map_info->pos.x) > index) {
			/* repaire les joueurs */
			int piece = state->map_info->action_map[index][pos.y];
			int tile = state->map_info->real_map[index][pos.y];
			if (check_tuple(state, tile))
				answer = 1;
			tab[(index + 2) - pos.x][2] = check_wall(answer, tile, piece);
		}
		index++;
	}

	answer = 0;
	index = pos.x;
	while (index > pos.x - 3) {
		// to up
		if (0 <= index && (state->map_info->pos.x) > index) {
			/* repaire les joueurs */
			int piece = state->map_info->action_map[index][pos.y];
			int tile = state->map_info->real_map[index][pos.y];
			if (check_tuple(state, tile))
				answer = 1;
			tab[(index + 2) - pos.x][2] = check_wall(answer, tile, piece);
		}
		index--;
	}

	answer = 0;
	index = pos.y;
	while (index < pos.y + 3) {
		if (0 <= index && (state->map_info->pos.y) > index) {
			/* repaire les joueurs */
			int piece = state->map_info->action_map[pos.x][index];
			int tile = state->map_info->real_map[pos.x][index];
			if (check_tuple(state, tile))
				answer = 1;
			tab[2][(index + 2) - pos.y] = check_wall(answer, tile, piece);
		}
		index++;
	}

	answer = 0;
	index = pos.y;
	while (index > pos.y - 3) {
		if (0 <= index && (state->map_info->pos.y) > index) {
			/* repaire les joueurs */
			int piece = state->map_info->action_map[pos.x][index];
			int tile = state->map_info->real_map[pos.x][index];
			if (check_tuple(state, tile))
				answer = 1;
			tab[2][(index + 2) - pos.y] = check_wall(answer, tile, piece);
		}
		index--;
	}

	return (tab);
}
