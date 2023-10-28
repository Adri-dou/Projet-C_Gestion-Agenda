
#include <stdio.h>
#include "level_lists.h"


int main() {
    printf("On adore ce projet HAHA\n");

    t_d_list my_list = createEmptyList(5);
    t_d_cell new_cell = createCell(12, 4);
    t_d_cell new_cell2 = createCell(7, 2);
    t_d_cell new_cell3 = createCell(4, 3);
    addCellHead(&my_list, &new_cell);
    addCellHead(&my_list, &new_cell2);
    addCellHead(&my_list, &new_cell3);
    alignedDisplay(my_list);

    return 0;
}
