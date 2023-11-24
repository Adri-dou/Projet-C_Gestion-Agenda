
#include <stdio.h>
#include "ui.h"


void displayMainMenu(){
    printf("\n\t=============== ACTIONS DISPONIBLES ==============\n"
          "        1 : Rechercher un contact\n"
          "            1) Afficher les rendez-vous du contact\n"
          "            2) Ajouter un rendez-vous\n"
          "            3) Supprimer un rendez-vous\n"
          "            4) Retour au menu principal\n"
          "        2 : Creer un nouveau contact\n"
          "        3 : Quitter l'application\n");
}

void displaySubMenu() {
    printf("\n            1) Afficher les rendez-vous du contact\n"
           "            2) Ajouter un rendez-vous\n"
           "            3) Supprimer un rendez-vous\n"
           "            4) Retour au menu principal\n");
}

void getUserInput(char * input){
    printf("\n >> ");
    scanf(" %s", input);
}
