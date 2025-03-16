#include "inputer.h"

char * get_sentence(char message[255]) {
    char * sentence = NULL;
    char status = 'n';
    char c = 'n';
    sentence = malloc(sizeof(char)*255);
   
    while (status != 'o')
    {
        printf("%s", message);
        fgets(sentence, sizeof(char) * 255, stdin);
        printf("Vous avez saisi : %s\n\n", sentence);
        printf("Valider la saisi o -> oui n -> non\n");
        c = getchar();
        getchar();
        status = c;
    }

    return sentence;
}