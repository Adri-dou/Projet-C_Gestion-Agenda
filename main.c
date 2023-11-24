
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "search.h"
#include "ui.h"


int main() {

    // Ici il faudra charger le fichier de l'agenda
    char user_input[50];
    t_d_list schedule = createEmptyList(4);

    printf("HELLO, welcome to your favourite appointment schedule application !\n\n"
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
                printf("\n\n    =======    %s %s    =======",ctc->firstname, ctc->name);
                displaySubMenu();

                while (1) {
                    getUserInput(user_input);

                    if (user_input[0] == '1') ; //Afficher les rdv

                    else if (user_input[0] == '2'); // Ajouter un rdv

                    else if (user_input[0] == '3'); // Suprimer rdv

                    else if (user_input[0] == '4') {
                        displayMainMenu(); break;
                    } else {
                        printf("\nEntree invalide !"); displaySubMenu();
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
            printf("\nAu revoir et a bientot !");
            return 0;
        }

        else {
            printf("\nEntree invalide !"); displayMainMenu();
        }

    }
    // Sauvegarder les contacts
}
