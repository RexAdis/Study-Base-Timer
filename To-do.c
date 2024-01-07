#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

typedef struct {
  char *task;
  int completed; 
} Task;

Task *tasks = NULL;
int length = 0;

void addTask(const char *task) {
  tasks = (Task *)realloc(tasks, (length + 1) * sizeof(Task)); 
  tasks[length].task = (char *)malloc(strlen(task) + 1); 
  tasks[length].completed = 0; 

  strcpy(tasks[length].task, task);

  length++;
  printf("Dodano zadanie do wykonania\n\n");
}

void listTasks() {
  const char* status;

  const char* ComStatus = "Wykonane";
  const char* NahStatus = "Nie wykonane";

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
  if (index <= length && index > 0 ) {
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

void editTask(int index, const char* task) {
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

int main() {
  int choice;
  int indexInput;
  int running = 1;

  char taskInput[100];

  
  
  

  while (running) {  
    printf("\nOpcje\n\n");
    printf("1. Dodaj nazwę zadania\n");
    printf("2. Wyświetl zadania\n");
    printf("3. Odhacz wykonane zadanie\n");
    printf("4. Edytuj zadanie\n");
    printf("5. Usuń zadanie\n");
    printf("6. Exit\n\n");
    printf("Wprowadź wybór: 1, 2, 3, 4, 5, 6: ");
    scanf("%d", &choice);
    printf("\n\n");

    switch(choice) {
      case 1:
        printf("Wpisz zadanie do wykonania: ");
        getchar();
        fgets(taskInput, sizeof(taskInput), stdin);
        taskInput[strcspn(taskInput, "\n")] = '\0'; 

        addTask(taskInput);
        break;

      case 2:
        listTasks();
        break;

      case 3:
        printf("Które zadanie chcesz odhaczyć? \n");
        listTasks();
        scanf("%d", &indexInput);
        markCompleted(indexInput);
        break;

      case 4:
        printf("Wpisz które zadania chcesz edytować: \n");
        listTasks();
        scanf("%d", &indexInput);
        printf("Wpisz jakie zmiany chcesz dokonać: ");

        getchar();
        fgets(taskInput, sizeof(taskInput), stdin);
        taskInput[strcspn(taskInput, "\n")] = '\0';

      
        editTask(indexInput, taskInput);
        break;

      case 5:
        printf("Wpisz które zadanie chcesz usnunąć: \n");
         listTasks();
        scanf("%d", &indexInput);
        deleteTask(indexInput);
        break;

      case 6:
        running = 0;
        break;

      default:
        printf("Niepoprawny wybór\n");
        break;
    }
  }

  for (int i = 0; i < length; i++) {
    free(tasks[i].task);
  }
  free(tasks);

  return 0;  
}
