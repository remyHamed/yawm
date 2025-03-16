#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include<string.h>
#include "./../inputer/inputer.h"
#ifndef TASK_H
#define TASK_H
typedef struct task {
    char title[255];
    time_t create_date;
    time_t task_date;
    char summary[500];
} task;

struct task * build_task(char title[255], char summary[500]);
task * create_task();
void save_task(task * t);
void print_task(task * t);
#endif