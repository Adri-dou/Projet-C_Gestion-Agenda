
#include <stdio.h>
#include "search.h"

int classicalSearch(t_d_list my_list, int val) {
    t_d_cell * temp = my_list.heads[0];
    while (temp != NULL) {
        if (temp->value == val) return 1;
        temp = temp->next[0];
    } return 0;
}

int levelSearch(t_d_list my_list, int val) {
    t_d_cell * temp = my_list.heads[my_list.max_level-1];

    for (int i=my_list.max_level-1; i>=0; i--) {

        if (temp != NULL) {

            if (temp->value > val) temp = my_list.heads[i];

            // We update 'temp' until the value is between temp and temp->next
            while ((temp->next[i] != NULL) && (val > temp->next[i]->value)) temp = temp->next[i];

            //printf("Debug : %d - %d\n", temp1->value, temp1->next[i]->value);

            if ((temp->value == val) || ((temp->next[i] != NULL) && (temp->next[i]->value == val))) return 1;
        }
    }
    return 0;
}
