#include "choice_ip_window.h"

void create_tag(control_t *control)
{
	SDL_Rect renderQuad = {200, 200, 385, 60};
	write_str(control, renderQuad, "adresse ip serveur");
}


int choice_nb(int c)
{
	if ((c >= 48 && c <= 57) || (c == 46))
		return (1);
	return (0);
}

char* delete_data(control_t* control, SDL_Event event)
{
	int index;
	char *tmp;

	tmp = (char*) malloc(sizeof(char)*16);
	bzero(tmp, 16);
	tmp = control->network->server_addr;

	index = strlen(tmp);
	if ((event.key.keysym.scancode == SDL_SCANCODE_BACKSPACE) && index)
	{
		index -= 1;
		tmp[index] = '\0';
		control->network->server_addr = tmp;
	}
	encart_clair(control);

	return tmp;
}

char *write_data(SDL_Event event, char *tmp)
{
	char c;
	int index;

	index = strlen(tmp);
	c = event.text.text[0];

	if (choice_nb(c) && index >= 0 && index < 15)
	{
		tmp[index] = c;
		index += 1;
	}

	tmp[index] = '\0';
	return tmp;
}
