
#include <stdio.h>
#include "level_lists.h"


int main() {
    printf("On adore ce projet HAHA\n");

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

    return 0;
}
