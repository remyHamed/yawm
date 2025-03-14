#include "task.h"

typedef struct task {
    char title[255];
    time_t create_date;
    time_t task_date;
    char summary[500];
} task;

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

task create_task() {
    // TODO
}

void printTask(task * t) {
    printf(" build printTask\n");
    printf("task : \n");
    printf("title : %s\n", t->title);
    printf("create_date : %d\n", t->create_date);
    printf("task_date : %d\n", t->task_date);
    printf("title : %s\n", t->summary);
    printf(" build printTask finished\n");
}