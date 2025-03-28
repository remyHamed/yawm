#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include<string.h>
#include <sys/types.h>
#include "./../inputer/inputer.h"
#ifndef TASK_H
#define TASK_H
typedef struct task {
    char title[255];
    time_t create_date;
    time_t task_date;
    char summary[500];
    struct task* next;
    
} task;

struct task * build_task(char title[255], char summary[500]);
task * create_task();
void save_task(const char *filename, task* t);
void print_task(task * t);
void read_task_from_save(const char *filename);
task** mapper_from_save_file(const char *filename);
void free_task_array(task** tasks);
task* parse_line_to_task(const char* line);
void print_task_array(task** tasks);
#endif