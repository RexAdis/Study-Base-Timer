#ifndef TASK_MANAGER_H
#define TASK_MANAGER_H

typedef struct {
    char *task;
    int completed;
} Task;

extern Task *tasks; 
extern int length;

void addTask(const char *task);
void listTasks();
void markCompleted(int index);
void deleteTask(int index);
void editTask(int index, const char *task);
void saveTasksToFile(const char *filename);

#endif