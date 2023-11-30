
#ifndef PROJET_C_GESTION_AGENDA_UI_H
#define PROJET_C_GESTION_AGENDA_UI_H

#include "loading.h"


// MAIN MENU

void displayMainMenu();

void displaySubMenu(t_contact*);

void getUserInput(char *);


// LEVEL LIST

// Displays the list's levels
void displayLevel(t_d_list, int);

// Displays the list's cells
void displayList(t_d_list);

// (OPTION) Displays the levels aligned
void alignedDisplay(t_d_list);


// CONTACTS

void displayMeetings(t_contact *);


#endif //PROJET_C_GESTION_AGENDA_UI_H
