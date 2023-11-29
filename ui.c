
#include <stdio.h>
#include "ui.h"


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

void displaySubMenu() {
    printf("\n\t1) Afficher les rendez-vous du contact\n"
           "\t2) Ajouter un rendez-vous\n"
           "\t3) Supprimer un rendez-vous\n"
           "\t4) Retour au menu principal\n");
}

void getUserInput(char * input){
    printf("\n >> ");
    scanf(" %s", input);
}
