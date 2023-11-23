
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "level_lists.h"
#include "search.h"
#include "timer.h"


int main() {

    /*
    // Part I Tests
    t_d_list my_list = createEmptyList(5);

    addCellHead(&my_list, createCell(32, 5));
    insertCell(&my_list, createCell(59, 1));
    insertCell(&my_list, createCell(31, 2));
    insertCell(&my_list, createCell(18, 4));
    insertCell(&my_list, createCell(59, 5));
    insertCell(&my_list, createCell(101, 3));
    insertCell(&my_list, createCell(9, 2));
    insertCell(&my_list, createCell(25, 1));
    insertCell(&my_list, createCell(56, 3));

    alignedDisplay(my_list);
    */

    // Part 2 Tests
    // Create a writing file
    FILE *log_file = fopen("log.txt","w");
    char format[] = "%d\t%s\t%s\n" ;
    int level = 5, nb_searches = 1000;
    char *time_lvl0;
    char *time_all_levels;

    t_d_list my_list;
    while (level <= 30) {

        int nb_cells = (int) pow(2, level) -1;
        printf("%2d : ", level);
        my_list = createFullList(level);

        startTimer();
        for (int i=0; i<nb_searches; i++) classicalSearch(my_list, rand()%nb_cells+1);
        stopTimer();
        time_lvl0 = getTimeAsString();

        startTimer();
        for (int i=0; i<nb_searches; i++) levelSearch(my_list, rand()%nb_cells+1);
        stopTimer();
        time_all_levels = getTimeAsString();

        fprintf(log_file, format, level, time_lvl0, time_all_levels);
        level++;
    }

    fclose(log_file);






    return 0;
}
