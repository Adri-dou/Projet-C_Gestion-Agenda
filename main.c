
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "level_lists.h"
#include "search.h"
#include "timer.h"


int main() {

    // Ici il faudra charger le fichier de l'agenda
    char user_input[50];
    t_d_list schedule = createEmptyList(4);

    printf("HELLO, welcome to your favourite appointment schedule application !\n\n"
           "\t**************************************************\n"
           "\t****           GESTIONNAIRE D'AGENDA          ****\n"
           "\t**************************************************\n");
    // Menu
    while (1){

        printf("\n >> ");
        scanf("%s", user_input);
        if (user_input[0] == '\0')
            printf("\nNe soyez pas timide, utilisez le menu pour effectuer des actions !");
        else if (user_input[1] != '\0')
            printf("\nSaisie trop longue ! Un seul chiffre suffit ;)");

        else if (user_input[0] == '1') ; // Rechercher un contact

        else if (user_input[0] == '2') displayList(schedule); // Afficher un contact et ses rdv

        else if (user_input[0] == '3') {
            t_contact * newcontact = createContact();
            printf("%s\n", newcontact->name);
            for (int i=0; newcontact->ref_ID[i] != '\0'; i++) printf("test:%c ", newcontact->ref_ID[i]);
            insertCell(&schedule, createCell(newcontact, 4)); // Nouveau contact
        }

        else if (user_input[0] == '4') ; // Ajouter un rdv

        else if (user_input[0] == '5') ; // Suprimer rdv

        else if (user_input[0] == '6')
            printf("\n=============== ACTIONS DISPONIBLES ==============\n"
                   "        1 : Rechercher un contact\n"
                   "        2 : Afficher les rendez-vous d'un contact\n"
                   "        3 : Creer un nouveau contact\n"
                   "        4 : Ajouter un rendez-vous\n"
                   "        5 : Supprimer un rendez-vous\n"
                   "        6 : Afficher ce menu\n"
                   "        7 : Quitter l'application\n");

        else if (user_input[0] == '7') {
            printf("\nAu revoir et a bientot !");
            return 0;
        }

        else printf("\nEntree invalide, afficher le menu avec 6 ;)");
    }
    // Sauvegarder les contacts
}
