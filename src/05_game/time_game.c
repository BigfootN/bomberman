//
// Created by marc on 01/03/18.
//

#include "bomberman.h"

int convert(int temps, int number, int flag)
{
    int data;

    if (temps >= number)
        data = temps / number;
    else
    {
        if (flag == 2)
            data = temps;
        if (flag == 1)
            data = 0;
    }

    return (data);
}

void display_time(t_control *control)
{
    time_t arrivee;
    if (control->receive_map->depart_time > 0)
    {
        time(&arrivee);
        if (difftime(arrivee, control->receive_map->depart_time) > 240)
        {

        }
        else
        {
            int change;
            int pminute;
            int pseconde;
            int minute1;
            int minute2;
            int seconde1;
            int seconde2;

            change = arrivee - control->receive_map->depart_time;
            if (change > 0)
            {
                pminute = convert(change, 60, 1); // 3 minutes si inferieur 0 minutes
                pseconde = convert(change % 60, 60, 2);

                minute1 = convert(pminute, 10, 1);
                minute2 = convert(pminute  % 10, 10, 2);

                seconde1 = convert(pseconde, 10, 1);
                seconde2 = convert(pseconde % 10, 10, 2);

                display_counter(control, minute1, minute2, seconde1, seconde2);
            }

        }
    }
}