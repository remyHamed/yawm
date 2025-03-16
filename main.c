#include <stdlib.h>
#include <stdio.h>
#include "domain/menu/menu.h"
#include "domain/task/task.h"

int main (int argc, char ** argv) {
    
    char status = '1';
    char c = '1';
    task * t = NULL;


    while (status != '3')
    {
        display_menu();
        c = getchar();
        while (getchar() != '\n');
        switch (c)
        {
        case '1':
            clear_screen();
            t = create_task();
            save_task(t);
            free(t);
            break;
        case '2':
            /* code */
            break;
        default:
            clear_screen();
            printf("Invalid input! Please choose a valid option.\n");
            break;
        }
        status = c;
    }
    
    return 0;
}