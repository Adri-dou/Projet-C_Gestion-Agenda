
#ifndef PROJET_C_GESTION_AGENDA_CONTACTS_H
#define PROJET_C_GESTION_AGENDA_CONTACTS_H

#include <stdio.h>
#include <string.h>

#define TAILLE 50

// STRUCTURES
typedef struct s_meeting{
    /*Définit la structure des rendez-vous*/
    int day,month,year,hour,minute;
    char *m_description; // penser à faire l'allocation dynamique dans la fonction qui permettra d'ajouter la descriptio du meeting  " malloc(sizeof(char) * taille_texte) ";
    struct s_meeting* next_meeting;
}t_meeting;

typedef struct s_contact{
    /*Définit la structure d'un contact avec les rendez-vous qui lui sont liés'*/
    char ref_ID[TAILLE*2+2], name[TAILLE], firstname[TAILLE];
    t_meeting *meetings;
}t_contact;


// FUNCTIONS

char * scanString();

int SpecialChar(char*);

t_contact * createContact();


#endif //PROJET_C_GESTION_AGENDA_CONTACTS_H
