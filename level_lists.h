
#ifndef PROJET_C_GESTION_AGENDA_LEVEL_LISTS_H
#define PROJET_C_GESTION_AGENDA_LEVEL_LISTS_H

#include "cells.h"

// The level list structure
typedef struct s_d_list {
    t_d_cell **heads;
    int max_level;
} t_d_list;


// FUNCTIONS :

// PART I

// Creates a new empty level list
t_d_list createEmptyList(int);

// Add a new cell in head
void addCellHead(t_d_list *, t_d_cell *);

// Insert new cell, sorted
void insertCell(t_d_list *, t_d_cell *);


// PART II



// Function that return a completed list of 2^n -1 cells and n levels
t_d_list createFullList(int);


#endif //PROJET_C_GESTION_AGENDA_LEVEL_LISTS_H
