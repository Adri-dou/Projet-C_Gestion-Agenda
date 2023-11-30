
#ifndef PROJET_C_GESTION_AGENDA_CONTACTS_H
#define PROJET_C_GESTION_AGENDA_CONTACTS_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define TAILLE 50


// STRUCTURES
typedef struct s_meeting{
    /*Définit la structure des rendez-vous*/
    int id;
    int day, month, year, hour, minute, dhour, dminute;
    char m_description[500]; // penser à faire l'allocation dynamique dans la fonction qui permettra d'ajouter la descriptio du meeting  " malloc(sizeof(char) * taille_texte) ";
    struct s_meeting* next_meeting;
}t_meeting;

typedef struct s_contact{
    /*Définit la structure d'un contact avec les rendez-vous qui lui sont liés'*/
    char ref_ID[TAILLE*2+2], name[TAILLE], firstname[TAILLE];
    t_meeting *meetings;
}t_contact;


// FUNCTIONS

t_contact * createContact();

t_meeting * createMeeting();

void addMeeting(t_contact *);

void removeMeeting(t_contact *);


#endif //PROJET_C_GESTION_AGENDA_CONTACTS_H
