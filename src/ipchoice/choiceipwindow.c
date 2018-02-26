#include "headers.h"

void createEtiquettes(t_control *control)
{
    SDL_Rect renderQuad = {200, 200, 385, 60};
    writeString(control, renderQuad, "adresse ip serveur");
    // TTF_Font *police = NULL;

    //  TTF_Init();
    // SDL_Color couleurNoire = {0, 0, 0, 255};
    /* Chargement de la police */
    // police = TTF_OpenFont("roboto/Roboto-Black.ttf", 45);
    // if(police == NULL)
    //     SDL_Quit();
    /*
        SDL_Surface* textSurface = TTF_RenderText_Solid(control->sprites->police, "adresse ip serveur", control->sprites->couleur);
        SDL_Texture* text = SDL_CreateTextureFromSurface(control->Main_Renderer, textSurface);
        SDL_FreeSurface(textSurface);
        SDL_Rect renderQuad = {200, 200, 385, 60};
        SDL_RenderCopy(control->Main_Renderer, text, NULL, &renderQuad);
        SDL_DestroyTexture(text);*/
    //  TTF_Quit();*
}

void writeText(t_control* control)
{
    //SDL_Color couleurNoire = {0, 0, 0, 255};
    //TTF_Font *police = NULL;

    //TTF_Init();

    SDL_Rect renderQuad = {200, 298, my_strlen(control->network->ipserveur) * 25, 60};
    writeString(control, renderQuad, control->network->ipserveur);

    //police = TTF_OpenFont("roboto/Roboto-Black.ttf", 50);
    //SDL_Color textColor = {255, 255, 255, 0};
    // SDL_Surface* textSurface = TTF_RenderText_Solid(police, control->network->ipserveur, couleurNoire);
    //SDL_Texture* text = SDL_CreateTextureFromSurface(control->Main_Renderer, textSurface);
    // SDL_FreeSurface(textSurface);
    //SDL_Rect renderQuad = {200, 298, 385, 60};
    // SDL_Rect renderQuad = {200, 298, my_strlen(control->network->ipserveur) * 25, 60};
    // SDL_RenderCopy(control->Main_Renderer, text, NULL, &renderQuad);
    // SDL_DestroyTexture(text);
    // TTF_Quit();
}

int my_choicenumber(int c)
{
    if ((c >= 48 && c <= 57) || (c == 46))
        return (1);
    return (0);
}

char * deleteData(t_control* control, SDL_Event event)
{
    int index;
    char *tmp;
    tmp = (char*) malloc(sizeof (char*)*16);
    bzero(tmp, 16);
    // event.key.keysym.scancode == SDLK_BACKSPACE ||
    tmp = control->network->ipserveur;
    index = my_strlen(tmp);
    if ((event.key.keysym.scancode == SDL_SCANCODE_BACKSPACE) && index)
    {
        index -= 1;
        tmp[index] = '\0';
        control->network->ipserveur = tmp;
    }
    encartClair(control);
    return tmp;
}

char *writeData(SDL_Event event, char *tmp)
{
    char *lettre;
    int index;


    index = my_strlen(tmp);
    lettre = (char*) malloc(sizeof (char*));
    lettre = event.text.text;

    if (my_choicenumber(lettre[0]) && index >= 0 && index < 15)
    {
        lettre = lettre + '\0';
        tmp[index] = *lettre;
        index += 1;
    }
    tmp[index] = '\0';
    return tmp;
}