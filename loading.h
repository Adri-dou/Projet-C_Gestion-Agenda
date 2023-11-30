
#ifndef PROJET_C_GESTION_AGENDA_LOADING_H
#define PROJET_C_GESTION_AGENDA_LOADING_H

#include "search.h"
#include "timer.h"


t_d_list loadRandomPeople();

char ** give1000RdmNames(char *);

t_d_list loadSchedule();

void saveSchedule(t_d_list);


#endif //PROJET_C_GESTION_AGENDA_LOADING_H
