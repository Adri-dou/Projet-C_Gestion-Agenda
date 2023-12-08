
#include "contacts.h"


t_contact * addNewContact(){

    char name[TAILLE], firstname[TAILLE];

    printf("\nEntrer le nom du contact :");
    fflush(stdin);
    fgets(name, sizeof(name), stdin);

    printf("\nEntrer le prenom du contact :");
    fflush(stdin);
    fgets(firstname, sizeof(firstname), stdin);

    name[strlen(name)-1] = '\0';
    firstname[strlen(firstname)-1] = '\0';
    return createContact(name, firstname);
}

t_contact * createContact(char *name, char *firstname){
    /* Crée un contact avec son nom, son prénom
    et un ID de la forme "nom_prenom" */

    t_contact * new_contact = malloc(sizeof(t_contact));
    int i=0, j=0;


    strcpy(new_contact->name, name);
    strcpy(new_contact->firstname, firstname);

    while (new_contact->name[j] != '\0') {
        if (65 <= new_contact->name[j] && new_contact->name[j] <= 90) {
            new_contact->ref_ID[i] = (char) (new_contact->name[j] + 32);
            i++;
        } else if (97 <= new_contact->name[j] && new_contact->name[j] <= 122) {
            new_contact->ref_ID[i] = new_contact->name[j];
            i++;
        }
        j++;
    }
    new_contact->ref_ID[i] = '_'; i++;
    j = 0;

    while (new_contact->firstname[j] != '\0'){
        if (65 <= new_contact->firstname[j] && new_contact->firstname[j] <= 90) {
            new_contact->ref_ID[i] = (char) (new_contact->firstname[j] + 32);
            i++;
        }
        else if (97 <= new_contact->firstname[j] && new_contact->firstname[j] <= 122) {
            new_contact->ref_ID[i] = new_contact->firstname[j];
            i++;
        }
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

    return new_meeting;
}


void addMeeting(t_contact * ctc){
     t_meeting * new_meeting = createMeeting();

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
    fgets(new_meeting->m_description, sizeof(char) * TAILLE*10, stdin);
    new_meeting->m_description[strlen(new_meeting->m_description)-1] = '\0';

    // On ajoute en tête de liste le nouveau rdv
    if (ctc->meetings == NULL) new_meeting->id = 1;
    else new_meeting->id = ctc->meetings->id + 1;
    new_meeting->next_meeting = ctc->meetings;
    ctc->meetings = new_meeting;
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
        else if (tmp->next_meeting == NULL) printf("\nLe rendez-vous n'existe pas");

        else {
            while (tmp->next_meeting != NULL && tmp->next_meeting->id != id) tmp = tmp->next_meeting;

            if (tmp->next_meeting->id == id) {
                tmp2 = tmp->next_meeting;
                tmp->next_meeting = tmp2->next_meeting;
                free(tmp2);
            } else printf("\nLe rendez-vous n'existe pas");
        }
    }
}
