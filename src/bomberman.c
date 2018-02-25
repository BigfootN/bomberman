#include "headers.h"

int main()
{
    int choixpage;
    int index;
    t_control *control;
    
    control = init_control();
    if (centralInitSprites(control))
    {
        index = 0;
        choixpage = 1;
        control->network->net_clt_srv_state = 1;
        while (l_bib[index].number != 0)
        {
            if (l_bib[index].number == choixpage)
            {
                choixpage = l_bib[index].pfunc(control);
                index = -1;
            }
            index++;
        }
    }
    return 0;
}