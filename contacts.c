
#include <ctype.h>
#include "contacts.h"


int SpecialChar(char * word){
    while (*word) {
        if (!isalpha(*word)) return 1;
        word++;
    }
    return 0;
}

t_contact * createContact(){
    /* Crée un contact avec son nom, son prénom
    et un ID de la forme "nom_prenom" */

    t_contact * new_contact = malloc(sizeof(t_contact));
    int i=0, j=0;

    do {
        printf("\nEntrer le nom du contact :");
        scanf(" %s", new_contact->name);
    } while (SpecialChar(new_contact->name));

    do {
        printf("\nEntrer le prenom du contact :");
        scanf(" %s", new_contact->firstname);
    } while (SpecialChar(new_contact->firstname));

    while (new_contact->name[i] != '\0') {
        if (65 <= new_contact->name[i] && new_contact->name[i] <= 90)
            new_contact->ref_ID[i] = (char) (new_contact->name[i] + 32);
        else new_contact->ref_ID[i] = new_contact->name[i];
        i++;
    }
    new_contact->ref_ID[i] = '_'; i++;

    while (new_contact->firstname[j] != '\0'){
        if (65 <= new_contact->firstname[j] && new_contact->firstname[j] <= 90)
            new_contact->ref_ID[i] = (char) (new_contact->firstname[j] + 32);
        else new_contact->ref_ID[i] = new_contact->firstname[j];
        i++;
        j++;
    }
    new_contact->ref_ID[i] = '\0';

    new_contact->meetings = NULL;
    //printf("%s", new_contact->ref_ID);
    return new_contact;
}
