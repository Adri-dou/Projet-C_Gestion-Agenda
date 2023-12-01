
#include "loading.h"


void loadRandomPeople(t_d_list * my_list){
    // Met tous les noms et prenoms ensemble dans une liste à niveaux
    char ** names, ** firstnames;
    names = give1000RdmNames("noms.txt");
    firstnames = give1000RdmNames("prenoms.csv");

    for (int i=0; i < 1000; ++i) insertCell(my_list, createCell(createContact(names[i], firstnames[i]), 4));
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

        for (int j=0; j<random_line; j++) fgets(name, sizeof(name), my_file);

        strcpy(names[i], name);

    }

    fclose(my_file);

    return names;
}

//t_d_list loadSchedule();

//void saveSchedule(t_d_list);
