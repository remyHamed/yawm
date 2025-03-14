#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include<string.h>
#ifndef TASK_H
#define TASK_H
struct task * build_task(char title[255], char summary[500]);
void printTask(task * t);
#endif
