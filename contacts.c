
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


t_meeting * createMeeting(){

    t_meeting * new_meeting = malloc(sizeof(t_meeting));
    new_meeting->next_meeting = NULL;

    do {
        printf("\nVeuillez saisir la date : jj/mm/aaaa\n >> ");
        scanf("%d/%d/%d", &new_meeting->day, &new_meeting->month, &new_meeting->year);
    } while (1 > new_meeting->day || new_meeting->day > 31
             || 1 > new_meeting->month || new_meeting->month > 12);

    do {
        printf("\nSaisissez une heure : hh:mm\n >> ");
        scanf("%d:%d", &new_meeting->hour, &new_meeting->minute);
    } while (0 > new_meeting->hour || new_meeting->hour >= 24
             || 0 > new_meeting->minute || new_meeting->minute >= 60);

    do {
        printf("\nSaisissez la duree du rendez-vous : hh:mm\n >> ");
        scanf("%d:%d", &new_meeting->dhour, &new_meeting->dminute);
    } while (0 > new_meeting->dhour || new_meeting->dhour >= 24
             || 0 > new_meeting->dminute || new_meeting->dminute >= 60);

    printf("\nQuel est cet evenement ?\n >>");
    fflush(stdin);
    fgets(new_meeting->m_description, sizeof(new_meeting->m_description), stdin);

    return new_meeting;
}


void addMeeting(t_contact * ctc){
     t_meeting * new_meeting = createMeeting();

     if (ctc->meetings == NULL) {
         new_meeting->id = 1;
         ctc->meetings = new_meeting;
     }
     else {
         t_meeting * tmp = ctc->meetings;
         while (tmp->next_meeting != NULL) tmp = tmp->next_meeting;
         new_meeting->id = tmp->id+1;
         tmp->next_meeting = new_meeting;
     }
}

void removeMeeting(t_contact * ctc) {
    int id;
    printf("\nNumero de l'evenement a supprimer :\n >> ");
    scanf("%d", &id);

    if (ctc->meetings == NULL) printf("\nEvenement inexistant !");

    else {
        t_meeting *tmp = ctc->meetings, *tmp2;

        if (tmp->id == id) {
            ctc->meetings = tmp->next_meeting;
            free(tmp);
        }

        else {
            while (tmp->next_meeting != NULL && tmp->next_meeting->id != id) tmp = tmp->next_meeting;

            if (tmp->next_meeting->id == id) {
                tmp2 = tmp->next_meeting;
                tmp->next_meeting = tmp2->next_meeting;
                free(tmp2);
            }
        }
    }
}
