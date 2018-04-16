//
// Created by marc on 01/03/18.
//

#include "headers.h"

int convert(int temps, int number, int flag) {
    int data;

    if (temps >= number)
        data = temps / number;
    else {
        if (flag == 2)
            data = temps;
        else
            data = 0;
    }

    return (data);
}

/*
 * chrono_time : temps choisie pour le set
 */

void chrono_session(t_control *control) {
    struct tm date_actual;
    time_t seconds;
    int minute1;
    int minute2;
    int seconde1;
    int seconde2;

    if (control->receive_map != NULL) {
        //time_t data = control->receive_map->depart_time;
        if (chrono_set == 0 ||
             (chrono_set < control->receive_map->depart_time && control->receive_map->depart_time != 0)) {
            chrono_set = (long) control->receive_map->depart_time; /* le temp d'arrivée */
        } else if (chrono_set != 0) {
            {
                /* au temps moins celui qui est actuel donne les minutes plus les secondes restantes */
                seconds = chrono_set - time(NULL);
                minute1 = 0, minute2 = 0, seconde1 = 0, seconde2 = 0;
                if (seconds > 0) {
                    date_actual = *localtime(&seconds);

                    minute1 = convert(date_actual.tm_min, 10, 1);
                    minute2 = convert(date_actual.tm_min % 10, 10, 2);

                    seconde1 = convert(date_actual.tm_sec, 10, 1);
                    seconde2 = convert(date_actual.tm_sec % 10, 10, 2);
                }
                /* affiche un compteur de compte à rebour */
                if (chrono_set >= time(NULL)) {
                    display_counter(control, minute1, minute2, seconde1, seconde2);
                    /* si le temps est écoulé il met zero et desactive */
                } else if (chrono_set < time(NULL) && seconds >= 0) {
                    chrono_set = 0;
                    display_counter(control, 0, 0, 0, 0);
                    control->receive_map->depart_time = 0; /* remet à zero */
                }
            }
        }
    }
}