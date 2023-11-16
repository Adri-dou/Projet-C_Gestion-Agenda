
#ifndef PROJET_C_GESTION_AGENDA_CONTACTS_H
#define PROJET_C_GESTION_AGENDA_CONTACTS_H

#include <stdio.h>
#include <string.h>

#define TAILLE 50

// STRUCTURES
typedef struct t_meeting{
    /*Défini la structure des rendez-vous*/
    int day,month,year,hour,minute;
    char *m_description; // penser à faire l'allocation dynamique dans la fonction qui permettra d'ajouter la descriptio du meeting  " malloc(sizeof(char) * taille_texte) ";
}t_meeting;

typedef struct t_contact{
    /*Défini la structure d'un contact avec les rendez-vous qui lui sont liés'*/
    char ref_ID[TAILLE], name[TAILLE], firstname[TAILLE];
    t_meeting meeting;
}t_contact;


// FUNCTIONS
char name_input();

#endif //PROJET_C_GESTION_AGENDA_CONTACTS_H
