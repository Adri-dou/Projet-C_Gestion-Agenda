
#ifndef PROJET_C_GESTION_AGENDA_CONTACTS_H
#define PROJET_C_GESTION_AGENDA_CONTACTS_H

#include <stdio.h>
#include <string.h>

#define TAILLE 50

// STRUCTURES
typedef struct t_meeting{
    /*Définit la structure des rendez-vous*/
    int day,month,year,hour,minute;
    char *m_description; // penser à faire l'allocation dynamique dans la fonction qui permettra d'ajouter la descriptio du meeting  " malloc(sizeof(char) * taille_texte) ";
    struct t_meeting* next_meeting;
}t_meeting;

typedef struct t_contact{
    /*Définit la structure d'un contact avec les rendez-vous qui lui sont liés'*/
    char *ref_ID, *name, *firstname;
    t_meeting *meetings;
}t_contact;


// FUNCTIONS
char * scanString();

t_contact * createContact();


#endif //PROJET_C_GESTION_AGENDA_CONTACTS_H
