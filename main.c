
#include <stdio.h>

#include "ui.h"


int main() {

    // Ici il faudra charger le fichier de l'agenda
    char user_input[50];
    t_d_list schedule = createEmptyList(4);

    printf("\nHELLO, welcome to your favourite appointment schedule application !\n\n"
           "\t**************************************************\n"
           "\t****           GESTIONNAIRE D'AGENDA          ****\n"
           "\t**************************************************\n");
    displayMainMenu();
    // Menu
    while (1){

        getUserInput(user_input);

        if (user_input[0] == '\0')
            printf("\nNe soyez pas timide, utilisez le menu pour effectuer des actions !");
        else if (user_input[1] != '\0')
            printf("\nSaisie trop longue ! Un seul chiffre suffit ");


        // Rechercher un contact
        else if (user_input[0] == '1') {
            t_contact * ctc = seekContact(schedule);
            if (ctc == NULL) {
                printf("\nLe contact n'existe pas.");
                displayMainMenu();
            }
            else {

                displaySubMenu(ctc);

                while (1) {
                    getUserInput(user_input);

                    if (user_input[0] == '1') displayMeetings(ctc);

                    else if (user_input[0] == '2') addMeeting(ctc);

                    else if (user_input[0] == '3') removeMeeting(ctc);

                    else if (user_input[0] == '4') {
                        displayMainMenu(); break;
                    } else {
                        printf("\nEntree invalide !"); displaySubMenu(ctc);
                    }
                }
            }
        }

        else if (user_input[0] == '!') displayList(schedule); // Afficher un contact et ses rdv

        else if (user_input[0] == '2') {
            t_contact * newcontact = createContact();
            printf("%s\n", newcontact->name);
            printf("test:%s ", newcontact->ref_ID);
            insertCell(&schedule, createCell(newcontact, 4)); // Nouveau contact
        }


        else if (user_input[0] == '3') {
            printf("\nAu revoir et a bientot !\n\n");
            return 0;
        }

        else {
            printf("\nEntree invalide !"); displayMainMenu();
        }

    }
    // Sauvegarder les contacts
}
