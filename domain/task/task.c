#include "task.h"
#include <time.h>

struct task * build_task(char title[255], char summary[500]) {
    printf(" build task\n");
    printf("title = |%s|\n", title);
    printf("summary = |%s|\n", summary);
    task * t = malloc(sizeof(task));
    strcpy(t->title, title);
    strcpy(t->summary, summary);
    printf(" build task finished\n");
    return t;
}

task * create_task() {
    char * title = NULL;
    char * summary = NULL;
    task * t = NULL;
    title = get_sentence("Taper le titre de la tache (pas plus de 255 char)\n");
    summary = get_sentence("Taper le resumer de la tache (pas plus de 255 char)\n");
    t = build_task(title, summary);
    free(title);
    free(summary);
    return t;
}


void save_task(const char *filename, task* t) {
    FILE *file = fopen(filename, "a");
    if (file == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        return;
    }

    fprintf(file, "%s, %ld, %ld, %s\n", t->title, t->create_date, t->task_date, t->summary);
    fclose(file);
}

void print_task(task * t) {
    printf(" build printTask\n");
    printf("TASK\n");
    printf("title : %s\n", t->title);
    printf("create_date : %d\n", t->create_date);
    printf("task_date : %d\n", t->task_date);
    printf("title : %s\n", t->summary);
    printf(" build printTask finished\n");
}

void read_task_from_save(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        return;
    }

    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    printf("Contenu du fichier '%s':\n", filename);
    printf("----------------------------------\n");

    while ((read = getline(&line, &len, file)) != -1) {
        printf("%s", line); 
    }

    free(line);
    fclose(file);
}