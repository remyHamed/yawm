#include <stdlib.h>
#include <stdio.h>
#include "domain/menu/menu.h"
#include "domain/task/task.h"

int main (int argc, char ** argv) {
    
    char status = '1';
    char c = '1';
    task * t = NULL;
    task** t_array = NULL;

    t_array = mapper_from_save_file("../save/backup.txt");

    print_task_array(t_array);

    /*while (status != '3') {
        display_menu();
        c = getchar();
        while (getchar() != '\n');
        switch (c)
        {
        case '1':
            clear_screen();
            t = create_task();
            save_task("../save/backup.txt", t);
            free(t);
            break;
        case '2':
            read_task_from_save("../save/backup.txt");
            break;
        default:
            clear_screen();
            printf("Invalid input! Please choose a valid option.\n");
            break;
        }
        status = c;
    }*/
    
    free_task_array(t_array);
    
    return 0;
}