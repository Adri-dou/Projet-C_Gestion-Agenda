
#include <stdio.h>
#include "search.h"


int levelSearch(t_d_list my_list, char * ref) {
    t_d_cell * temp = my_list.heads[my_list.max_level-1];

    for (int i=my_list.max_level-1; i>=0; i--) {

        if (temp != NULL) {

            if (temp->value->ref_ID > ref) temp = my_list.heads[i];

            // We update 'temp' until the value is between temp and temp->next
            while ((temp->next[i] != NULL) && (ref > temp->next[i]->value->ref_ID)) temp = temp->next[i];

            //printf("Debug : %d - %d\n", temp1->value, temp1->next[i]->value);

            if ((temp->value->ref_ID == ref) || ((temp->next[i] != NULL) && (temp->next[i]->value->ref_ID == ref))) return 1;
        }
    }
    return 0;
}
