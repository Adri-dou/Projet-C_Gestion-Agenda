
#include <stdio.h>
#include "ui.h"


// MAIN MENU

void displayMainMenu(){
    printf("\n\t=============== ACTIONS DISPONIBLES ==============\n"
          "\t        1 : Rechercher un contact\n"
          "\t            1) Afficher les rendez-vous du contact\n"
          "\t            2) Ajouter un rendez-vous\n"
          "\t            3) Supprimer un rendez-vous\n"
          "\t            4) Retour au menu principal\n"
          "\t        2 : Creer un nouveau contact\n"
          "\t        3 : Quitter l'application\n");
}

void displaySubMenu(t_contact * ctc) {
    printf("\n\n    =======    %s %s    =======", ctc->firstname, ctc->name);
    printf("\n\t1) Afficher les rendez-vous du contact\n"
           "\t2) Ajouter un rendez-vous\n"
           "\t3) Supprimer un rendez-vous\n"
           "\t4) Retour au menu principal\n");
}

void getUserInput(char * input){
    printf("\n >> ");
    scanf(" %s", input);
}


// LEVEL LIST

void displayLevel(t_d_list my_list, int lvl_display){
    t_d_cell *temp;
    temp = my_list.heads[lvl_display];
    printf("[list head_%d @-]", lvl_display);
    while (temp != NULL){
        printf("-->[%s|@-]", temp->value->name);
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
                printf("-->[%s|@-]", temp2->value->name);
                temp2 = temp2->next[i];
            } else printf("-------------------");
            temp1 = temp1->next[0];
        }
        printf("-->NULL\n");
    }
}


// CONTACTS

void displayMeetings(t_contact * ctc) {
    t_meeting * tmp = ctc->meetings;
    printf("\nListe les evenements de %s %s : \n", ctc->firstname, ctc->name);
    if (tmp == NULL) printf("Aucun evenement");
    else {
        while (tmp != NULL) {
            printf("\nID - %d"
                   "\nDate :  %02d/%02d/%04d"
                   "\nHeure :  %02d h %02d"
                   "\nDuree :  %02d h %02d"
                   "\n  Description :\n%s\n",
                   tmp->id,
                   tmp->day, tmp->month, tmp->year,
                   tmp->hour, tmp->minute,
                   tmp->dhour, tmp->dminute,
                   tmp->m_description);
            tmp = tmp->next_meeting;
        }
    }
}
