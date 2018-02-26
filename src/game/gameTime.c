#include "headers.h"

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

void displayTime(t_control *control)
{
    time_t arrivee;
    if (control->receiveMap->departTime > 0)
    {
        time(&arrivee);
        if (difftime(arrivee, control->receiveMap->departTime) > 240)
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

            change = arrivee - control->receiveMap->departTime;
            if (change > 0)
            {
                pminute = convert(change, 60, 1); // 3 minutes si inferieur 0 minutes
                pseconde = convert(change % 60, 60, 2);

                minute1 = convert(pminute, 10, 1);
                minute2 = convert(pminute  % 10, 10, 2);

                seconde1 = convert(pseconde, 10, 1);
                seconde2 = convert(pseconde % 10, 10, 2);

                displayCounter(control, minute1, minute2, seconde1, seconde2);
            }

        }
    }
}