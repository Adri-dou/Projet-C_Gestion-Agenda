
#include "search.h"


t_contact * levelSearch(t_d_list my_list, char * name) {
    // First we lower the name
    int k = 0;
    while (name[k] != '\0') {
        if (65 <= name[k] && name[k] <= 90)
            name[k] = (char) (name[k] + 32);
        k++;
    }
    t_d_cell *temp = my_list.heads[my_list.max_level - 1];

    for (int i = my_list.max_level - 1; i >= 0; i--) {

        if (temp != NULL) {

            if (strcmp(temp->value->ref_ID, name) > 0) temp = my_list.heads[i];

            // We update 'temp' until the value is between temp and temp->next
            while ((temp->next[i] != NULL) && (strcmp(name, temp->next[i]->value->ref_ID) > 0)) temp = temp->next[i];


            if (strstr(temp->value->ref_ID, name) != NULL) return temp->value;

            else if ((temp->next[i] != NULL) && (strstr(temp->next[i]->value->ref_ID, name)))
                return temp->next[i]->value;
        }
    }
    return NULL;
}

t_contact * seekContact(t_d_list schedule){
    char name[TAILLE];
    int i=0;
    t_contact * ctc = NULL;

    name[0] = '\0';

    printf("\nInserez '>' pour valider le contact"
           "\nOu bien '<' pour retourner au menu");

    while (1){
        // Take the input
        printf("\n>>  %s", name); scanf(" %c", &name[i]);
        printf("\n");

        if (name[i] == '<') return NULL;
        else if (name[i] == '>') return ctc;


        i++;
        name[i] = '\0';

        if (strlen(name) >= 3) {
            ctc = levelSearch(schedule, name);
            if (ctc == NULL) printf("\nAucun contact correspondant");
            else printf("\nRecherchez-vous %s %s ?", ctc->firstname, ctc->name);
        }
    }
}
