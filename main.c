#include <stdlib.h>
#include <stdio.h>
#include "domain/menu/menu.h"

int main (int argc, char ** argv) {
    
    char status = '1';
    char c = '1';

    while (status != '3')
    {
        display_menu();
        printf("Avant initialisation valeur numerique ascii : %d\n", c);
        printf("Avant initialisation valeur alphabetique ascii: %c\n", c);

        c = getchar();
        getchar();

        printf("c = %d\n", c);
        printf("c = %c\n", c);

        
        status = c;
        printf("status = %d\n", status);
        printf("status = %c\n", status);

    }
    
    return 0;
}