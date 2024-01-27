#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TaskMenager.h"
#include <time.h>

Task *tasks = NULL;
int length = 0;
time_t timeSpent;

void addTask(const char *task) {
    tasks = (Task *)realloc(tasks, (length + 1) * sizeof(Task));
    tasks[length].task = (char *)malloc(strlen(task) + 1);
    tasks[length].completed = 0;

    strcpy(tasks[length].task, task);

    length++;
    printf("Dodano zadanie do wykonania\n\n");
}

void listTasks() {
    const char *status;
    const char *ComStatus = "Wykonane";
    const char *NahStatus = "Nie wykonane";

    for (int i = 0; i < length; i++) {
        if (tasks[i].completed == 1) {
            status = ComStatus;
        } else {
            status = NahStatus;
        }
        printf("%d. %s [%s]\n", i + 1, tasks[i].task, status);
    }
    printf("\n\n");
}

void markCompleted(int index) {
    if (index <= length && index > 0) {
        tasks[index - 1].completed = 1;
        printf("Zadanie ukończone\n");
    } else {
        printf("Nieprawidłowy indeks zadania\n");
    }
}

void deleteTask(int index) {
    if (index <= length && index > 0) {
        index = index - 1;

        free(tasks[index].task);

        for (int i = index; i < length - 1; i++) {
            tasks[i] = tasks[i + 1];
        }

        length--;

        tasks = (Task *)realloc(tasks, (length * sizeof(Task)));
    } else {
        printf("Nieprawidłowy indeks zadania\n");
    }
}
void editTask(int index, const char *task) {
    if (index <= length && index > 0) {
        index = index - 1;

        char *editedTask = (char *)realloc(tasks[index].task, strlen(task) + 1);

        if (editedTask != NULL) {
            tasks[index].task = editedTask;
            strcpy(tasks[index].task, task);

            printf("Zmiana zadania powiodła się\n");
        } else {
            printf("Nie udało się zmodyfikować zadania\n");
        }
    } else {
        printf("Nieprawidłowy indeks zadania\n");
    }
}

void saveTasksToFile(const char *filename) {
    FILE *plik = fopen(filename, "w+");
    if (plik == NULL) {
        printf("Błąd podczas zapisywanie zapisu.\n");
        return;
    }

    for (int i = 0; i < length; i++) {
        fprintf(plik, "%s [%s]\n", tasks[i].task, tasks[i].completed ? "Wykonane" : "Nie wykonane");
    }

    fclose(plik);
    printf("Zapisano pliko o nazwie %s.\n", filename);
}

void startTaskTimer(int index) {
  if (index <= length && index > 0 && tasks[index - 1].completed == 0) {
      time_t currentTime;
      time(&currentTime);
      tasks[index - 1].timeSpent = currentTime;
      printf("Rozpoczęto śledzenie czasu dla zadania.\n");
  }
}

void stopTaskTimer(int index) {
  if (index <= length && index > 0 && tasks[index - 1].completed == 0) {
      time_t currentTime;
      time(&currentTime);
      tasks[index - 1].timeSpent += difftime(currentTime, tasks[index - 1].timeSpent); //Oblicza roznice czasu// 
      printf("Zakończono śledzenie czasu dla zadania.\n");
  } else {
      printf("Nieprawidłowy indeks zadania lub zadanie jest już zakończone.\n");
  }
}


void displayTimeSpent(int index) {
    if (index <= length && index > 0) {
        long secondsSpent = tasks[index - 1].timeSpent;

        long minutesSpent = secondsSpent / 60;
        long hoursSpent = minutesSpent / 60;

        printf("Czas poświęcony na zadaniu: %ld godzin, %ld minut, %ld sekund\n",
               hoursSpent, minutesSpent % 60, secondsSpent % 60);
    } else {
        printf("Nieprawidłowy indeks zadania.\n");
    }
}
