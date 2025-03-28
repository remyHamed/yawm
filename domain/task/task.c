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

task ** mapper_from_save_file(const char *filename) {
   
    if (!filename) return NULL;

    FILE * file = fopen(filename, "r");
    if (!file) {
        perror("Erreur lors de l'ouverture du fichier");
        return NULL;
    }

    task * head = NULL;
    task * tail = NULL;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;

    while ((read = getline(&line, &len, file)) != -1) {
        if (line[read-1] == '\n') line[read-1] = '\0';
        
        task* new_task = parse_line_to_task(line);
        if (!new_task) continue;

        if (!head) {
            head = new_task;
            tail = new_task;
        } else {
            tail->next = new_task;
            tail = new_task;
        }
    }

    free(line);
    fclose(file);
    
    int count = 0;
    task * current = head;
    while (current) {
        count++;
        current = current->next;
    }

    task ** result = malloc((count+1) * sizeof(task*));
    if (!result) {
        while (head) {
            task* tmp = head;
            head = head->next;
            free(tmp);
        }
        return NULL;
    }

    current = head;
    for (int i = 0; i < count; i++) {
        result[i] = current;
        current = current->next;
    }
    result[count] = NULL;

    return result;
}

void free_task_array(task** tasks) {
    if (!tasks) return;
    
    for (int i = 0; tasks[i] != NULL; i++) {
        free(tasks[i]);
    }
    free(tasks);
}

task * parse_line_to_task(const char* line) {
    if (!line) return NULL;

    char* tokens[4];
    char* copy = strdup(line);
    if (!copy) return NULL;

    char* token = strtok(copy, ",");
    int i = 0;
    while (token && i < 4) {
        while (*token == ' ') token++;
        int len = strlen(token);
        while (len > 0 && token[len-1] == ' ') token[--len] = '\0';
        
        tokens[i++] = token;
        token = strtok(NULL, ",");
    }

    if (i != 4) {
        free(copy);
        return NULL;
    }

    task* new_task = malloc(sizeof(task));
    if (!new_task) {
        free(copy);
        return NULL;
    }

    strncpy(new_task->title, tokens[0], sizeof(new_task->title)-1);
    new_task->create_date = atol(tokens[1]);
    new_task->task_date = atol(tokens[2]);
    strncpy(new_task->summary, tokens[3], sizeof(new_task->summary)-1);
    new_task->next = NULL;

    free(copy);
    return new_task;
}

void print_task_array(task** tasks) {

    if (!tasks) return;

    int size = sizeof(tasks) / sizeof(tasks[0]);

    printf("size : %d\n", size);

    for (size_t i = 0; i < size; i++) {
        print_task(tasks[i]);
    }
    
}