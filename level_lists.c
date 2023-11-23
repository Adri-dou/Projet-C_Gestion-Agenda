
#include <stdio.h>
#include <malloc.h>
#include <math.h>
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

void displayLevel(t_d_list my_list, int lvl_display){
    t_d_cell *temp;
    temp = my_list.heads[lvl_display];
    printf("[list head_%d @-]", lvl_display);
    while (temp != NULL){
        printf("-->[%s|@-]", temp->value->ref_ID);
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
            if ((temp2 != NULL) && (temp2->value->ref_ID == temp1->value->ref_ID)) {
                printf("-->[%10s|@-]", temp2->value->name);
                temp2 = temp2->next[i];
            } else printf("------------------");
            temp1 = temp1->next[0];
        }
        printf("-->NULL\n");
    }
}

void insertCell(t_d_list * my_list, t_d_cell * new_cell) {
    if ((my_list->heads[0] == NULL) || (strcmp(new_cell->value->ref_ID, my_list->heads[0]->value->ref_ID) < 0))
        addCellHead(my_list, new_cell);

    else {
        int level;   // Check in case the Cell has a greater level than max
        if (my_list->max_level >= new_cell->level) level = new_cell->level;
        else level = my_list->max_level;

        t_d_cell *temp;

        for (int i = level - 1; i >= 0; i--) {
            temp = my_list->heads[i];
            if ((temp == NULL) || (strcmp(temp->value->ref_ID, new_cell->value->ref_ID) > 0)) {
                new_cell->next[i] = my_list->heads[i];
                my_list->heads[i] = new_cell;
            } else {
                while ((temp->next[i] != NULL) && (strcmp(new_cell->value->ref_ID, temp->next[i]->value->ref_ID) > 0))
                    temp = temp->next[i];
                new_cell->next[i] = temp->next[i];
                temp->next[i] = new_cell;
            }
        }
    }
}
