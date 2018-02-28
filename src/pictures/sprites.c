#include "sprites.h"

int central_init_sprites(control_t *control)
{
	if (init_sprites(control))
		if (init_menu(control))
			if (init_banner(control))
				if (init_intro(control))
					if (init_font(control))
						if (init_wait(control))
							if (init_pannel_res(control))
								return (1);
	return (0);
}

// 31 sprites

int init_sprites(control_t *control)
{
	int indexX;
	int indexY;
	int numtile;

	indexX = 0;
	numtile = 0;
	control->sprites->sprite_surf = IMG_Load("sprites/Game_sprites.png"); // charge l'image dans image_ram en RAM
	if (control->sprites->sprite_surf == NULL)
	{
		printf(" Game_sprites.png introuvable !! \n");
		SDL_Quit();
		return (0);
	}

	control->sprites->sprite_coord = (coord_t*) malloc(sizeof (coord_t) * 31);
	while (indexX < 4)
	{
		indexY = 0;
		while (indexY < 9)
		{
			if (31 > numtile)
			{
				control->sprites->sprite_coord[numtile].img.w = WIDTH_TILE;
				control->sprites->sprite_coord[numtile].img.h = HEIGHT_TILE;
				control->sprites->sprite_coord[numtile].img.x = indexY * WIDTH_TILE;
				control->sprites->sprite_coord[numtile].img.y = indexX * HEIGHT_TILE;
			}
			indexY++;
			numtile++;
		}

		indexX++;
	}
	return (1);
}

int init_menu(control_t *control)
{
	int indexX;


	control->sprites->menu_surf = IMG_Load("sprites/menu1.png"); // charge l'image dans image_ram en RAM
	if (control->sprites->menu_surf == NULL)
	{
		printf("menu.png image introuvable !! \n");
		SDL_Quit();
		return (0);
	}
	control->sprites->menu_coord = (coord_t*) malloc(sizeof (coord_t) * 20);

	// le bandeau comprenant les joueurs
	control->sprites->menu_coord[1].img.w = 256;
	control->sprites->menu_coord[1].img.h = 32;
	control->sprites->menu_coord[1].img.x = 0;
	control->sprites->menu_coord[1].img.y = 0;
	// le bout de bordure
	control->sprites->menu_coord[2].img.w = 10;
	control->sprites->menu_coord[2].img.h = 32;
	control->sprites->menu_coord[2].img.x = 260;
	control->sprites->menu_coord[2].img.y = 0;
	// les affiches scores
	control->sprites->menu_coord[3].img.w = 138;
	control->sprites->menu_coord[3].img.h = 339;
	control->sprites->menu_coord[3].img.x = 285;
	control->sprites->menu_coord[3].img.y = 0;
	// le bouton
	control->sprites->menu_coord[4].img.w = 150;
	control->sprites->menu_coord[4].img.h = 60;
	control->sprites->menu_coord[4].img.x = 0;
	control->sprites->menu_coord[4].img.y = 79;
	// le compteur seul
	control->sprites->menu_coord[5].img.w = 30;
	control->sprites->menu_coord[5].img.h = 14;
	control->sprites->menu_coord[5].img.x = 40;
	control->sprites->menu_coord[5].img.y = 0;
	// les chiffres
	indexX = 0;
	while (indexX < 10)
	{
		control->sprites->menu_coord[indexX + 6].img.w = 8;
		control->sprites->menu_coord[indexX + 6].img.h = 14;
		control->sprites->menu_coord[indexX + 6].img.y = 60;
		control->sprites->menu_coord[indexX + 6].img.x = indexX * 10;
		indexX++;
	}

	control->sprites->menu_coord[17].img.w = 138;
	control->sprites->menu_coord[17].img.h = 339;
	control->sprites->menu_coord[17].img.x = 280;
	control->sprites->menu_coord[17].img.y = 0;
	// fond jaune
	control->sprites->menu_coord[18].img.w = 150;
	control->sprites->menu_coord[18].img.h = 60;
	control->sprites->menu_coord[18].img.x = 0;
	control->sprites->menu_coord[18].img.y = 140;

	return (1);
}

int init_banner(control_t *control)
{
	control->sprites->logo_surf = IMG_Load("sprites/SuperBombermanR.jpg");
	if (control->sprites->logo_surf == NULL)
	{
		SDL_Quit();
		return (0);
	}

	control->sprites->logo_coord = (coord_t*) malloc(sizeof (coord_t));
	control->sprites->logo_coord->img.w = 840;
	control->sprites->logo_coord->img.h = 473;
	control->sprites->logo_coord->img.x = 0;
	control->sprites->logo_coord->img.y = 0;
	return (1);
}

int init_intro(control_t *control)
{
	control->sprites->banner_surf = IMG_Load("sprites/banderole.png");
	if (control->sprites->banner_surf == NULL)
	{
		SDL_Quit();
		return (0);
	}
	control->sprites->banner_coord = (coord_t*) malloc(sizeof (coord_t));
	control->sprites->banner_coord->img.w = 840;
	control->sprites->banner_coord->img.h = 473;
	control->sprites->banner_coord->img.x = 0;
	control->sprites->banner_coord->img.y = 0;
	return (1);
}

int init_font(control_t *control)
{
	TTF_Init();
	control->sprites->color.b = 0;
	control->sprites->color.g = 0;
	control->sprites->color.r = 255;

	control->sprites->font = TTF_OpenFont("roboto/Roboto-Black.ttf", 45);
	if (control->sprites->font == NULL)
	{
		SDL_Quit();
		return (0);
	}
	TTF_Quit();
	return (1);
}

int init_wait(control_t *control)
{
	control->sprites->wait_surf = IMG_Load("sprites/attente1.png");
	if (control->sprites->wait_surf == NULL)
	{
		SDL_Quit();
		return (0);
	}
	control->sprites->wait_coord = (coord_t*) malloc(sizeof (coord_t));
	control->sprites->wait_coord->img.w = 320;
	control->sprites->wait_coord->img.h = 162;
	control->sprites->wait_coord->img.x = 0;
	control->sprites->wait_coord->img.y = 0;
	return (1);
}

int init_pannel_res(control_t *control)
{
	control->sprites->res_surf = IMG_Load("sprites/panneau_final.png");
	if (control->sprites->res_surf == NULL)
	{
		printf("menu.png image introuvable !! \n");
		SDL_Quit();
		return (0);
	}
	control->sprites->res_coord = (coord_t*) malloc(sizeof (coord_t) * 20);
	control->sprites->res_coord[1].img.w = 320;
	control->sprites->res_coord[1].img.h = 165;
	control->sprites->res_coord[1].img.x = 0;
	control->sprites->res_coord[1].img.y = 0;
	control->sprites->res_coord[2].img.w = 320;
	control->sprites->res_coord[2].img.h = 165;
	control->sprites->res_coord[2].img.x = 0;
	control->sprites->res_coord[2].img.y = 165;
	return (1);
}
