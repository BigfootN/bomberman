#include "headers.h"

int createBonusMalus()
{
    int nbreMonstre;
    int choice;

    nbreMonstre = my_rand(10);
     if (nbreMonstre == 0)
         choice = 28;
     else if (nbreMonstre == 1)
         choice = 6;
     else if (nbreMonstre == 2)
         choice = 29;
     else if (nbreMonstre == 3)
         choice = 5;
     else if (nbreMonstre == 4)
         choice = 27;
     else if (nbreMonstre == 5)
         choice = 8;
     else if (nbreMonstre == 6)
         choice = 7;
     else if (nbreMonstre == 7)
         choice = 4;
     else if (nbreMonstre == 8)
         choice = 30;
     else
         choice = -1; // sinon rien pas de BM

    /* if (nbreMonstre == 0)
         choice = 8;
     else if (nbreMonstre == 1)
         choice = 6;
     else if (nbreMonstre == 2)
         choice = 5;
     else if (nbreMonstre == 3)
         choice = 7;
     else
         choice = -1;
    if (nbreMonstre == 0)
        choice = 28;
    else if (nbreMonstre == 1)
        choice = 30;
    else if (nbreMonstre == 2)
        choice = 29;
    else if (nbreMonstre == 3)
        choice = 27;*/


    return (choice);
}