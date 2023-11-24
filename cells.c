
#include "cells.h"


t_d_cell * createCell(t_contact * ctc, int lvl){
    t_d_cell *new_cell = malloc(sizeof(t_d_cell));
    new_cell->value = ctc;
    new_cell->level = lvl;
    new_cell->next = malloc(sizeof(t_d_cell) * lvl);
    for (int i=0; i<lvl; i++) new_cell->next[i] = NULL;
    return new_cell;
}
