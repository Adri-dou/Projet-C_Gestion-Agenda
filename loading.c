
#include "loading.h"


t_d_list  loadRandomPeople(){
    // Met tous les noms et prenoms ensemble dans une liste à niveaux
}

char ** give1000RdmNames(char * namefile){
    // Donne une liste de 1000 noms ou prénoms en fonction du nom de fichier donné
    FILE * my_file = fopen(namefile, "r");

    srand(time(NULL));

    int nb_lines = 0, random_line;
    char names[1000][TAILLE];

    while (fgets(names[0], sizeof(names[0]), my_file) != NULL) nb_lines++;

    for (int i=0; i<1000; i++){
        rewind(my_file);
        random_line = (rand() * rand()) % nb_lines;
        //printf("%d",random_line);

        for (int j=0; j<random_line; j++) fgets(names[i], sizeof(names[0]), my_file);

        printf("%s",names[i]);
    }
    return (char **) names;
}

//t_d_list loadSchedule();

//void saveSchedule(t_d_list);
