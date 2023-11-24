
#ifndef PROJET_C_GESTION_AGENDA_SEARCH_H
#define PROJET_C_GESTION_AGENDA_SEARCH_H

#include "level_lists.h"


// Search a value only on level 0
// int classicalSearch(t_d_list, int);  (doesn't exist anymore)

// Search a value from high levels

t_contact * levelSearch(t_d_list, char *);

t_contact * seekContact(t_d_list);

#endif //PROJET_C_GESTION_AGENDA_SEARCH_H
