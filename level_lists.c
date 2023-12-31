
#include <stdio.h>
#include <string.h>
#include "level_lists.h"

t_d_list createEmptyList(int lvl){
    t_d_list new_list;
    new_list.max_level = lvl;
    new_list.heads = malloc(sizeof(t_d_cell) * lvl);
    for (int i=0; i<lvl; i++) new_list.heads[i] = NULL;
    return new_list;
}

void addCellHead(t_d_list *my_list, t_d_cell * new_cell){
    for (int i=0; i<my_list->max_level; i++){
        new_cell->next[i] = my_list->heads[i];
        my_list->heads[i] = new_cell;
    }
}

void insertCell(t_d_list * my_list, t_d_cell * new_cell) {
    if ((my_list->heads[0] == NULL) || (strcmp(new_cell->value->ref_ID, my_list->heads[0]->value->ref_ID) < 0))
        addCellHead(my_list, new_cell);

    else {

        t_d_cell *temp;

        for (int i = my_list->max_level - 1; i >= 0; i--) {
            temp = my_list->heads[i];

            while ((temp->next[i] != NULL) && (strcmp(new_cell->value->ref_ID, temp->next[i]->value->ref_ID) > 0))
                temp = temp->next[i];
            //printf("%d ", my_list->max_level-1-i);
            if (i==0 || new_cell->value->ref_ID[my_list->max_level-1-i] != temp->value->ref_ID[my_list->max_level-1-i]){
                new_cell->next[i] = temp->next[i];
                temp->next[i] = new_cell;
            } else new_cell->level--;

        }
    }
}

void linearInsertion(t_d_list * my_list, t_d_cell * new_cell) {
    if ((my_list->heads[0] == NULL) || (strcmp(new_cell->value->ref_ID, my_list->heads[0]->value->ref_ID) < 0))
        addCellHead(my_list, new_cell);

    else {

        t_d_cell *temp;

        temp = my_list->heads[0];

        while ((temp->next[0] != NULL) && (strcmp(new_cell->value->ref_ID, temp->next[0]->value->ref_ID) > 0))
            temp = temp->next[0];

        new_cell->next[0] = temp->next[0];
        temp->next[0] = new_cell;

    }
}
