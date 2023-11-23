
#include <stdlib.h>
#include "contacts.h"


t_contact * createContact(){
    /* Crée un contact avec son nom, son prénom
    et un ID de la forme "nom_prenom" */

    t_contact * new_contact = malloc(sizeof(t_contact));
    char concatenated_name[TAILLE*2+1], name[TAILLE], firstname[TAILLE];
    int i=0, j=0;

    printf("\nEntrer le nom du contact :");
    scanf(" %s",name);

    printf("\nEntrer le prenom du contact :");
    scanf(" %s",firstname);

    while (name[i] != '\0') {
        concatenated_name[i] = name[i];
        i++;
    }
    concatenated_name[i] = '_'; i++;

    while (firstname[j] != '\0'){
        concatenated_name[i] = firstname[j];
        i++;
        j++;
    }
    concatenated_name[i] = '\0';


    new_contact->name = name;
    new_contact->firstname = firstname;
    new_contact->ref_ID = concatenated_name;

    new_contact->meetings = NULL;
    //printf("%s", new_contact->ref_ID);
    return new_contact;
}

