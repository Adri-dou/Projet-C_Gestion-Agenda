
#ifndef PROJET_C_GESTION_AGENDA_CELLS_H
#define PROJET_C_GESTION_AGENDA_CELLS_H

#include "contacts.h"

// The level Cell structure :
typedef struct s_d_cell {
    t_contact * value;
    int level;
    struct s_d_cell **next;
} t_d_cell;


// Function to create a new cell
t_d_cell * createCell(t_contact * , int);


#endif //PROJET_C_GESTION_AGENDA_CELLS_H
