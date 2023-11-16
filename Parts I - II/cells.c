
#include <malloc.h>
#include "cells.h"

t_d_cell * createCell(int val, int lvl){
    t_d_cell *new_cell = malloc(sizeof(t_d_cell));
    new_cell->value = val;
    new_cell->level = lvl;
    new_cell->next = malloc(sizeof(t_d_cell) * lvl);
    for (int i=0; i<lvl; i++) new_cell->next[i] = NULL;
    return new_cell;
}
