
#include "loading.h"


void loadRandomPeople(t_d_list * my_list){
    // Met tous les noms et prenoms ensemble dans une liste à niveaux
    char ** names, ** firstnames;
    names = give1000RdmNames("../noms.txt");
    firstnames = give1000RdmNames("../prenoms.csv");



    // On va tester ici les temps d'insertion par niveau, et linéairement
    FILE *log_file = fopen("log.txt","w");
    char format[] = "%d\t%s\t%s\n" ;
    int level;
    char *time_lvl0;
    char *time_all_levels;

    startTimer();
    for (int i=0; i < 1000; ++i) insertCell(my_list, createCell(createContact(names[i], firstnames[i]), 4));
    stopTimer();
    time_all_levels = getTimeAsString();

    t_d_list new_list_for_tests = createEmptyList(4);

    startTimer();
    for (int i=0; i < 1000; ++i) linearInsertion(&new_list_for_tests, createCell(createContact(names[i], firstnames[i]), 4));
    stopTimer();
    time_lvl0 = getTimeAsString();

    printf("\n\nTemps mis pour creer une liste de 1000 contacts :\n"
           "Lineairement : %s\n"
           "Par niveaux : %s\n\n",
           time_lvl0, time_all_levels);
}

char ** give1000RdmNames(char * namefile) {
    // Donne une liste de 1000 noms ou prénoms en fonction du nom de fichier donné
    FILE * my_file = fopen(namefile, "r");

    srand(time(NULL));

    char ** names = (char**)malloc(sizeof(char*) * 1000);
    for (int i = 0; i < 1000; i++) {
        names[i] = (char*)malloc(sizeof(char) * TAILLE);
    }

    int nb_lines = 0, random_line;
    char name[TAILLE];
    while (fgets(name, sizeof(name), my_file) != NULL) nb_lines++;

    for (int i=0; i<1000; i++){
        rewind(my_file);
        random_line = (rand() * rand()) % nb_lines;
        //printf("%d",random_line);

        for (int j=0; j<random_line; j++) {
            fgets(name, sizeof(name), my_file);
            name[strlen(name)-1] = '\0';
        }

        strcpy(names[i], name);

    }

    fclose(my_file);

    return names;
}

//t_d_list loadSchedule();

void saveSchedule(t_d_list schedule) {
    FILE *save = fopen("../schedule-save.csv", "w");

    t_d_cell * temp = schedule.heads[0];
    t_meeting * mt;
    while (temp != NULL) {
        fprintf(save, "%s;%s;", temp->value->name, temp->value->firstname);
        mt = temp->value->meetings;
        while (mt != NULL) {
            fprintf(save, "%d;%d;%d;%d;%d;%d;%d;%d;%s;",
                    mt->id, mt->day, mt->month, mt->year, mt->hour, mt->minute, mt->dhour, mt->dminute, mt->m_description);
            mt = mt->next_meeting;
        }
        fprintf(save, "\n");
        temp = temp->next[0];
    }
    fclose(save);
}

t_d_list loadSchedule(){
    FILE *save = fopen("../schedule-save.csv", "r");

    t_d_list new_list = createEmptyList(4);

    char line[1000], *name, *firstname;


    while (fgets(line, sizeof(line), save) != NULL) {

        name = strtok(line, ";");
        firstname = strtok(NULL, ";");

        t_contact * new_contact = createContact(name, firstname);

        // On crée un nouveau rdv avec tous les elements enregistrés
        char *tok = strtok(NULL, ";");
        while (tok != NULL && tok[0] != '\n') {

            t_meeting * new_meeting = createMeeting();

            new_meeting->id = atoi(tok);
            tok = strtok(NULL, ";");

            new_meeting->day = atoi(tok);
            tok = strtok(NULL, ";");

            new_meeting->month = atoi(tok);
            tok = strtok(NULL, ";");

            new_meeting->year = atoi(tok);
            tok = strtok(NULL, ";");

            new_meeting->hour = atoi(tok);
            tok = strtok(NULL, ";");

            new_meeting->minute = atoi(tok);
            tok = strtok(NULL, ";");

            new_meeting->dhour = atoi(tok);
            tok = strtok(NULL, ";");

            new_meeting->dminute = atoi(tok);
            tok = strtok(NULL, ";");

            strcpy(new_meeting->m_description, tok);
            tok = strtok(NULL, ";");

            new_meeting->next_meeting = new_contact->meetings;
            new_contact->meetings = new_meeting;
        }

        insertCell(&new_list, createCell(new_contact, 4));
    }
    fclose(save);
    return new_list;
}
