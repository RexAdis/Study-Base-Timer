#ifndef TaskMenager_H // sprawdza czy nie ma takiego pliku //
#define TaskMenager_H

typedef struct { // typdef powoduje że nie musimy pisać aliasow //
  char *task;
  int completed;
  time_t timeSpent;
} Task;

// Deklaracja zmiennej globalnej //
extern Task *tasks;
extern int length;
extern char ch;

// Deklaracja funkcji oraz ich typ //

void addTask(const char *task);
void listTasks();
void markCompleted(int index);
void deleteTask(int index);
void editTask(int index, const char *task);
void saveTasksToFile(const char *filename);
char loadTasksFromFile(const char *filename, char ch);

#endif // konczy dyrektywe //