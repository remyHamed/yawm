#include "task.h"

struct task * build_task(char title[255], char summary[500]) {
    printf(" build task\n");
    printf("title = %s\n", title);
    printf("summary = %s\n", summary);
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

void save_task(task * t) {
    print_task(t);
}

void print_task(task * t) {
    printf(" build printTask\n");
    printf("task : \n");
    printf("title : %s\n", t->title);
    printf("create_date : %d\n", t->create_date);
    printf("task_date : %d\n", t->task_date);
    printf("title : %s\n", t->summary);
    printf(" build printTask finished\n");
}