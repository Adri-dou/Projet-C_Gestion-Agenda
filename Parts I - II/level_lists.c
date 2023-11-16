
#include <stdio.h>
#include <malloc.h>
#include <math.h>
#include "level_lists.h"

t_d_list createEmptyList(int lvl){
    t_d_list new_list;
    new_list.max_level = lvl;
    new_list.heads = malloc(sizeof(t_d_cell) * lvl);
    for (int i=0; i<lvl; i++) new_list.heads[i] = NULL;
    return new_list;
}

void addCellHead(t_d_list *my_list, t_d_cell * new_cell){
    int mini;   // Check in case the Cell has a greater level than max
    if (my_list->max_level >= new_cell->level) mini = new_cell->level;
    else mini = my_list->max_level;

    for (int i=0; i<mini; i++){
        new_cell->next[i] = my_list->heads[i];
        my_list->heads[i] = new_cell;
    }
}

void displayLevel(t_d_list my_list, int lvl_display){
    t_d_cell *temp;
    temp = my_list.heads[lvl_display];
    printf("[list head_%d @-]", lvl_display);
    while (temp != NULL){
        printf("-->[%3d|@-]", temp->value);
        temp = temp->next[lvl_display];
    }
    printf("-->NULL\n");
}

void displayList(t_d_list my_list){
    for (int i=0; i<my_list.max_level; i++){
        displayLevel(my_list, i);
    }
}

void alignedDisplay(t_d_list my_list){
    // First level is always aligned
    displayLevel(my_list, 0);

    t_d_cell *temp1, *temp2;
    for (int i=1; i<my_list.max_level; i++){
        temp1 = my_list.heads[0];
        temp2 = my_list.heads[i];
        printf("[list head_%d @-]", i);
        while (temp1 != NULL) {
            if ((temp2 != NULL) && (temp2->value == temp1->value)) {
                printf("-->[%3d|@-]", temp2->value);
                temp2 = temp2->next[i];
            } else printf("-----------");
            temp1 = temp1->next[0];
        }
        printf("-->NULL\n");
    }
}

void insertCell(t_d_list * my_list, t_d_cell * new_cell) {

    if ((my_list->heads[0] == NULL) || (new_cell->value <= my_list->heads[0]->value)) addCellHead(my_list, new_cell);

    else {
        int level;   // Check in case the Cell has a greater level than max
        if (my_list->max_level >= new_cell->level) level = new_cell->level;
        else level = my_list->max_level;

        t_d_cell *temp;

        for (int i = level - 1; i >= 0; i--) {
            temp = my_list->heads[i];
            if ((temp == NULL) || (temp->value > new_cell->value)) {
                new_cell->next[i] = my_list->heads[i];
                my_list->heads[i] = new_cell;
            }
            else {
                while ((temp->next[i] != NULL) && (new_cell->value > temp->next[i]->value)) temp = temp->next[i];
                new_cell->next[i] = temp->next[i];
                temp->next[i] = new_cell;
            }
        }
    }
}

t_d_list createFullList(int n){
    t_d_list new_list = createEmptyList(n);
    int nb_cells = pow(2, n) -1;
    int *tab = malloc(nb_cells * sizeof(int));
    int step = 2, k=1;

    // Initialize with 0
    for (int i=0; i<nb_cells; i++) tab[i] = 0;

    while (step < nb_cells){
        for (int i=step-1; i<nb_cells; i+=step)  tab[i]++;
        k++;
        step = pow(2, k);
    }

    // Let's fill the list
    for (int i=nb_cells-1; i>=0; i--){
        addCellHead(&new_list, createCell(i+1, tab[i]+1));
    }
    return new_list;
}
